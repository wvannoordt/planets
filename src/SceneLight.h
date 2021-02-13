#ifndef TRX_SCENE_LIGHT_H
#define TRX_SCENE_LIGHT_H

namespace trx
{
    class SceneLight
    {
        public:
            SceneLight(void){}
            virtual ~SceneLight(void){}
        private:
            int lightColor = 0x00ffffff;
    };
}

#endif