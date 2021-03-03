#ifndef TRX_SCENE_H
#define TRX_SCENE_H
#include "SceneObject.h"
#include "SceneLight.h"
#include <vector>
namespace trx
{
    class Scene
    {
        public:
            Scene(void);
            ~Scene(void);
            void Clear(void);
            SceneObject* AddObject(SceneObject* obj);
            SceneLight*  AddLightSource(SceneLight* light);
            void SetGamma(double gamma_in);
        private:
            std::vector<SceneObject*> objects;
            std::vector<SceneLight*>  lights;
            double gamma;
        friend class Render;
    };
}

#endif