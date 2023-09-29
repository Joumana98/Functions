// Calculate GPA

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void openFiles(ifstream& inFile, ofstream& outFile, int& exist);
void initialize(int& f, int& m, double& maleGPA, double& femaleGPA);
void sumGrades(double& maleGPA, double& femaleGPA, int& m, int& f, ifstream& inFile);
void averageGrade(double& mAvg, double& fAvg, double maleGPA, double femaleGPA, int m, int f);
void printResults(ofstream& outFile, double maleGPA, double femaleGPA);

int main()
{
	ifstream inFile;
	ofstream outFile;
	int exist;
	openFiles(inFile, outFile, exist);
	if (exist == 1)
		return 1;

	int mCount, fCount;
	double mGPA, fGPA;
	initialize(fCount, mCount, mGPA, fGPA);

	sumGrades(mGPA, fGPA, mCount, fCount, inFile);

	double mAvg, fAvg;
	averageGrade(mAvg, fAvg, mGPA, fGPA, mCount, fCount);

	printResults(outFile, mAvg, fAvg);

	return 0;
}

void openFiles(ifstream& inFile, ofstream& outFile, int& exist)
{
	outFile << fixed << showpoint << setprecision(2);

	inFile.open("C:\\inData.txt");
	if (!inFile)
	{
		cout << "The file does not exist!!" << endl;
		cout << "The program terminates!!" << endl;
		exist = 1;
	}
	else
		exist = 0;

	outFile.open("C:\\outData.txt");


}

void initialize(int& f, int& m, double& maleGPA, double& femaleGPA)
{
	f = 0;
	m = 0;
	maleGPA = 0;
	femaleGPA = 0;
}

void sumGrades(double& maleGPA, double& femaleGPA, int& m, int& f, ifstream& inFile)
{
	char gender;
	double gpa;

	inFile >> gender >> gpa;

	while (inFile)
	{
		if (gender == 'm')
		{
			maleGPA = maleGPA + gpa;
			m++;
		}
		else if (gender == 'f')
		{
			femaleGPA = femaleGPA + gpa;
			f++;
		}
		else
		{
			cout << "Invalid gender type!!" << endl;
			continue;
		}

		inFile >> gender >> gpa;


	}
}

void averageGrade(double& mAvg, double& fAvg, double maleGPA, double femaleGPA, int m, int f)
{
	mAvg = maleGPA / m;
	fAvg = femaleGPA / f;
}

void printResults(ofstream& outFile, double maleGPA, double femaleGPA)
{
	outFile << "The average GPA for male students is: " << maleGPA << endl;
	outFile << "The average GPA for female students is: " << femaleGPA << endl;
}