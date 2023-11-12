#include "IGraphics.h"
#include "SdlGraphics.h"
#include <SDL.h>

using namespace ProjetEngin;

/// <summary>
/// Constructor
/// </summary>
SdlGraphics::SdlGraphics():
_renderer(NULL),
_window(NULL)
{
}

/// <summary>
/// Destructor
/// </summary>
SdlGraphics::~SdlGraphics()
{
}

/// <summary>
/// Initializes SDL graphics
/// </summary>
/// <param name="name">= the name appearing at the top of the window border</param>
/// <param name="w">= the width of the window</param>
/// <param name="h">= the height of the window</param>
/// <returns></returns>
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

/// <summary>
/// Shuts down the application
/// </summary>
void SdlGraphics::Shutdown()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

/// <summary>
/// Uses SDL graphics and color to set the color of a visual element
/// </summary>
/// <param name="color"></param>
void SdlGraphics::SetColor(const Color& color)
{
	SDL_SetRenderDrawColor(_renderer, color.red, color.green, color.blue, 255);
}

/// <summary>
/// clears the visual elements from the render view
/// </summary>
void SdlGraphics::Clear()
{
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderClear(_renderer);
}


void SdlGraphics::Present()
{
	SDL_RenderPresent(_renderer);
}

/// <summary>
/// Draws a rectangle of specific position, dimension and color.
/// </summary>
/// <param name="x">= is the X position of the rectangle</param>
/// <param name="y">= is the Y position of the rectangle</param>
/// <param name="w">= is the width of the rectangle</param>
/// <param name="h">= is the height of the rectangle</param>
/// <param name="color"></param>
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

/// <summary>
/// Draws a rectangle of specific position, dimension and color. WIP
/// </summary>
/// <param name="rect"></param>
/// <param name="color"></param>
void SdlGraphics::DrawRect(const RectF& rect, const Color& color)
{
}

/// <summary>
/// Draws a rectangle of specific position, dimension and fill with a color.
/// </summary>
/// <param name="x">= is the X position of the rectangle</param>
/// <param name="y">= is the Y position of the rectangle</param>
/// <param name="w">= is the width of the rectangle</param>
/// <param name="h">= is the height of the rectangle</param>
/// <param name="color"></param>
void SdlGraphics::FillRect(float x, float y, float w, float h, const Color& color)
{
}

/// <summary>
/// Draws a rectangle of specific position, dimension and fill with a color.
/// </summary>
/// <param name="x">= is the X position of the rectangle</param>
/// <param name="y">= is the Y position of the rectangle</param>
/// <param name="w">= is the width of the rectangle</param>
/// <param name="h">= is the height of the rectangle</param>
/// <param name="color"></param>
void SdlGraphics::FillRect(const RectF& rect, const Color& color)
{
}

/// <summary>
/// Draws a line from 2 points specified by params
/// </summary>
/// <param name="x1">= X position for the first point</param>
/// <param name="y1">= Y position for the first point</param>
/// <param name="x2">= X position for the second point</param>
/// <param name="y2">= Y position for the second point</param>
/// <param name="color"></param>
void SdlGraphics::DrawLine(float x1, float y1, float x2, float y2, const Color& color)
{
}

/// <summary>
/// Loads a texture from the file name specified in the params.
/// </summary>
/// <param name="filename">= the file path to the image to be used</param>
/// <returns></returns>
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

/// <summary>
/// Draws a texture
/// </summary>
/// <param name="id">= the texture's ID</param>
/// <param name="src">= the SRC of the image</param>
/// <param name="dst">= distance from SRC of the image</param>
/// <param name="angle">= angle of the image</param>
/// <param name="flip">= toggle for if the image is to be flipped or not</param>
/// <param name="color">= the color tint to apply to the image (use white for no tint)</param>
void SdlGraphics::DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color)
{

}

/// <summary>
/// Draws a texture
/// </summary>
/// <param name="id">= the texture's ID</param>
/// <param name="dst">= distance from SRC of the image</param>
/// <param name="color">= the color tint to apply to the image (use white for no tint)</param>
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

/// <summary>
/// Draws a texture
/// </summary>
/// <param name="id">= the texture's ID</param>
/// <param name="color">= the color tint to apply to the image (use white for no tint)</param>
void SdlGraphics::DrawTexture(size_t id, const Color& color)
{

}

/// <summary>
/// Gets the size of a texture
/// </summary>
/// <param name="id">= the ID of the texture</param>
/// <param name="w">= the width of the texture</param>
/// <param name="h">= the height of the texture</param>
void SdlGraphics::GetTextureSize(size_t id, int* w, int* h)
{
	if (_textureMap.count(id) > 0)
	{
		SDL_QueryTexture(_textureMap[id], nullptr, nullptr, w, h);
	}
}

/// <summary>
/// Loads a font to be used
/// </summary>
/// <param name="filename">= the file path to the file itself</param>
/// <param name="fontSize">= the size of the font to be used</param>
/// <returns></returns>
size_t SdlGraphics::LoadFont(const std::string& filename, int fontSize)
{
	return size_t();
}

/// <summary>
/// Draws a text on the screen
/// </summary>
/// <param name="text">= the text to be printed in the screen</param>
/// <param name="fontId">the ID of the font to be used</param>
/// <param name="x">= the X position of the text</param>
/// <param name="y">= the Y position of the text</param>
/// <param name="color">= the color of the text</param>
void SdlGraphics::DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color)
{
}

/// <summary>
/// Gets the size of a text
/// </summary>
/// <param name="text">= the text to be sized</param>
/// <param name="fontId">= the ID of the font to be used</param>
/// <param name="w">= the width of the text</param>
/// <param name="h">= the height of the text</param>
void SdlGraphics::GetTextSize(const std::string& text, size_t fontId, int* w, int* h)
{
}
