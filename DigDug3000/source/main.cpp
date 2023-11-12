#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <Windows.h>
#include <vld.h>
#include "Engine.h"
#include "DemoScene.h"

/// <summary>
/// Starts the game by associating a scene (Demo scene), registers it and loads it
/// </summary>
void InitGameplay() 
{
	IScene* _DemoScene = new DemoScene();
	ProjetEngin::Engine::Get()->World().Register("SomethingUI", _DemoScene);
	ProjetEngin::Engine::Get()->World().Load("SomethingUI");
}


INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PSTR, _In_ INT)  
{
	ProjetEngin::Engine* RunningEngine = ProjetEngin::Engine::Get();
	if (RunningEngine->Init("DIGDUG3000", 800, 600))
	{
		InitGameplay();
		RunningEngine->Start();
	}

	return 0; 
}