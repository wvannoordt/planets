#include "PointLight.h"

namespace trx
{
    PointLight::PointLight(void)
    {
        
    }
    
    PointLight::PointLight(Vec3 position_in)
    {
        position = position_in;
    }
    
    double PointLight::Illuminate(double* x, double* n)
    {
        return 1.0;
    }
    
    PointLight::~PointLight(void)
    {
        
    }
}