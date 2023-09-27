#include <iostream>
#include <cmath>

using namespace std;

double const PI = 3.14;

double distance(int c1, int c2, int p1, int p2);
double radius(int c1, int c2, int p1, int p2);
double circumference(double r);
double area(double r);

int main()
{
	int c1, c2;
	int p1, p2;
	cout << "Enter the coordinates of the center ofthe circle: " << endl;
	cin >> c1 >> c2;
	cout << "Enter the coordinates of one point on the circle: " << endl;
	cin >> p1 >> p2;

	double r = radius(c1, c2, p1, p2);
	cout << "The radius of the circle is: " << r << endl;
	cout << "The diameter of the circle is: " << 2 * r << endl;
	cout << "The circumference of the circle is: " << circumference(r) << endl;
	cout << "The area of the circle is: " << area(r) << endl;

	return 0;
}

double distance(int c1, int c2, int p1, int p2)
{
	return sqrt(pow(c1 - p1, 2) + pow(c2 - p2, 2));
}

double radius(int c1, int c2, int p1, int p2)
{
	return distance(c1, c2, p1, p2);
}

double circumference(double r)
{
	return 2 * PI * r;
}

double area(double r)
{
	return  PI * (pow(r, 2));
}