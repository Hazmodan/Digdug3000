typedef unsigned char uchar;

class Color {
public:
	Color(uchar red, uchar green, uchar blue, uchar alpha);

	static const Color& Red;
	static const Color& Green;
	static const Color& Blue;

	uchar red = 255;
	uchar green = 255;
	uchar blue = 255;
	uchar alpha = 255;

private:


};