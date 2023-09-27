#include <iostream>
#include <cmath>

using namespace std;

int degree(int n);
int reverseDigits(int n);

int main()
{
	int nb;
	cout << "Enter an integer: " << endl;
	cin >> nb;

	cout << "The number with its digits reversed is: " << reverseDigits(nb) << endl;


	return 0;
}

int degree(int n)
{
	int d = 0;
	int temp;
	if (n < 0)
		temp = -n;
	else
		temp = n;
	while (temp > 9)
	{
		temp = temp / 10;
		d++;
	}

	return d;
}

int reverseDigits(int n)
{
	int temp = n;
	int rev = 0;

	int d = degree(temp);

	while (d >= 0)
	{
		rev = rev + (temp % 10) * (pow(10, d));
		temp = temp / 10;
		d--;
	}

	return rev;

}