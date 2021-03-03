#include "Render.h"
#include "SpecialIds.h"
#include "SimpleColors.h"
#include "util.h"
namespace trx
{
    Render::Render(Camera* camera_in, Scene* scene_in)
    {
        camera = camera_in;
        scene  = scene_in;
        
        idBuffer.SetSize(camera->Width(), camera->Height());
        pixelBuffer.SetSize(camera->Width(), camera->Height());
        lightingBuffer.SetSize(camera->Width(), camera->Height());
        camNormals.SetSize(camera->Width(), camera->Height(), 3);
        reflectedNormals.SetSize(camera->Width(), camera->Height(), 3);
        camDistance.SetSize(camera->Width(), camera->Height());

        image = new PngImage(camera->Height(), camera->Width(), pixelBuffer.data);
        
        idBuffer.Fill(SpecialId::background);
        pixelBuffer.Fill(SimpleColor::black);
        lightingBuffer.Fill(0.0);
        
        drawer = new PngDrawer(image);
    }
    
    void Render::RenderImage(void)
    {
        camDistance.Fill(MAX_DISTANCE);
        ComputeCameraNormals(camNormals);
        CameraIdPass(camNormals, idBuffer, camDistance, reflectedNormals);
        ColorByID(idBuffer, pixelBuffer);
    }
    
    void Render::ComputeCameraNormals(ImageBuffer<double>& norms)
    {
        Vec3 ll = camera->LowerLeft();
        Vec3 xa = camera->XAxis();
        Vec3 ya = camera->YAxis();
        Vec3 pn = camera->GetPosition();
        double* lowLeft = &(ll.v[0]);
        double* pos     = &(pn.v[0]);
        double* xax     = &(xa.v[0]);
        double* yax     = &(ya.v[0]);
        double screenPosition[3] = {0.0};
        double pari, parj, normVal;
        for (int j = 0; j < norms.nj; j++)
        {
            for (int i = 0; i < norms.ni; i++)
            {
                pari = ((double)i)/(norms.ni-1);
                parj = ((double)j)/(norms.nj-1);
                double* normVec = norms.data + 3*j*norms.ni + 3*i;
                screenPosition[0] = lowLeft[0] + pari*xax[0] + parj*yax[0];
                screenPosition[1] = lowLeft[1] + pari*xax[1] + parj*yax[1];
                screenPosition[2] = lowLeft[2] + pari*xax[2] + parj*yax[2];
                normVec[0] = screenPosition[0]-pos[0];
                normVec[1] = screenPosition[1]-pos[1];
                normVec[2] = screenPosition[2]-pos[2];
                normVal = sqrt(normVec[0]*normVec[0] + normVec[1]*normVec[1] + normVec[2]*normVec[2]);
                normVec[0]/=normVal;
                normVec[1]/=normVal;
                normVec[2]/=normVal;
            }
        }
    }
    
    void Render::CameraIdPass(ImageBuffer<double>& normals, ImageBuffer<int>& idBuf, ImageBuffer<double>& dists, ImageBuffer<double>& reflectedNormal)
    {
        for (const auto obj:scene->objects)
        {
            obj->TraceRange(normals, idBuf, dists, reflectedNormals, camera);
        }
    }
    
    void Render::IllumintaionPass(ImageBuffer<double>& cameraNormals, ImageBuffer<double>& cameraDistance, ImageBuffer<double>& reflectedNormalVecs, ImageBuffer<int>& lighting)
    {
        // for (int j = 0; j < pixelBuffer.nj; j++)
        // {
        //     for (int i = 0; i < pixelBuffer.ni; i++)
        //     {
        //         int idLoc = id.data[i+j*pxBuf.ni];
        //         if (idLoc>=0)
        //         {
        // 
        //         }
        //     }    
        // }
    }
    
    void Render::ColorByID(ImageBuffer<int>& id, ImageBuffer<int>& pxBuf)
    {
        for (int j = 0; j < pxBuf.nj; j++)
        {
            for (int i = 0; i < pxBuf.ni; i++)
            {
                int idLoc = id.data[i+j*pxBuf.ni];
                if (idLoc>=0)
                {
                    pxBuf.data[i+j*pxBuf.ni] = color_blend(SimpleColor::black, scene->objects[idLoc]->baseColor, scene->gamma);
                }
            }
        }
    }
    
    void Render::SaveImage(std::string filename)
    {
        image->Write(filename);
    }
    
    Render::~Render(void)
    {
        delete image;
        delete drawer;
    }
}