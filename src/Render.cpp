#include "Render.h"
#include "SpecialIds.h"
#include "SimpleColors.h"

namespace trx
{
    Render::Render(Camera* camera_in, Scene* scene_in)
    {
        camera = camera_in;
        scene  = scene_in;
        
        idBuffer.SetSize(camera->Width(), camera->Height());
        pixelBuffer.SetSize(camera->Width(), camera->Height());
        image = new PngImage(camera->Height(), camera->Width(), pixelBuffer.data);
        
        idBuffer.Fill(SpecialId::background); // -1 -> background ID
        pixelBuffer.Fill(SimpleColor::gray);
        
        drawer = new PngDrawer(image);
    }
    
    void Render::RenderImage(void)
    {
        
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