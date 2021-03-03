#include "trx.h"

int main(void)
{
	trx::WriteLine("Init");
	trx::Scene scene;
	trx::Camera camera(500, 500);
	camera.SetPosition(trx::Vec3(-3, 0, 0));
	
	scene.SetGamma(0.06);
	
	scene.AddLightSource(new trx::PointLight(trx::Vec3(0, 0, 12)));
	
	auto s1 = scene.AddObject(new trx::Sphere());
	auto s2 = scene.AddObject(new trx::Sphere());
	s1->SetBaseColor(trx::SimpleColor::red);
	s1->SetPosition(trx::Vec3(1, 0.0, 0));
	
	s2->SetBaseColor(trx::SimpleColor::blue);
	s2->SetPosition(trx::Vec3(3, 1.7, -1.1));
	trx::Render rdr(&camera, &scene);
	
	rdr.RenderImage();
	rdr.SaveImage("output/test.png");
	scene.Clear();
	return 0;
}
