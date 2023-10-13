#include "Engine.h"
#include "SDL.h"
#include <time.h>
#include "SdlInput.h"
#include "Windows.h">
#include "fileLogger.h"
#include "consoleLogger.h"

static SDL_Renderer* _renderer = NULL;
static SDL_Window* _window = NULL;
using namespace ProjetEngin;

bool Engine::Init(const char* name, int w, int h) {

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        SDL_Log(SDL_GetError());
        return false;
    }
    int _x = SDL_WINDOWPOS_CENTERED;
    int _y = SDL_WINDOWPOS_CENTERED;
    Uint32 _flag = SDL_WINDOW_TOOLTIP;
    _window = SDL_CreateWindow(name, _x, _y, w, h, _flag);

    if (!_window)
    {
        SDL_Log(SDL_GetError());
        return false;
    }


    Uint32 _flag2 = SDL_RENDERER_ACCELERATED;
    _renderer = SDL_CreateRenderer(_window, -1, _flag2);

    if (!_renderer)
    {
        SDL_Log(SDL_GetError());
        return false;
    }
    m_Input = new SdlInput();
    m_IsInit = true;

#ifdef _DEBUG
    m_Logger = new ConsoleLogger();
#endif

     
    //This is release
#ifdef NDEBUG
    m_Logger = new FileLogger();

#endif

    return true;
}

void Engine::Start(void) {
    if (!m_IsInit) {
        if (!Init("Unknow title", 800, 600)) {
            return;
        }
    }
    m_Input->m_IsRunning = true;
    clock_t _end = clock();


    while (m_Input->m_IsRunning) {
        const clock_t _start = clock();
        float dt = (_start - _end) * 0.001f;
        ProcessInput();
        Update(dt);
        Render();

        _end = _start;
    }
    Shutdown();
}

void Engine::ProcessInput(void)
{
    m_Input->Update();
    
}

static float x = 0.0f;
static float y = 0.0f;
void Engine::Update(float dt)
{

    if (m_Input->IsKeyDown(SDL_SCANCODE_D)) {
        x += 100 * dt;
        m_Logger->Log("D is pressed");
    }
    if (m_Input->IsKeyDown(SDL_SCANCODE_A)) {
        x -= 100 * dt;
        m_Logger->Log("A is pressed");
    }
    if (m_Input->IsKeyDown(SDL_SCANCODE_W)) {
        y -= 100 * dt;
        m_Logger->Log("W is pressed");
    }
    if (m_Input->IsKeyDown(SDL_SCANCODE_S)) {
        y += 100 * dt;
        m_Logger->Log("S is pressed");
    }
    if (m_Input->IsKeyDown(SDL_SCANCODE_ESCAPE)) {
        m_Input->m_IsRunning = false;
    }
}

void Engine::Render(void)
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);

    SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
    SDL_Rect get_rect = { 0 };
    get_rect.x = x;
    get_rect.y = y;
    get_rect.h = 100;
    get_rect.w = 100;
    SDL_RenderDrawRect(_renderer, &get_rect);

    SDL_RenderPresent(_renderer);
}

void Engine::Shutdown(void)
{
    if (m_Input != nullptr)
    {
        delete m_Input;
    }
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}


