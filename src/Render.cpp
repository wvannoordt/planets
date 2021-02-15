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
        camNormals.SetSize(camera->Width(), camera->Height(), 3);
        camDistance.SetSize(camera->Width(), camera->Height());

        image = new PngImage(camera->Height(), camera->Width(), pixelBuffer.data);
        
        idBuffer.Fill(SpecialId::background);
        pixelBuffer.Fill(SimpleColor::gray);
        
        drawer = new PngDrawer(image);
    }
    
    void Render::RenderImage(void)
    {
        camDistance.Fill(MAX_DISTANCE);
        ComputeCameraNormals(camNormals);
        CameraIdPass(idBuffer);
    }
    
    void Render::ComputeCameraNormals(ImageBuffer<double>& norms)
    {
        double* lowLeft = &(camera->LowerLeft().v[0]);
        double* pos     = &(camera->Position().v[0]);
        double* xax     = &(camera->XAxis().v[0]);
        double* yax     = &(camera->YAxis().v[0]);
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
    
    void Render::CameraIdPass(ImageBuffer<int>& idBuf)
    {
        for (const auto obj:scene->objects)
        {
            ScreenBoundingBox objbbox = obj->ComputeBoundingBox(camera);
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