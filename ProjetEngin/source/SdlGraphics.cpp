#include "IGraphics.h"
#include "SdlGraphics.h"
#include <SDL.h>

using namespace ProjetEngin;

SdlGraphics::SdlGraphics():
_renderer(NULL),
_window(NULL)
{
}

SdlGraphics::~SdlGraphics()
{
}

bool SdlGraphics::Initialize(const char* name, int w, int h)
{
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

	return true;
}

void SdlGraphics::Shutdown()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

void SdlGraphics::SetColor(const Color& color)
{
	SDL_SetRenderDrawColor(_renderer, color.red, color.green, color.blue, 255);
}

void SdlGraphics::Clear()
{
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderClear(_renderer);
}

void SdlGraphics::Present()
{
	SDL_RenderPresent(_renderer);
}

void SdlGraphics::DrawRect(float x, float y, float w, float h, const Color& color)
{
	SetColor(color);
	SDL_Rect get_rect;
	get_rect.x = static_cast<int>(x);
	get_rect.y = static_cast<int>(y);
	get_rect.h = static_cast<int>(h);
	get_rect.w = static_cast<int>(w);
	SDL_RenderDrawRect(_renderer, &get_rect);
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
	const size_t _textureId = std::hash<std::string>()(filename);

	if (_textureMap.count(_textureId) > 0)
	{
		return _textureId;
	}

	SDL_Texture* _texture = IMG_LoadTexture(_renderer, filename.c_str());
	if(_texture != NULL)
	{
		_textureMap[_textureId] = _texture;
		return _textureId;
	}

	return 0;
}

void SdlGraphics::DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color)
{

}

void SdlGraphics::DrawTexture(size_t id, const RectF& dst, const Color& color)
{
	if (_textureMap.count(id) > 0)
	{
		SDL_Rect* _sourceRect = new SDL_Rect();

		GetTextureSize(id, &_sourceRect->w, &_sourceRect->h);

		SDL_Rect* _destinationRect = new SDL_Rect();

		_destinationRect->x = dst.x;
		_destinationRect->y = dst.y;
		_destinationRect->h = dst.h;
		_destinationRect->w = dst.w;

		SDL_RenderCopy(_renderer, _textureMap[id], _sourceRect, _destinationRect);
	}
}

void SdlGraphics::DrawTexture(size_t id, const Color& color)
{

}

void SdlGraphics::GetTextureSize(size_t id, int* w, int* h)
{
	if (_textureMap.count(id) > 0)
	{
		SDL_QueryTexture(_textureMap[id], nullptr, nullptr, w, h);
	}
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
