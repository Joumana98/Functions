// Exercise 8

#include <iostream>
#include <iomanip>

using namespace std;

void calculateVolume(double L, double W, double& x, double& l, double& w, double& v);

int main()
{

	cout << fixed << showpoint << setprecision(3);

	double L, W;
	cout << "Enter the length and width of the flat card board: " << endl;
	cin >> L >> W;

	double l, w;
	double side;

	double volume = 0; // volume of the box is l*w*side

	calculateVolume(L, W, side, l, w, volume);

	cout << "The max volume of the box is: " << volume << endl;
	cout << "The length and width are: " << l << " and " << w << endl;
	cout << "The side of the square to be removed is: " << side << endl;





	return 0;
}

void calculateVolume(double L, double W, double& x, double& l, double& w, double& v)
{
	double side = 0.001;
	double width = W - 2 * side;
	double length = L - 2 * side;

	double volume = 0;


	while (width > 0 && length > 0)
	{
		width = W - 2 * side;
		length = L - 2 * side;
		volume = side * width * length;
		if (volume > v)
		{
			v = volume;
			w = width;
			l = length;
			x = side;
		}
		side = side + 0.001;

	}




}