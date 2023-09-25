// Programming Example
// Data Comparison-Part2-Bar Graph

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void calculateAverage(ifstream& inFile, double& avg);
void printResult(ofstream& outFile, string ID, int grpNb, double avg);
void printHeader(ofstream& outFile);


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
	printHeader(outFile);

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
		outFile << "Group 1 -- ****" << endl;
		outFile << "Group 2 -- ####" << endl;
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

void printHeader(ofstream& outFile)
{
	outFile << "Course       Course Average" << endl;
	outFile << "ID     0   10   20   30   40   50   60   70   80   90   100" << endl;
	outFile << "       |....|....|....|....|....|....|....|....|....|....|" << endl;

}

void printResult(ofstream& outFile, string ID, int grpNb, double avg)
{
	outFile << fixed << showpoint << setprecision(2);
	if (grpNb == 1)
		outFile << ID << "    ";
	else
		outFile << "       ";

	int symbolsNb;
	symbolsNb = static_cast <int> (avg / 2);
	if (grpNb == 1)
	{
		for (int count = 1; count <= symbolsNb; count++)
			outFile << "*";
	}
	else
	{
		for (int count = 1; count <= symbolsNb; count++)
			outFile << "#";
	}
	outFile << endl;

}
