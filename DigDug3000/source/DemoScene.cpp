#include "DemoScene.h"
#include "Engine.h"

void DemoScene::Load()
{

	Entity* _ent = ProjetEngin::Engine::Get()->World().Create("TestEntity01");
	//_ent->AddComponent<Sprite>();

}
