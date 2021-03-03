#include "Sphere.h"
#include "vops.h"
namespace trx
{
    Sphere::Sphere(void)
    {
        radius = 1.0;
    }
    
    void Sphere::TraceRay(double* x, double* n, int* idOut, double* distanceOut, double* reflectNormalOut)
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
                double xinc[3];
                xinc[0] = x[0] + dist*n[0];
                xinc[1] = x[1] + dist*n[1];
                xinc[2] = x[2] + dist*n[2];
                reflectNormalOut[0] = xinc[0] - center.v[0];
                reflectNormalOut[1] = xinc[1] - center.v[1];
                reflectNormalOut[2] = xinc[2] - center.v[2];
                double norm = v_norm(reflectNormalOut);
                reflectNormalOut[0]/=norm;
                reflectNormalOut[1]/=norm;
                reflectNormalOut[2]/=norm;
            }
        }
    }
    
    Sphere::~Sphere(void)
    {
        
    }
}