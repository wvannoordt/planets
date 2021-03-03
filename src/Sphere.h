#ifndef TRX_SPHERE_H
#define TRX_SPHERE_H
#include "Vec3.h"
#include "SceneObject.h"
namespace trx
{
    class Sphere : public SceneObject
    {
        public:
            Sphere(void);
            ~Sphere(void);
            void TraceRay(double* x, double* n, int* idOut, double* distanceOut, double* reflectNormalOut) override;
        private:
            double radius;
    };
}

#endif