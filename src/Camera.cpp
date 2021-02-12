#include "Camera.h"

namespace trx
{
    Camera::Camera(int height_in, int width_in)
    {
        height = height_in;
        width  = width_in;
        image = new PngImage(height, width);
        drawer = new PngDrawer(image);
    }
    
    Camera::~Camera(void)
    {
        delete drawer;
        delete image;
    }
}