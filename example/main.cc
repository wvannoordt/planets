#include "trx.h"

int main(void)
{
	trx::WriteLine("Init");
	trx::Scene scene;
	trx::Camera camera(400, 400);
	
	scene.AddObject(new trx::Sphere());
	
	trx::Render rdr(&camera, &scene);
	rdr.RenderImage();
	rdr.SaveImage("output/test.png");
	return 0;
}
