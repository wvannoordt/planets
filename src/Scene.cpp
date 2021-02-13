#include "Scene.h"

namespace trx
{
    Scene::Scene(void)
    {
        
    }
    
    SceneObject* Scene::AddObject(SceneObject* obj)
    {
        objects.push_back(obj);
        obj->SetId(objects.size());
        return obj;
    }
    
    SceneLight* Scene::AddLightSource(SceneLight* light)
    {
        lights.push_back(light);
        return light;
    }
    
    Scene::~Scene(void)
    {
        for (auto o:objects) delete o;
        for (auto l:lights)  delete l;
    }
}