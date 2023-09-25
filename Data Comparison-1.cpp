// Data Comparison-Part1

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void calculateAverage(ifstream& inFile, double& avg);
void printResult(ofstream& outFile, string ID, int grpNb, double avg);


int main()
{
	ifstream inFile1, inFile2;
	ofstream outFile;

	inFile1.open("C:\\group1.txt");
	inFile2.open("C:\\group2.txt");
	outFile.open("C:\\outData.txt");

	if (!inFile1 || !inFile2)
	{
		cout << "Unable to open files!!" << endl;
		cout << "Program terminated!!" << endl;
		return 1;
	}

	outFile << fixed << showpoint << setprecision(2);
	outFile << "Course No" << "  "
		<< setw(8) << "Group No" << "  "
		<< setw(16) << "Course Average" << endl;

	string courseID1, courseID2;
	inFile1 >> courseID1;
	inFile2 >> courseID2;

	double totalAvg1 = 0;
	double totalAvg2 = 0;

	int courseCount1 = 0;
	int courseCount2 = 0;


	double avg1;
	double avg2;
	while (inFile1 && inFile2)
	{

		if (courseID1 != courseID2)
		{
			cout << "Not matching course IDs!!" << endl;
			cout << "Program terminated!!" << endl;
			return 1;
		}

		calculateAverage(inFile1, avg1);
		calculateAverage(inFile2, avg2);

		printResult(outFile, courseID1, 1, avg1);
		printResult(outFile, courseID2, 2, avg2);
		outFile << endl;

		totalAvg1 = totalAvg1 + avg1;
		courseCount1++;
		totalAvg2 = totalAvg2 + avg2;
		courseCount2++;

		inFile1 >> courseID1;
		inFile2 >> courseID2;

	}

	if (inFile1 && !inFile2)
		cout << "Ran out of data for group 2 before group 1." << endl;
	else if (!inFile1 && inFile2)
		cout << "Ran out of data for group 1 before group 2." << endl;
	else
	{
		outFile << "Avg for group 1: " << totalAvg1 / courseCount1 << endl;
		outFile << "Avg for group 2: " << totalAvg2 / courseCount2 << endl;
	}

	inFile1.close();
	inFile2.close();
	outFile.close();


	return 0;
}

void calculateAverage(ifstream& inFile, double& avg)
{
	double average = 0;

	double score;
	double count = 0;

	inFile >> score;
	while (score != -999)
	{
		average = average + score;
		count++;
		inFile >> score;
	}
	avg = average / count;

}

void printResult(ofstream& outFile, string ID, int grpNb, double avg)
{
	outFile << fixed << showpoint << setprecision(2);
	if (grpNb == 1)
		outFile << "   " << ID << "   ";
	else
		outFile << "         ";
	outFile << setw(8) << grpNb << setw(17) << avg << endl;
}