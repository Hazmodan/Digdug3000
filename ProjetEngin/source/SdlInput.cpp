#include "SdlInput.h"
#include "SDL.h"

using namespace ProjetEngin;

/// <summary>
/// Makes it possible to quit the application
/// </summary>
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

/// <summary>
/// Checks if a key is down
/// </summary>
/// <param name="key">= the key being pressed down</param>
/// <returns></returns>
bool ProjetEngin::SdlInput::IsKeyDown(EKey key)
{
	return m_keyStates[static_cast<int>(key)];
}

/// <summary>
/// Checks if a button is being pressed (controller)
/// </summary>
/// <param name="button">= the button being pressed down</param>
/// <returns></returns>
bool ProjetEngin::SdlInput::IsButtonDown(int button)
{
	return false;
}

/// <summary>
/// checks the mouse's position on the screen
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void ProjetEngin::SdlInput::GetMousePosition(int* x, int* y)
{
}
