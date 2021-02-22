#include "Sphere.h"
#include "vops.h"
namespace trx
{
    Sphere::Sphere(void)
    {
        radius = 1.0;
    }
    
    void Sphere::TraceRay(double* x, double* n, int* idOut, double* distanceOut)
    {
        Vec3 delta(x, center.v);
        double dot = v_dot(delta.v, n);
        double disc = dot*dot - (v_normsq(delta.v) - radius*radius);
        if (disc>=0.0)
        {
            double dist = dot-sqrt(disc);
            if (dist<*distanceOut)
            {
                *distanceOut = dist;
                *idOut = sceneId;
            }
        }
    }
    
    Sphere::~Sphere(void)
    {
        
    }
}