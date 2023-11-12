#include <Engine.h>
#include <time.h>
#include <Windows.h>
#include <SdlInput.h>
#include <SdlGraphics.h>
#include <SdlAudio.h>
#include <EKey.h>
#include <Entity.h>
#include "WorldService.h"

using namespace ProjetEngin;

#if _DEBUG
#include "consoleLogger.h"
#else
#include "fileLogger.h"
#endif


/// <summary>
/// Initiatilse the engine
/// </summary>
/// <param name="title">= where you enter the title of the game here</param>
/// <param name="w">= the Width of the active window</param>
/// <param name="h">= the Height of the active window</param>
/// <returns></returns>
bool Engine::Init(const char* title, int w, int h) 
{
#ifdef _DEBUG
	m_Logger = new ConsoleLogger();
#endif
	//This is release
#ifdef NDEBUG
	m_Logger = new FileLogger();
#endif

	m_World = new WorldService();

	m_Graphics = new SdlGraphics();

	if (!m_Graphics->Initialize(title, w, h))
	{
		m_Logger->LogError("Cannot create window");
	}

	m_Audio = new SdlAudio();
	m_Input = new SdlInput();

	m_IsInit = true;
	return true;
}

/// <summary>
/// Start the engine using the title, width and height as parameters
/// </summary>
/// <param name=""></param>
void Engine::Start(void) {


	if (!m_IsInit) 
	{
		if (!Init("Unknow title", 800, 600)) 
		{
			return;
		}
	}

	m_IsRunning = true;

	clock_t _end = clock();
	const int TARGET_FPS = 60;
	const int MS_PER_FRAME = 1000 / TARGET_FPS;

	while (m_IsRunning) 
	{
		const clock_t _start = clock();
		float _dt = (_start - _end) * 0.001f;

		ProcessInput();
		Update(_dt);
		Render();

		int _sleepTime = (_start + MS_PER_FRAME - clock());
		if (_sleepTime > 0) 
		{
			Sleep(_sleepTime);
		}

		_end = _start;
	}
	Shutdown();
}

/// <summary>
/// Exit the game
/// </summary>
void Engine::Exit()
{
	m_IsRunning = false;
}

/// <summary>
/// Process the player's input
/// </summary>
/// <param name=""></param>
void Engine::ProcessInput(void)
{
	m_Input->Update();
#if _DEBUG
	if (m_Input->IsKeyDown(EKey::EKEY_ESCAPE))
	{
		Exit();
	}
#endif
}

static float x = 0.0f;
static float y = 0.0f;
/// <summary>
/// Updates the frame of the engine
/// </summary>
/// <param name="dt"></param>
void Engine::Update(float dt)
{
	if (m_Input->IsKeyDown(EKey::EKEY_D)) {
		x += 100 * dt;
		//m_Logger->Log("D is pressed");
	}
	if (m_Input->IsKeyDown(EKey::EKEY_A)) {
		x -= 100 * dt;
		//m_Logger->Log("A is pressed");
	}
	if (m_Input->IsKeyDown(EKey::EKEY_W)) {
		y -= 100 * dt;
		//m_Logger->Log("W is pressed");
	}
	if (m_Input->IsKeyDown(EKey::EKEY_S)) {
		y += 100 * dt;
		//m_Logger->Log("S is pressed");
	}
	
	Sleep(dt);
}

/// <summary>
/// clears the last frame, renders the current frame
/// </summary>
/// <param name=""></param>
void Engine::Render(void)
{
	m_Graphics->Clear();

	//m_Graphics->DrawRect(x, y, 102, 102, Color::RED);
	m_Graphics->DrawLine(x, y, 100, 200, Color::AQUAMARINE);

	m_Graphics->Present();
}

/// <summary>
/// Closes all services 
/// </summary>
/// <param name=""></param>
void Engine::Shutdown(void)
{
	if (m_Input != nullptr)
	{
		delete m_Input;
	}

	if (m_Audio != nullptr)
	{
		delete m_Audio;
	}

	if (m_Graphics != nullptr)
	{
		m_Graphics->Shutdown();
		delete m_Graphics;
	}

	if (m_Logger != nullptr)
	{
		delete m_Logger;
	}

	if (m_World != nullptr)
	{
		m_World->Unload();
		delete m_World;
	}

}


