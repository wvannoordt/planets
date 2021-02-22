#ifndef TRX_CAMERA_H
#define TRX_CAMERA_H
#include "PngImage.h"
#include "PngDrawer.h"
#include "Vec3.h"
namespace trx
{
    class Camera
    {
        public:
            Camera(int wid, int hei);
            void SetRadians(void);
            void SetDegrees(void);
            ~Camera(void);
            int Width(void);
            int Height(void);
            Vec3 GetPosition(void) { return position; };
            Vec3 SetPosition(const Vec3& p) { position = p; ComputeNormalAndAxes(); };
            Vec3 XAxis(void) { return xAxis; };
            Vec3 YAxis(void) { return yAxis; };
            Vec3 LowerLeft(void) { return lowerLeft; };
            
        private:
            void ComputeNormalAndAxes(void);
            int width, height;
            double angleMult;//radians or degrees?
            double xyAspect; //assume width of 1, how tall is y?
            Vec3 position;
            Vec3 normal;
            Vec3 yAxis;
            Vec3 xAxis;
            Vec3 lowerLeft;
            double pitch, roll, yaw;
            double zoom;
            friend class Render;
    };
}

#endif