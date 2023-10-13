#include "IGraphics.h"
#include "SdlGraphics.h"
#include <SDL.h>

using namespace ProjetEngin;

bool SdlGraphics::Initialize(const std::string& title, int w, int h)
{
	return false;
}

void SdlGraphics::Shutdown()
{
	SDL_Quit();
}

void SdlGraphics::SetColor(const Color& color)
{
}

void SdlGraphics::Clear()
{
}

void SdlGraphics::Present()
{
}

void SdlGraphics::DrawRect(float x, float y, float w, float h, const Color& color)
{
}

void SdlGraphics::DrawRect(const RectF& rect, const Color& color)
{
}

void SdlGraphics::FillRect(float x, float y, float w, float h, const Color& color)
{
}

void SdlGraphics::FillRect(const RectF& rect, const Color& color)
{
}

void SdlGraphics::DrawLine(float x1, float y1, float x2, float y2, const Color& color)
{
}

size_t SdlGraphics::LoadTexture(const std::string& filename)
{
	return size_t();
}

void SdlGraphics::DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color)
{
}

void SdlGraphics::DrawTexture(size_t id, const RectF& dst, const Color& color)
{
}

void SdlGraphics::DrawTexture(size_t id, const Color& color)
{
}

void SdlGraphics::GetTextureSize(size_t id, int* w, int* h)
{
}

size_t SdlGraphics::LoadFont(const std::string& filename, int fontSize)
{
	return size_t();
}

void SdlGraphics::DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color)
{
}

void SdlGraphics::GetTextSize(const std::string& text, size_t fontId, int* w, int* h)
{
}
