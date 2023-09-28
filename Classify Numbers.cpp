// Classify Numbers-2

#include <iostream>
#include <fstream>

using namespace std;

const int N = 20;

void initialize(int& zeros, int& evens, int& odds);
int getNumber(ifstream& inFile, ofstream& outFile);
void classifyNumber(int n, int& zeros, int& evens, int& odds);
void printResults(ofstream& outFile, int zeros, int evens, int odds, double sum, double avg);

int main()
{
	ifstream inFile;
	inFile.open("C:\\inData.txt");
	if (!inFile)
	{
		cout << "The file does not exist!!" << endl;
		cout << "The program terminates!!" << endl;
		return 1;
	}
	ofstream outFile;
	outFile.open("C:\\outData.txt");

	int zeros, evens, odds;
	initialize(zeros, evens, odds);



	int count = 0;
	double sum = 0;
	int n = getNumber(inFile, outFile);
	while (inFile)
	{
		count++;
		sum = sum + n;
		if (count % 10 == 0)
			outFile << endl;

		classifyNumber(n, zeros, evens, odds);
		n = getNumber(inFile, outFile);

	}
	double avg = sum / count;

	printResults(outFile, zeros, evens, odds, sum, avg);


	return 0;
}

void initialize(int& zeros, int& evens, int& odds)
{
	zeros = 0;
	evens = 0;
	odds = 0;
}

int getNumber(ifstream& inFile, ofstream& outFile)
{
	int n;
	inFile >> n;
	if (inFile)
		outFile << n << " ";

	return n;

}

void classifyNumber(int n, int& zeros, int& evens, int& odds)
{
	if (n == 0)
		zeros++;
	else if (n % 2 == 0)
		evens++;
	else
		odds++;
}

void printResults(ofstream& outFile, int zeros, int evens, int odds, double sum, double avg)
{
	outFile << endl;
	outFile << "The number of zeros is: " << zeros << endl;
	outFile << "The number of even numbers is: " << evens << endl;
	outFile << "The number of odd numbers is: " << odds << endl;
	outFile << "The sum of the numbers is: " << sum << endl;
	outFile << "Th average is: " << avg << endl;
}