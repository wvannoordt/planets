#ifndef TRX_SCENE_LIGHT_H
#define TRX_SCENE_LIGHT_H

namespace trx
{
    class SceneLight
    {
        public:
            SceneLight(void){}
            virtual double Illuminate(double* x, double* n)=0;
            virtual ~SceneLight(void){}
        private:
            int lightColor = 0x00ffffff;
    };
}

#endif