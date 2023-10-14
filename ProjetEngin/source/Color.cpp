#include "Color.h"

Color::Color(uchar red, uchar green, uchar blue, uchar alpha = 255)
{
	Color::red = red; Color::green = green; Color::blue = blue; Color::alpha = alpha;
}

const Color& Color::Red = Color(255, 0, 0, 255);
const Color& Color::Green = Color(0, 255, 0, 255);
const Color& Color::Blue = Color(0, 0, 255, 255);
