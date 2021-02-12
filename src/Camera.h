#ifndef TRX_CAMERA_H
#define TRX_CAMERA_H
#include "PngImage.h"
#include "PngDrawer.h"
namespace trx
{
    class Camera
    {
        public:
            Camera(int height_in, int width_in);
            ~Camera(void);
        private:
            int height, width;
            PngImage* image;
            PngDrawer* drawer;
    };
}

#endif