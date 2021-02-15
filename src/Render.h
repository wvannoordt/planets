#ifndef TRX_RENDER_H
#define TRX_RENDER_H
#include "Scene.h"
#include "Camera.h"
#include "PngImage.h"
#include "PngDrawer.h"
#include "ImageBuffer.h"
namespace trx
{
    class Render
    {
        public:
            Render(Camera* camera_in, Scene* scene_in);
            void RenderImage(void);
            void SaveImage(std::string filename);
            ~Render(void);
        private:
            
            void ComputeCameraNormals(ImageBuffer<double>& norms);
            void CameraIdPass(ImageBuffer<double>& normals, ImageBuffer<int>& idBuf, ImageBuffer<double>& dists);
            
            Camera* camera;
            Scene* scene;
            PngImage* image;
            PngDrawer* drawer;
            
            ImageBuffer<int>    pixelBuffer;
            ImageBuffer<int>    idBuffer;
            ImageBuffer<double> camNormals;
            ImageBuffer<double> camDistance;
    };
}

#endif