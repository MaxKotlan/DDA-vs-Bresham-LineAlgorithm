
#include <iostream>

const int width  = 80;
const int height = 80;

char screenbuffer[width * height];

void print() {
	for (int x = width - 1; x >= 0; x--) {
		for (int y = 0; y < height; y++)
			std::cout << screenbuffer[x + width * y];
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void DigitalDifferentialAnalyzer(int x1, int y1, int x2, int y2) {
	int dy = y2 - y1;
	int dx = x2 - x1;

	int step;
	if (abs(dx) > abs(dy))
		step = abs(dx);
	else
		step = abs(dy);

	float xinc = dx / ((float)step);
	float yinc = dy / ((float)step);

	float x = x1;
	float y = y1;
	for (int i = 0; i < step; i++) {
		int intx = (int)x;
		int inty = (int)y;
		screenbuffer[intx + width * inty] = '&';
		x += xinc;
		y += yinc;
	}
}

void BresenhamLineAlgorithm(int x1, int y1, int x2, int y2) {

	int dx = x2 - x1;
	int dy = y2 - y1;
	int steps, k;
	steps = dx;
	int x, y;
	int p0 = (2 * dy) - dx;

	screenbuffer[x1 + width * y1] = 'B';
	x = x1;
	y = y1;

	for (k = 0; k < steps; k++)
	{
		if (p0 < 2)
		{
			p0 = p0 + (2 * dy);
			x += 1;
		}
		else
		{
			p0 = p0 + (2 * dy) - (2 * dx);
			x += 1;
			y += 1;
		}
		screenbuffer[x + width * y] = 'B';
	}
}

int main() {
	for (int i = 0; i < width * height; i++)
		screenbuffer[i] = '`';
	//print();
	DigitalDifferentialAnalyzer(3, 5, 45, 67);
	BresenhamLineAlgorithm(3, 5, 45, 67);
	print();
	//DigitalDifferentialAnalyzer(12, 5, 70, 67);
	//DigitalDifferentialAnalyzer(45, 67, 53, 53);
	//print();

}