#include <iostream>
#include <Engine.h>

using namespace ProjetEngin;

void Engine::Start()
{
	if (!m_IsInit)
	{
		if (!Init("DigDug3000", 800, 600))
		{
			return;
		}
	}
	m_IsRunning = true;

	while (m_IsRunning)
	{
		ProcessInput();
		Update();
		Render();
	}

	Shutdown();
}