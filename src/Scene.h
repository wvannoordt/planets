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
            SceneObject* AddObject(SceneObject* obj);
            SceneLight*  AddLightSource(SceneLight* light);
        private:
            std::vector<SceneObject*> objects;
            std::vector<SceneLight*>  lights;
        friend class Render;
    };
}

#endif