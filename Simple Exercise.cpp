// Programming Exercise 1

#include <iostream>

using namespace std;

void initialize(int& a, int& b, char& c);
void getHoursRate(double& r, double& h);
double payCheck(double r, double h);
void printCheck(double h, double r, double amount);
void funcOne(int& a, int b);
void nextChar(char& c);

int main()
{
	int x, y;
	char z;
	double rate, hours;
	double amount;

	initialize(x, y, z);
	getHoursRate(rate, hours);
	amount = payCheck(rate, hours);

	printCheck(hours, rate, amount);

	cout << "Initial value of x is: " << x << endl;
	funcOne(x, y);
	cout << "Value of x after funcOne is:  " << x << endl;

	cout << "Initial value of z is: " << z << endl;
	nextChar(z);
	cout << "Value of z after nextChar is:  " << z << endl;

	return 0;
}

void initialize(int& a, int& b, char& c)
{
	a = 0;
	b = 0;
	c = 'a'; // the null character

}

void getHoursRate(double& r, double& h)
{
	cout << "Enter the number of hours worked and the rate per hour: " << endl;
	cin >> r >> h;
}

double payCheck(double r, double h)
{
	if (h > 40)
		return 40 * r + 1.5 * r * (h - 40);
	else
		return r * h;

}

void printCheck(double h, double r, double amount)
{
	cout << "The number of hours worked is: " << h << endl;
	cout << "The rate per hour is " << r << " for the first 40 hours, and " << 1.5 * r << " for hours over 40" << endl;
	cout << "The amount due is: " << amount << endl;
}

void funcOne(int& a, int b)
{
	int c;
	cout << "Enter a number: " << endl;
	cin >> c;
	a = 2 * a + b - c;
}

void nextChar(char& c)
{
	c = static_cast <char> (c + 1);
}