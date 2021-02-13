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
            void TraceRange(double* x, double* n, int* idOut, double* xIncidentOut, double* nReflectOut, ScreenBoundingBox& boundBox) override;
        private:
            double radius;
    };
}

#endif