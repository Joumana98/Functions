#include <iostream>

using namespace std;

double growthRate(int b, int d);
int estimatePopulation(int p, double gr, int n);

int main()
{

	int p;
	cout << "Enter the starting population: " << endl;
	cin >> p;
	while (cin)
	{
		if (p < 2)
		{
			cout << "The population should be greater or equal to 2. Enter population again: " << endl;
			cin >> p;
		}
		else
			break;
	}

	int b, d;
	cout << "Enter the birth and death rate respectively: " << endl;
	cin >> b >> d;
	while (cin)
	{
		if (b < 0 || d < 0)
		{
			cout << "Both rates should be positive!! Enter rates again: " << endl;
			cin >> b >> d;
		}
		else
			break;
	}

	int n;
	cout << "Enter the number of years: " << endl;
	cin >> n;

	cout << "The estimated population after " << n << " years is: "
		<< estimatePopulation(p, growthRate(b, d), n) << endl;

	return 0;
}

double growthRate(int b, int d)
{
	return static_cast <double> (b - d);
}

int estimatePopulation(int p, double gr, int n)
{
	double currentp = p * (1 + gr / 100.0);
	for (int i = 1; i < n; i++)
		currentp = currentp * (1 + gr / 100.0);

	return static_cast <int> (currentp);
}