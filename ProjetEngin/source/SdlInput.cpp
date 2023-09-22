#include "SdlInput.h"
#include "SDL.h"

using namespace ProjetEngin;

void ProjetEngin::SdlInput::Update()
{
	SDL_Event _event;
	while (SDL_PollEvent(&_event)) 
	{
		switch (_event.type) 
		{
		case SDL_QUIT:
			m_IsRunning = false;
			break;
		}
	}
	m_keyStates = SDL_GetKeyboardState(nullptr);
}

bool ProjetEngin::SdlInput::IsKeyDown(int key)
{
	return m_keyStates[key];
}

bool ProjetEngin::SdlInput::IsButtonDown(int button)
{
	return false;
}

void ProjetEngin::SdlInput::GetMousePosition(int* x, int* y)
{
}
