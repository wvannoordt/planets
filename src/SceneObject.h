#ifndef TRX_SCENE_OBJECT_H
#define TRX_SCENE_OBJECT_H
#include "ScreenBoundingBox.h"
#include "ImageBuffer.h"
#include "Camera.h"
namespace trx
{
    class SceneObject
    {
        public:
            SceneObject(void){};
            virtual ~SceneObject(void){};
            void SetId(int sceneId_in) { sceneId = sceneId_in; }
            virtual void TraceRay(double* x, double* n, int* idOut, double* distanceOut)=0;
            virtual ScreenBoundingBox ComputeBoundingBox(Camera* camera)
            {
                //default to whole image :(
                ScreenBoundingBox bbox;
                bbox.imin = 0;
                bbox.jmin = 0;
                bbox.imax = camera->Width();
                bbox.jmax = camera->Height();
                return bbox;
            }
            
            void TraceRange(ImageBuffer<double>& n, ImageBuffer<int>& idOut, ImageBuffer<double>& distanceOut, Camera* camera)
            {
                ScreenBoundingBox bbox = ComputeBoundingBox(camera);
                double* pos = &(camera->Position().v[0]);
                for (int j = bbox.jmin; j < bbox.jmax; j++)
                {
                    for (int i = bbox.imin; i < bbox.imax; i++)
                    {
                        TraceRay(pos, (n.data + j*3*n.ni + 3*i), (idOut.data + j*n.ni + i), (distanceOut.data + j*n.ni + i));
                    }
                }
            }
            
        protected:
            int sceneId = -1;
            Vec3 center;
    };
}

#endif