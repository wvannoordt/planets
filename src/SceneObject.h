#ifndef TRX_SCENE_OBJECT_H
#define TRX_SCENE_OBJECT_H
#include "ScreenBoundingBox.h"
#include "Camera.h"
namespace trx
{
    class SceneObject
    {
        public:
            SceneObject(void){};
            virtual ~SceneObject(void){};
            void SetId(int sceneId_in) { sceneId = sceneId_in; }
            virtual ScreenBoundingBox ComputeBoundingBox(Camera& camera)
            {
                //default to whole image :(
                ScreenBoundingBox bbox;
                bbox.imin = 0;
                bbox.jmin = 0;
                bbox.imax = camera.Width();
                bbox.jmax = camera.Height();
                return bbox;
            };
            virtual void TraceRange(double* x, double* n, int* idOut, double* xIncidentOut, double* nReflectOut, ScreenBoundingBox& boundBox)=0;
        protected:
            int sceneId = -1;
            Vec3 center;
    };
}

#endif