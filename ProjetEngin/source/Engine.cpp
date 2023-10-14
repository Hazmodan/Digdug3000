#include "Engine.h"
#include "SDL.h"
#include <time.h>
#include "SdlInput.h"
#include "Windows.h">
#include "fileLogger.h"
#include "consoleLogger.h"
#include "SdlGraphics.h"

using namespace ProjetEngin;

bool Engine::Init(const char* name, int w, int h) {

    m_Graphics = new SdlGraphics();

    m_Graphics->Initialize("DigDUG3000", 800, 600);

    m_Input = new SdlInput();
    m_IsInit = true;
    
//placeholder/test start
    digdugtest = m_Graphics->LoadTexture("assets/digdugTest.png");
    m_DigdugRect = RectF();
    m_DigdugRect.x = 16;
    m_DigdugRect.y = 16;
    m_DigdugRect.h = 100;
    m_DigdugRect.w = 100;
//placeholder/test end

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
    m_Graphics->Clear();
    
    m_Graphics->DrawRect(x, y, 102, 102, Color::Red);

    m_Graphics->DrawTexture(digdugtest, m_DigdugRect, Color::Red);

    m_Graphics->Present();    
}

void Engine::Shutdown(void)
{
    if (m_Input != nullptr)
    {
        delete m_Input;
    }
    m_Graphics->Shutdown();
}


