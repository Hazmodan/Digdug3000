#include <Color.h>

/// <summary>
/// color constructor without the alpha value
/// </summary>
/// <param name="red"></param>
/// <param name="green"></param>
/// <param name="blue"></param>
ProjetEngin::Color::Color(uchar red, uchar green, uchar blue) :
	Color(red, green, blue, 255)
{
}

/// <summary>
/// Color constructor, with an alpha value
/// </summary>
/// <param name="red"></param>
/// <param name="green"></param>
/// <param name="blue"></param>
/// <param name="alpha"></param>
ProjetEngin::Color::Color(uchar red, uchar green, uchar blue, uchar alpha) :
	red(red), green(green), blue(blue), alpha(alpha)
{
}

/// <summary>
/// Sets a color
/// </summary>
/// <param name="other"></param>
void ProjetEngin::Color::Set(const Color& other)
{
    red = other.red;
    green = other.green;
    blue = other.blue;
    alpha = other.alpha;
}

/// <summary>
/// All the colors constants to potentially be used
/// </summary>
const ProjetEngin::Color& ProjetEngin::Color::MAROON = ProjetEngin::Color(128, 0, 0);
const ProjetEngin::Color& ProjetEngin::Color::DARKRED = ProjetEngin::Color(139, 0, 0);
const ProjetEngin::Color& ProjetEngin::Color::BROWN = ProjetEngin::Color(165, 42, 42);
const ProjetEngin::Color& ProjetEngin::Color::FIREBRICK = ProjetEngin::Color(178, 34, 34);
const ProjetEngin::Color& ProjetEngin::Color::CRIMSON = ProjetEngin::Color(220, 20, 60);
const ProjetEngin::Color& ProjetEngin::Color::RED = ProjetEngin::Color(255, 0, 0);
const ProjetEngin::Color& ProjetEngin::Color::TOMATO = ProjetEngin::Color(255, 99, 71);
const ProjetEngin::Color& ProjetEngin::Color::CORAL = ProjetEngin::Color(255, 127, 80);
const ProjetEngin::Color& ProjetEngin::Color::INDIANRED = ProjetEngin::Color(205, 92, 92);
const ProjetEngin::Color& ProjetEngin::Color::LIGHTCORAL = ProjetEngin::Color(240, 128, 128);
const ProjetEngin::Color& ProjetEngin::Color::DARKSALMON = ProjetEngin::Color(233, 150, 122);
const ProjetEngin::Color& ProjetEngin::Color::SALMON = ProjetEngin::Color(250, 128, 114);
const ProjetEngin::Color& ProjetEngin::Color::LIGHTSALMON = ProjetEngin::Color(255, 160, 122);
const ProjetEngin::Color& ProjetEngin::Color::ORANGERED = ProjetEngin::Color(255, 69, 0);
const ProjetEngin::Color& ProjetEngin::Color::DARKORANGE = ProjetEngin::Color(255, 140, 0);
const ProjetEngin::Color& ProjetEngin::Color::ORANGE = ProjetEngin::Color(255, 165, 0);
const ProjetEngin::Color& ProjetEngin::Color::GOLD = ProjetEngin::Color(255, 215, 0);
const ProjetEngin::Color& ProjetEngin::Color::DARKGOLDENROD = ProjetEngin::Color(184, 134, 11);
const ProjetEngin::Color& ProjetEngin::Color::GOLDENROD = ProjetEngin::Color(218, 165, 32);
const ProjetEngin::Color& ProjetEngin::Color::PALEGOLDENROD = ProjetEngin::Color(238, 232, 170);
const ProjetEngin::Color& ProjetEngin::Color::DARKKHAKI = ProjetEngin::Color(189, 183, 107);
const ProjetEngin::Color& ProjetEngin::Color::KHAKI = ProjetEngin::Color(240, 230, 140);
const ProjetEngin::Color& ProjetEngin::Color::OLIVE = ProjetEngin::Color(128, 128, 0);
const ProjetEngin::Color& ProjetEngin::Color::YELLOW = ProjetEngin::Color(255, 255, 0);
const ProjetEngin::Color& ProjetEngin::Color::YELLOWGREEN = ProjetEngin::Color(154, 205, 50);
const ProjetEngin::Color& ProjetEngin::Color::DARKOLIVEGREEN = ProjetEngin::Color(85, 107, 47);
const ProjetEngin::Color& ProjetEngin::Color::OLIVEDRAB = ProjetEngin::Color(107, 142, 35);
const ProjetEngin::Color& ProjetEngin::Color::LAWNGREEN = ProjetEngin::Color(124, 252, 0);
const ProjetEngin::Color& ProjetEngin::Color::CHARTREUSE = ProjetEngin::Color(127, 255, 0);
const ProjetEngin::Color& ProjetEngin::Color::GREENYELLOW = ProjetEngin::Color(173, 255, 47);
const ProjetEngin::Color& ProjetEngin::Color::DARKGREEN = ProjetEngin::Color(0, 100, 0);
const ProjetEngin::Color& ProjetEngin::Color::GREEN = ProjetEngin::Color(0, 128, 0);
const ProjetEngin::Color& ProjetEngin::Color::FORESTGREEN = ProjetEngin::Color(34, 139, 34);
const ProjetEngin::Color& ProjetEngin::Color::LIME = ProjetEngin::Color(0, 255, 0);
const ProjetEngin::Color& ProjetEngin::Color::LIMEGREEN = ProjetEngin::Color(50, 205, 50);
const ProjetEngin::Color& ProjetEngin::Color::LIGHTGREEN = ProjetEngin::Color(144, 238, 144);
const ProjetEngin::Color& ProjetEngin::Color::PALEGREEN = ProjetEngin::Color(152, 251, 152);
const ProjetEngin::Color& ProjetEngin::Color::DARKSEAGREEN = ProjetEngin::Color(143, 188, 143);
const ProjetEngin::Color& ProjetEngin::Color::MEDIUMSPRINGGREEN = ProjetEngin::Color(0, 250, 154);
const ProjetEngin::Color& ProjetEngin::Color::SPRINGGREEN = ProjetEngin::Color(0, 255, 127);
const ProjetEngin::Color& ProjetEngin::Color::SEAGREEN = ProjetEngin::Color(46, 139, 87);
const ProjetEngin::Color& ProjetEngin::Color::MEDIUMAQUAMARINE = ProjetEngin::Color(102, 205, 170);
const ProjetEngin::Color& ProjetEngin::Color::MEDIUMSEAGREEN = ProjetEngin::Color(60, 179, 113);
const ProjetEngin::Color& ProjetEngin::Color::LIGHTSEAGREEN = ProjetEngin::Color(32, 178, 170);
const ProjetEngin::Color& ProjetEngin::Color::DARKSLATEGRAY = ProjetEngin::Color(47, 79, 79);
const ProjetEngin::Color& ProjetEngin::Color::TEAL = ProjetEngin::Color(0, 128, 128);
const ProjetEngin::Color& ProjetEngin::Color::DARKCYAN = ProjetEngin::Color(0, 139, 139);
const ProjetEngin::Color& ProjetEngin::Color::AQUA = ProjetEngin::Color(0, 255, 255);
const ProjetEngin::Color& ProjetEngin::Color::CYAN = ProjetEngin::Color(0, 255, 255);
const ProjetEngin::Color& ProjetEngin::Color::LIGHTCYAN = ProjetEngin::Color(224, 255, 255);
const ProjetEngin::Color& ProjetEngin::Color::DARKTURQUOISE = ProjetEngin::Color(0, 206, 209);
const ProjetEngin::Color& ProjetEngin::Color::TURQUOISE = ProjetEngin::Color(64, 224, 208);
const ProjetEngin::Color& ProjetEngin::Color::MEDIUMTURQUOISE = ProjetEngin::Color(72, 209, 204);
const ProjetEngin::Color& ProjetEngin::Color::PALETURQUOISE = ProjetEngin::Color(175, 238, 238);
const ProjetEngin::Color& ProjetEngin::Color::AQUAMARINE = ProjetEngin::Color(127, 255, 212);
const ProjetEngin::Color& ProjetEngin::Color::POWDERBLUE = ProjetEngin::Color(176, 224, 230);
const ProjetEngin::Color& ProjetEngin::Color::CADETBLUE = ProjetEngin::Color(95, 158, 160);
const ProjetEngin::Color& ProjetEngin::Color::STEELBLUE = ProjetEngin::Color(70, 130, 180);
const ProjetEngin::Color& ProjetEngin::Color::CORNFLOWERBLUE = ProjetEngin::Color(100, 149, 237);
const ProjetEngin::Color& ProjetEngin::Color::DEEPSKYBLUE = ProjetEngin::Color(0, 191, 255);
const ProjetEngin::Color& ProjetEngin::Color::DODGERBLUE = ProjetEngin::Color(30, 144, 255);
const ProjetEngin::Color& ProjetEngin::Color::LIGHTBLUE = ProjetEngin::Color(173, 216, 230);
const ProjetEngin::Color& ProjetEngin::Color::SKYBLUE = ProjetEngin::Color(135, 206, 235);
const ProjetEngin::Color& ProjetEngin::Color::LIGHTSKYBLUE = ProjetEngin::Color(135, 206, 250);
const ProjetEngin::Color& ProjetEngin::Color::MIDNIGHTBLUE = ProjetEngin::Color(25, 25, 112);
const ProjetEngin::Color& ProjetEngin::Color::NAVY = ProjetEngin::Color(0, 0, 128);
const ProjetEngin::Color& ProjetEngin::Color::DARKBLUE = ProjetEngin::Color(0, 0, 139);
const ProjetEngin::Color& ProjetEngin::Color::MEDIUMBLUE = ProjetEngin::Color(0, 0, 205);
const ProjetEngin::Color& ProjetEngin::Color::BLUE = ProjetEngin::Color(0, 0, 255);
const ProjetEngin::Color& ProjetEngin::Color::ROYALBLUE = ProjetEngin::Color(65, 105, 225);
const ProjetEngin::Color& ProjetEngin::Color::BLUEVIOLET = ProjetEngin::Color(138, 43, 226);
const ProjetEngin::Color& ProjetEngin::Color::INDIGO = ProjetEngin::Color(75, 0, 130);
const ProjetEngin::Color& ProjetEngin::Color::DARKSLATEBLUE = ProjetEngin::Color(72, 61, 139);
const ProjetEngin::Color& ProjetEngin::Color::SLATEBLUE = ProjetEngin::Color(106, 90, 205);
const ProjetEngin::Color& ProjetEngin::Color::MEDIUMSLATEBLUE = ProjetEngin::Color(123, 104, 238);
const ProjetEngin::Color& ProjetEngin::Color::MEDIUMPURPLE = ProjetEngin::Color(147, 112, 219);
const ProjetEngin::Color& ProjetEngin::Color::DARKMAGENTA = ProjetEngin::Color(139, 0, 139);
const ProjetEngin::Color& ProjetEngin::Color::DARKVIOLET = ProjetEngin::Color(148, 0, 211);
const ProjetEngin::Color& ProjetEngin::Color::DARKORCHID = ProjetEngin::Color(153, 50, 204);
const ProjetEngin::Color& ProjetEngin::Color::MEDIUMORCHID = ProjetEngin::Color(186, 85, 211);
const ProjetEngin::Color& ProjetEngin::Color::PURPLE = ProjetEngin::Color(128, 0, 128);
const ProjetEngin::Color& ProjetEngin::Color::THISTLE = ProjetEngin::Color(216, 191, 216);
const ProjetEngin::Color& ProjetEngin::Color::PLUM = ProjetEngin::Color(221, 160, 221);
const ProjetEngin::Color& ProjetEngin::Color::VIOLET = ProjetEngin::Color(238, 130, 238);
const ProjetEngin::Color& ProjetEngin::Color::MAGENTA = ProjetEngin::Color(255, 0, 255);
const ProjetEngin::Color& ProjetEngin::Color::ORCHID = ProjetEngin::Color(218, 112, 214);
const ProjetEngin::Color& ProjetEngin::Color::MEDIUMVIOLETRED = ProjetEngin::Color(199, 21, 133);
const ProjetEngin::Color& ProjetEngin::Color::PALEVIOLETRED = ProjetEngin::Color(219, 112, 147);
const ProjetEngin::Color& ProjetEngin::Color::DEEPPINK = ProjetEngin::Color(255, 20, 147);
const ProjetEngin::Color& ProjetEngin::Color::HOTPINK = ProjetEngin::Color(255, 105, 180);
const ProjetEngin::Color& ProjetEngin::Color::LIGHTPINK = ProjetEngin::Color(255, 182, 193);
const ProjetEngin::Color& ProjetEngin::Color::PINK = ProjetEngin::Color(255, 192, 203);
const ProjetEngin::Color& ProjetEngin::Color::ANTIQUEWHITE = ProjetEngin::Color(250, 235, 215);
const ProjetEngin::Color& ProjetEngin::Color::BEIGE = ProjetEngin::Color(245, 245, 220);
const ProjetEngin::Color& ProjetEngin::Color::BISQUE = ProjetEngin::Color(255, 228, 196);
const ProjetEngin::Color& ProjetEngin::Color::BLANCHEDALMOND = ProjetEngin::Color(255, 235, 205);
const ProjetEngin::Color& ProjetEngin::Color::WHEAT = ProjetEngin::Color(245, 222, 179);
const ProjetEngin::Color& ProjetEngin::Color::CORNSILK = ProjetEngin::Color(255, 248, 220);
const ProjetEngin::Color& ProjetEngin::Color::LEMONCHIFFON = ProjetEngin::Color(255, 250, 205);
const ProjetEngin::Color& ProjetEngin::Color::LIGHTGOLDENRODYELLOW = ProjetEngin::Color(250, 250, 210);
const ProjetEngin::Color& ProjetEngin::Color::LIGHTYELLOW = ProjetEngin::Color(255, 255, 224);
const ProjetEngin::Color& ProjetEngin::Color::SADDLEBROWN = ProjetEngin::Color(139, 69, 19);
const ProjetEngin::Color& ProjetEngin::Color::SIENNA = ProjetEngin::Color(160, 82, 45);
const ProjetEngin::Color& ProjetEngin::Color::CHOCOLATE = ProjetEngin::Color(210, 105, 30);
const ProjetEngin::Color& ProjetEngin::Color::PERU = ProjetEngin::Color(205, 133, 63);
const ProjetEngin::Color& ProjetEngin::Color::SANDYBROWN = ProjetEngin::Color(244, 164, 96);
const ProjetEngin::Color& ProjetEngin::Color::BURLYWOOD = ProjetEngin::Color(222, 184, 135);
const ProjetEngin::Color& ProjetEngin::Color::TAN = ProjetEngin::Color(210, 180, 140);
const ProjetEngin::Color& ProjetEngin::Color::ROSYBROWN = ProjetEngin::Color(188, 143, 143);
const ProjetEngin::Color& ProjetEngin::Color::MOCCASIN = ProjetEngin::Color(255, 228, 181);
const ProjetEngin::Color& ProjetEngin::Color::NAVAJOWHITE = ProjetEngin::Color(255, 222, 173);
const ProjetEngin::Color& ProjetEngin::Color::PEACHPUFF = ProjetEngin::Color(255, 218, 185);
const ProjetEngin::Color& ProjetEngin::Color::MISTYROSE = ProjetEngin::Color(255, 228, 225);
const ProjetEngin::Color& ProjetEngin::Color::LAVENDERBLUSH = ProjetEngin::Color(255, 240, 245);
const ProjetEngin::Color& ProjetEngin::Color::LINEN = ProjetEngin::Color(250, 240, 230);
const ProjetEngin::Color& ProjetEngin::Color::OLDLACE = ProjetEngin::Color(253, 245, 230);
const ProjetEngin::Color& ProjetEngin::Color::PAPAYAWHIP = ProjetEngin::Color(255, 239, 213);
const ProjetEngin::Color& ProjetEngin::Color::SEASHELL = ProjetEngin::Color(255, 245, 238);
const ProjetEngin::Color& ProjetEngin::Color::MINTCREAM = ProjetEngin::Color(245, 255, 250);
const ProjetEngin::Color& ProjetEngin::Color::SLATEGRAY = ProjetEngin::Color(112, 128, 144);
const ProjetEngin::Color& ProjetEngin::Color::LIGHTSLATEGRAY = ProjetEngin::Color(119, 136, 153);
const ProjetEngin::Color& ProjetEngin::Color::LIGHTSTEELBLUE = ProjetEngin::Color(176, 196, 222);
const ProjetEngin::Color& ProjetEngin::Color::LAVENDER = ProjetEngin::Color(230, 230, 250);
const ProjetEngin::Color& ProjetEngin::Color::FLORALWHITE = ProjetEngin::Color(255, 250, 240);
const ProjetEngin::Color& ProjetEngin::Color::ALICEBLUE = ProjetEngin::Color(240, 248, 255);
const ProjetEngin::Color& ProjetEngin::Color::GHOSTWHITE = ProjetEngin::Color(248, 248, 255);
const ProjetEngin::Color& ProjetEngin::Color::HONEYDEW = ProjetEngin::Color(240, 255, 240);
const ProjetEngin::Color& ProjetEngin::Color::IVORY = ProjetEngin::Color(255, 255, 240);
const ProjetEngin::Color& ProjetEngin::Color::AZURE = ProjetEngin::Color(240, 255, 255);
const ProjetEngin::Color& ProjetEngin::Color::SNOW = ProjetEngin::Color(255, 250, 250);
const ProjetEngin::Color& ProjetEngin::Color::BLACK = ProjetEngin::Color(0, 0, 0);
const ProjetEngin::Color& ProjetEngin::Color::DIMGREY = ProjetEngin::Color(105, 105, 105);
const ProjetEngin::Color& ProjetEngin::Color::GREY = ProjetEngin::Color(128, 128, 128);
const ProjetEngin::Color& ProjetEngin::Color::DARKGREY = ProjetEngin::Color(169, 169, 169);
const ProjetEngin::Color& ProjetEngin::Color::SILVER = ProjetEngin::Color(192, 192, 192);
const ProjetEngin::Color& ProjetEngin::Color::LIGHTGREY = ProjetEngin::Color(211, 211, 211);
const ProjetEngin::Color& ProjetEngin::Color::GAINSBORO = ProjetEngin::Color(220, 220, 220);
const ProjetEngin::Color& ProjetEngin::Color::WHITESMOKE = ProjetEngin::Color(245, 245, 245);
const ProjetEngin::Color& ProjetEngin::Color::WHITE = ProjetEngin::Color(255, 255, 255);
