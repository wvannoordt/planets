#include "Camera.h"
#include <cmath>
namespace trx
{
    Camera::Camera(int wid, int hei)
    {
        width = wid;
        height = hei;
        xyAspect = (double)hei/(double)wid;
        position = Vec3(0.0,0.0,0.0);
        pitch = 0.0;
        roll = 0.0;
        yaw = 0.0;
        angleMult = 1.0;
        zoom = 1.0;
        ComputeNormalAndAxes();
    }
    
    void Camera::SetRadians(void)
    {
        angleMult = 1.0;
    }
    
    int Camera::Width(void)
    {
        return width;
    }
    
    int Camera::Height(void)
    {
        return height;
    }
    
    void Camera::SetDegrees(void)
    {
        angleMult = 0.01745329251;
    }
    
    void Camera::ComputeNormalAndAxes(void)
    {
        normal.v[0] = cos(angleMult*yaw)*cos(angleMult*pitch);
        normal.v[1] = sin(angleMult*yaw)*cos(angleMult*pitch);
        normal.v[2] = sin(angleMult*pitch);
        Vec3 midpoint = position + normal*zoom;
        Vec3 z(0.0, 0.0, 1.0);
        xAxis = normal%z;
        xAxis.Normalize();
        yAxis = xAxis%normal;
        yAxis.Normalize();
        yAxis = yAxis*xyAspect;
        lowerLeft = midpoint - (xAxis*0.5) - (yAxis*0.5);
    }
    
    Camera::~Camera(void)
    {
        
    }
}