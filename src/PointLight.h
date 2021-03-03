#ifndef TRX_POINT_LIGHT_H
#define TRX_POINT_LIGHT_H

#include "Vec3.h"
#include "SceneLight.h"
namespace trx
{
    class PointLight : public SceneLight
    {
        public:
            PointLight(void);
            PointLight(Vec3 position_in);
            double Illuminate(double* x, double* n) override;
            ~PointLight(void);
        private:
            Vec3 position;
    };
}

#endif