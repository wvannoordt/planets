#include "Scene.h"

namespace trx
{
    Scene::Scene(void)
    {
        gamma = 0.0;
    }
    
    SceneObject* Scene::AddObject(SceneObject* obj)
    {
        objects.push_back(obj);
        obj->SetId(objects.size()-1);
        return obj;
    }
    
    void Scene::SetGamma(double gamma_in)
    {
        gamma = gamma_in;
    }
    
    SceneLight* Scene::AddLightSource(SceneLight* light)
    {
        lights.push_back(light);
        return light;
    }
    
    void Scene::Clear(void)
    {
        for (auto o:objects) delete o;
        for (auto l:lights)  delete l;
    }
    
    Scene::~Scene(void)
    {
        
    }
}