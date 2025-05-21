/*
Zachery Evans
COSC-1337
Programming Assignment 1
03/06/2023
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
using namespace std;

//Global Constant

//Function Prototype
int getRand(int, int);
void makeKeysAs(int*, int);
int gradeTest(int*, int*, int, int);
void displayVector(vector <string>);

int main()
{
	//Random number generator
	unsigned seed = time(0);
	srand(seed);

	//Opening File
	ifstream infile;
	ofstream outfile;
	infile.open("SP23_HW1.txt");
	outfile.open("SP23_HW1_GradeReport.txt");

	//Variables
	const int LVL1_SIZE = 10, LVL2_SIZE = 40, LVL3_SIZE = 100, STU = 20;
	int students = 0, results1, results2, results3, results4, lvl4Size = 0, totalPoints = 0;

	//Arrays and Vectors
	int lvl1KeyArr[LVL1_SIZE], lvl2KeyArr[LVL2_SIZE], lvl3KeyArr[LVL3_SIZE];
	int tst1stu1[LVL1_SIZE], tst1stu2[LVL1_SIZE], tst1stu3[LVL1_SIZE], tst1stu4[LVL1_SIZE], tst1stu5[LVL1_SIZE], tst1stu6[LVL1_SIZE], tst1stu7[LVL1_SIZE], tst1stu8[LVL1_SIZE], tst1stu9[LVL1_SIZE], tst1stu10[LVL1_SIZE];
	int tst1stu11[LVL1_SIZE], tst1stu12[LVL1_SIZE], tst1stu13[LVL1_SIZE], tst1stu14[LVL1_SIZE], tst1stu15[LVL1_SIZE], tst1stu16[LVL1_SIZE], tst1stu17[LVL1_SIZE], tst1stu18[LVL1_SIZE], tst1stu19[LVL1_SIZE], tst1stu20[LVL1_SIZE];
	vector <string> level1Vec, level2Vec, level3Vec, level4Vec;

	//Pointers
	string* rosterPtr = nullptr;     //Pointer for dynamically allocated array of number of students
	int* testPtr = nullptr, * keyPtr = nullptr;

	//**Program Body**
	cout << "Please enter the number of students who are taking the test: ";
	cin >> students;
	cout << endl;
	rosterPtr = new string[students];
	for (int i = 0; i < students; i++)
		getline(infile, rosterPtr[i]);


	makeKeysAs(lvl1KeyArr, LVL1_SIZE);
	makeKeysAs(lvl2KeyArr, LVL2_SIZE);
	makeKeysAs(lvl3KeyArr, LVL3_SIZE);


	makeKeysAs(tst1stu1, LVL1_SIZE);
	results1 = gradeTest(lvl1KeyArr, tst1stu1, LVL1_SIZE, LVL1_SIZE);
	cout << rosterPtr[0] << " is taking the test...." << endl;
	cout << "Percentage Report: " << (results1 * 10) << endl;
	if ((results1 * 10) >= 50)
	{
		cout << "Advancing to level 2....." << endl;
		level2Vec.push_back(rosterPtr[0]);
		testPtr = new int[LVL2_SIZE];
		makeKeysAs(testPtr, LVL2_SIZE);
		results2 = gradeTest(lvl2KeyArr, testPtr, LVL2_SIZE, LVL2_SIZE);
		cout << "Percentage report: " << (results2 * 2) << endl;
		if ((results2 * 2) >= 20)
		{
			cout << "Advancing to level 3....." << endl;
			level3Vec.push_back(rosterPtr[0]);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[LVL3_SIZE];
			makeKeysAs(testPtr, LVL3_SIZE);
			results3 = gradeTest(lvl3KeyArr, testPtr, LVL3_SIZE, LVL3_SIZE);
			cout << "Percentage report: " << results3 << endl;
			lvl4Size = (results3 * .1);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[lvl4Size];
			keyPtr = new int[lvl4Size];
			makeKeysAs(keyPtr, lvl4Size);
			makeKeysAs(testPtr, lvl4Size);
			cout << "The size of test 4: " << lvl4Size << endl;
			results4 = gradeTest(keyPtr, testPtr, lvl4Size, lvl4Size);
			cout << "Percentage report: " << results4 << endl;
			totalPoints = ((results1 * 10) + (results2 * 2) + results3 + (results4 + 10));
			cout << "Total points: " << totalPoints << endl << endl;
			level4Vec.push_back(rosterPtr[0]);
			delete[] testPtr;
			delete[] keyPtr;
			testPtr = nullptr;
			keyPtr = nullptr;
		}
		else
		{
			cout << "Not Advancing after level 2." << endl;
			totalPoints = ((results1 * 10) + (results2 * 2));
			cout << "Total Points: " << totalPoints << endl << endl;
			results1 = 0, results2 = 0;
			delete[] testPtr;
			testPtr = nullptr;
		}
	}
	else
	{
		cout << "Not advancing after level 1....." << endl;
		level1Vec.push_back(rosterPtr[0]);
		totalPoints = (results1 * 10);
		cout << "Total points: " << totalPoints << endl << endl;
		results1 = 0;
	}
	outfile << rosterPtr[0] << " " << totalPoints << endl;
	totalPoints = 0;
	



	makeKeysAs(tst1stu2, LVL1_SIZE);
	results1 = gradeTest(lvl1KeyArr, tst1stu2, LVL1_SIZE, LVL1_SIZE);
	cout << rosterPtr[1] << " is taking the test...." << endl;
	cout << "Percentage Report: " << (results1 * 10) << endl;
	if ((results1 * 10) >= 50)
	{
		cout << "Advancing to level 2....." << endl;
		level2Vec.push_back(rosterPtr[1]);
		testPtr = new int[LVL2_SIZE];
		makeKeysAs(testPtr, LVL2_SIZE);
		results2 = gradeTest(lvl2KeyArr, testPtr, LVL2_SIZE, LVL2_SIZE);
		cout << "Percentage report: " << (results2 * 2) << endl;
		if ((results2 * 2) >= 20)
		{
			cout << "Advancing to level 3....." << endl;
			level3Vec.push_back(rosterPtr[1]);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[LVL3_SIZE];
			makeKeysAs(testPtr, LVL3_SIZE);
			results3 = gradeTest(lvl3KeyArr, testPtr, LVL3_SIZE, LVL3_SIZE);
			cout << "Percentage report: " << results3 << endl;
			lvl4Size = (results3 * .1);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[lvl4Size];
			keyPtr = new int[lvl4Size];
			makeKeysAs(keyPtr, lvl4Size);
			makeKeysAs(testPtr, lvl4Size);
			cout << "The size of test 4: " << lvl4Size << endl;
			results4 = gradeTest(keyPtr, testPtr, lvl4Size, lvl4Size);
			cout << "Percentage report: " << results4 << endl;
			totalPoints = ((results1 * 10) + (results2 * 2) + results3 + (results4 + 10));
			cout << "Total points: " << totalPoints << endl << endl;			
			level4Vec.push_back(rosterPtr[1]);
			delete[] testPtr;
			delete[] keyPtr;
			testPtr = nullptr;
			keyPtr = nullptr;
		}
		else
		{
			cout << "Not Advancing after level 2." << endl;
			totalPoints = ((results1 * 10) + (results2 * 2));
			cout << "Total Points: " << totalPoints << endl << endl;			
			results1 = 0, results2 = 0;
			delete[] testPtr;
			testPtr = nullptr;
		}
	}
	else
	{
		cout << "Not advancing after level 1....." << endl;
		level1Vec.push_back(rosterPtr[1]);
		totalPoints = (results1 * 10);
		cout << "Total points: " << totalPoints << endl << endl;		
		results1 = 0;
	}
	outfile << rosterPtr[1] << " " << totalPoints << endl;
	totalPoints = 0;

	makeKeysAs(tst1stu3, LVL1_SIZE);
	results1 = gradeTest(lvl1KeyArr, tst1stu3, LVL1_SIZE, LVL1_SIZE);
	cout << rosterPtr[2] << " is taking the test...." << endl;
	cout << "Percentage Report: " << (results1 * 10) << endl;
	if ((results1 * 10) >= 50)
	{
		cout << "Advancing to level 2....." << endl;
		level2Vec.push_back(rosterPtr[2]);
		testPtr = new int[LVL2_SIZE];
		makeKeysAs(testPtr, LVL2_SIZE);
		results2 = gradeTest(lvl2KeyArr, testPtr, LVL2_SIZE, LVL2_SIZE);
		cout << "Percentage report: " << (results2 * 2) << endl;
		if ((results2 * 2) >= 20)
		{
			cout << "Advancing to level 3....." << endl;
			level3Vec.push_back(rosterPtr[2]);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[LVL3_SIZE];
			makeKeysAs(testPtr, LVL3_SIZE);
			results3 = gradeTest(lvl3KeyArr, testPtr, LVL3_SIZE, LVL3_SIZE);
			cout << "Percentage report: " << results3 << endl;
			lvl4Size = (results3 * .1);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[lvl4Size];
			keyPtr = new int[lvl4Size];
			makeKeysAs(keyPtr, lvl4Size);
			makeKeysAs(testPtr, lvl4Size);
			cout << "The size of test 4: " << lvl4Size << endl;
			results4 = gradeTest(keyPtr, testPtr, lvl4Size, lvl4Size);
			cout << "Percentage report: " << results4 << endl;
			totalPoints = ((results1 * 10) + (results2 * 2) + results3 + (results4 + 10));
			cout << "Total points: " << totalPoints << endl << endl;			
			level4Vec.push_back(rosterPtr[2]);
			delete[] testPtr;
			delete[] keyPtr;
			testPtr = nullptr;
			keyPtr = nullptr;
		}
		else
		{
			cout << "Not Advancing after level 2." << endl;
			totalPoints = ((results1 * 10) + (results2 * 2));
			cout << "Total Points: " << totalPoints << endl << endl;			
			results1 = 0, results2 = 0;
			delete[] testPtr;
			testPtr = nullptr;
		}
	}
	else
	{
		cout << "Not advancing after level 1....." << endl;
		level1Vec.push_back(rosterPtr[2]);
		totalPoints = (results1 * 10);
		cout << "Total points: " << totalPoints << endl << endl;		
		results1 = 0;
	}
	outfile << rosterPtr[2] << " " << totalPoints << endl;
	totalPoints = 0;

	makeKeysAs(tst1stu4, LVL1_SIZE);
	results1 = gradeTest(lvl1KeyArr, tst1stu4, LVL1_SIZE, LVL1_SIZE);
	cout << rosterPtr[3] << " is taking the test...." << endl;
	cout << "Percentage Report: " << (results1 * 10) << endl;
	if ((results1 * 10) >= 50)
	{
		cout << "Advancing to level 2....." << endl;
		level2Vec.push_back(rosterPtr[3]);
		testPtr = new int[LVL2_SIZE];
		makeKeysAs(testPtr, LVL2_SIZE);
		results2 = gradeTest(lvl2KeyArr, testPtr, LVL2_SIZE, LVL2_SIZE);
		cout << "Percentage report: " << (results2 * 2) << endl;
		if ((results2 * 2) >= 20)
		{
			cout << "Advancing to level 3....." << endl;
			level3Vec.push_back(rosterPtr[3]);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[LVL3_SIZE];
			makeKeysAs(testPtr, LVL3_SIZE);
			results3 = gradeTest(lvl3KeyArr, testPtr, LVL3_SIZE, LVL3_SIZE);
			cout << "Percentage report: " << results3 << endl;
			lvl4Size = (results3 * .1);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[lvl4Size];
			keyPtr = new int[lvl4Size];
			makeKeysAs(keyPtr, lvl4Size);
			makeKeysAs(testPtr, lvl4Size);
			cout << "The size of test 4: " << lvl4Size << endl;
			results4 = gradeTest(keyPtr, testPtr, lvl4Size, lvl4Size);
			cout << "Percentage report: " << results4 << endl;
			totalPoints = ((results1 * 10) + (results2 * 2) + results3 + (results4 + 10));
			cout << "Total points: " << totalPoints << endl << endl;			
			level4Vec.push_back(rosterPtr[3]);
			delete[] testPtr;
			delete[] keyPtr;
			testPtr = nullptr;
			keyPtr = nullptr;
		}
		else
		{
			cout << "Not Advancing after level 2." << endl;
			totalPoints = ((results1 * 10) + (results2 * 2));
			cout << "Total Points: " << totalPoints << endl << endl;			
			results1 = 0, results2 = 0;
			delete[] testPtr;
			testPtr = nullptr;
		}
	}
	else
	{
		cout << "Not advancing after level 1....." << endl;
		level1Vec.push_back(rosterPtr[3]);
		totalPoints = (results1 * 10);
		cout << "Total points: " << totalPoints << endl << endl;		
		results1 = 0;
	}
	outfile << rosterPtr[3] << " " << totalPoints << endl;
	totalPoints = 0;

	makeKeysAs(tst1stu5, LVL1_SIZE);
	results1 = gradeTest(lvl1KeyArr, tst1stu5, LVL1_SIZE, LVL1_SIZE);
	cout << rosterPtr[4] << " is taking the test...." << endl;
	cout << "Percentage Report: " << (results1 * 10) << endl;
	if ((results1 * 10) >= 50)
	{
		cout << "Advancing to level 2....." << endl;
		level2Vec.push_back(rosterPtr[4]);
		testPtr = new int[LVL2_SIZE];
		makeKeysAs(testPtr, LVL2_SIZE);
		results2 = gradeTest(lvl2KeyArr, testPtr, LVL2_SIZE, LVL2_SIZE);
		cout << "Percentage report: " << (results2 * 2) << endl;
		if ((results2 * 2) >= 20)
		{
			cout << "Advancing to level 3....." << endl;
			level3Vec.push_back(rosterPtr[4]);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[LVL3_SIZE];
			makeKeysAs(testPtr, LVL3_SIZE);
			results3 = gradeTest(lvl3KeyArr, testPtr, LVL3_SIZE, LVL3_SIZE);
			cout << "Percentage report: " << results3 << endl;
			lvl4Size = (results3 * .1);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[lvl4Size];
			keyPtr = new int[lvl4Size];
			makeKeysAs(keyPtr, lvl4Size);
			makeKeysAs(testPtr, lvl4Size);
			cout << "The size of test 4: " << lvl4Size << endl;
			results4 = gradeTest(keyPtr, testPtr, lvl4Size, lvl4Size);
			cout << "Percentage report: " << results4 << endl;
			totalPoints = ((results1 * 10) + (results2 * 2) + results3 + (results4 + 10));
			cout << "Total points: " << totalPoints << endl << endl;			
			level4Vec.push_back(rosterPtr[4]);
			delete[] testPtr;
			delete[] keyPtr;
			testPtr = nullptr;
			keyPtr = nullptr;
		}
		else
		{
			cout << "Not Advancing after level 2." << endl;
			totalPoints = ((results1 * 10) + (results2 * 2));
			cout << "Total Points: " << totalPoints << endl << endl;			
			results1 = 0, results2 = 0;
			delete[] testPtr;
			testPtr = nullptr;
		}
	}
	else
	{
		cout << "Not advancing after level 1....." << endl;
		level1Vec.push_back(rosterPtr[4]);
		totalPoints = (results1 * 10);
		cout << "Total points: " << totalPoints << endl << endl;		
		results1 = 0;
	}
	outfile << rosterPtr[4] << " " << totalPoints << endl;
	totalPoints = 0;

	makeKeysAs(tst1stu6, LVL1_SIZE);
	results1 = gradeTest(lvl1KeyArr, tst1stu6, LVL1_SIZE, LVL1_SIZE);
	cout << rosterPtr[5] << " is taking the test...." << endl;
	cout << "Percentage Report: " << (results1 * 10) << endl;
	if ((results1 * 10) >= 50)
	{
		cout << "Advancing to level 2....." << endl;
		level2Vec.push_back(rosterPtr[5]);
		testPtr = new int[LVL2_SIZE];
		makeKeysAs(testPtr, LVL2_SIZE);
		results2 = gradeTest(lvl2KeyArr, testPtr, LVL2_SIZE, LVL2_SIZE);
		cout << "Percentage report: " << (results2 * 2) << endl;
		if ((results2 * 2) >= 20)
		{
			cout << "Advancing to level 3....." << endl;
			level3Vec.push_back(rosterPtr[5]);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[LVL3_SIZE];
			makeKeysAs(testPtr, LVL3_SIZE);
			results3 = gradeTest(lvl3KeyArr, testPtr, LVL3_SIZE, LVL3_SIZE);
			cout << "Percentage report: " << results3 << endl;
			lvl4Size = (results3 * .1);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[lvl4Size];
			keyPtr = new int[lvl4Size];
			makeKeysAs(keyPtr, lvl4Size);
			makeKeysAs(testPtr, lvl4Size);
			cout << "The size of test 4: " << lvl4Size << endl;
			results4 = gradeTest(keyPtr, testPtr, lvl4Size, lvl4Size);
			cout << "Percentage report: " << results4 << endl;
			totalPoints = ((results1 * 10) + (results2 * 2) + results3 + (results4 + 10));
			cout << "Total points: " << totalPoints << endl << endl;			
			level4Vec.push_back(rosterPtr[5]);
			delete[] testPtr;
			delete[] keyPtr;
			testPtr = nullptr;
			keyPtr = nullptr;
		}
		else
		{
			cout << "Not Advancing after level 2." << endl;
			totalPoints = ((results1 * 10) + (results2 * 2));
			cout << "Total Points: " << totalPoints << endl << endl;			
			results1 = 0, results2 = 0;
			delete[] testPtr;
			testPtr = nullptr;
		}
	}
	else
	{
		cout << "Not advancing after level 1....." << endl;
		level1Vec.push_back(rosterPtr[5]);
		totalPoints = (results1 * 10);
		cout << "Total points: " << totalPoints << endl << endl;		
		results1 = 0;
	}
	outfile << rosterPtr[5] << " " << totalPoints << endl;
	totalPoints = 0;

	makeKeysAs(tst1stu7, LVL1_SIZE);
	results1 = gradeTest(lvl1KeyArr, tst1stu7, LVL1_SIZE, LVL1_SIZE);
	cout << rosterPtr[6] << " is taking the test...." << endl;
	cout << "Percentage Report: " << (results1 * 10) << endl;
	if ((results1 * 10) >= 50)
	{
		cout << "Advancing to level 2....." << endl;
		level2Vec.push_back(rosterPtr[6]);
		testPtr = new int[LVL2_SIZE];
		makeKeysAs(testPtr, LVL2_SIZE);
		results2 = gradeTest(lvl2KeyArr, testPtr, LVL2_SIZE, LVL2_SIZE);
		cout << "Percentage report: " << (results2 * 2) << endl;
		if ((results2 * 2) >= 20)
		{
			cout << "Advancing to level 3....." << endl;
			level3Vec.push_back(rosterPtr[6]);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[LVL3_SIZE];
			makeKeysAs(testPtr, LVL3_SIZE);
			results3 = gradeTest(lvl3KeyArr, testPtr, LVL3_SIZE, LVL3_SIZE);
			cout << "Percentage report: " << results3 << endl;
			lvl4Size = (results3 * .1);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[lvl4Size];
			keyPtr = new int[lvl4Size];
			makeKeysAs(keyPtr, lvl4Size);
			makeKeysAs(testPtr, lvl4Size);
			cout << "The size of test 4: " << lvl4Size << endl;
			results4 = gradeTest(keyPtr, testPtr, lvl4Size, lvl4Size);
			cout << "Percentage report: " << results4 << endl;
			totalPoints = ((results1 * 10) + (results2 * 2) + results3 + (results4 + 10));
			cout << "Total points: " << totalPoints << endl << endl;			
			level4Vec.push_back(rosterPtr[6]);
			delete[] testPtr;
			delete[] keyPtr;
			testPtr = nullptr;
			keyPtr = nullptr;
		}
		else
		{
			cout << "Not Advancing after level 2." << endl;
			totalPoints = ((results1 * 10) + (results2 * 2));
			cout << "Total Points: " << totalPoints << endl << endl;			
			results1 = 0, results2 = 0;
			delete[] testPtr;
			testPtr = nullptr;
		}
	}
	else
	{
		cout << "Not advancing after level 1....." << endl;
		level1Vec.push_back(rosterPtr[6]);
		totalPoints = (results1 * 10);
		cout << "Total points: " << totalPoints << endl << endl;		
		results1 = 0;
	}
	outfile << rosterPtr[6] << " " << totalPoints << endl;
	totalPoints = 0;

	makeKeysAs(tst1stu8, LVL1_SIZE);
	results1 = gradeTest(lvl1KeyArr, tst1stu8, LVL1_SIZE, LVL1_SIZE);
	cout << rosterPtr[7] << " is taking the test...." << endl;
	cout << "Percentage Report: " << (results1 * 10) << endl;
	if ((results1 * 10) >= 50)
	{
		cout << "Advancing to level 2....." << endl;
		level2Vec.push_back(rosterPtr[7]);
		testPtr = new int[LVL2_SIZE];
		makeKeysAs(testPtr, LVL2_SIZE);
		results2 = gradeTest(lvl2KeyArr, testPtr, LVL2_SIZE, LVL2_SIZE);
		cout << "Percentage report: " << (results2 * 2) << endl;
		if ((results2 * 2) >= 20)
		{
			cout << "Advancing to level 3....." << endl;
			level3Vec.push_back(rosterPtr[7]);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[LVL3_SIZE];
			makeKeysAs(testPtr, LVL3_SIZE);
			results3 = gradeTest(lvl3KeyArr, testPtr, LVL3_SIZE, LVL3_SIZE);
			cout << "Percentage report: " << results3 << endl;
			lvl4Size = (results3 * .1);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[lvl4Size];
			keyPtr = new int[lvl4Size];
			makeKeysAs(keyPtr, lvl4Size);
			makeKeysAs(testPtr, lvl4Size);
			cout << "The size of test 4: " << lvl4Size << endl;
			results4 = gradeTest(keyPtr, testPtr, lvl4Size, lvl4Size);
			cout << "Percentage report: " << results4 << endl;
			totalPoints = ((results1 * 10) + (results2 * 2) + results3 + (results4 + 10));
			cout << "Total points: " << totalPoints << endl << endl;			
			level4Vec.push_back(rosterPtr[7]);
			delete[] testPtr;
			delete[] keyPtr;
			testPtr = nullptr;
			keyPtr = nullptr;
		}
		else
		{
			cout << "Not Advancing after level 2." << endl;
			totalPoints = ((results1 * 10) + (results2 * 2));
			cout << "Total Points: " << totalPoints << endl << endl;			
			results1 = 0, results2 = 0;
			delete[] testPtr;
			testPtr = nullptr;
		}
	}
	else
	{
		cout << "Not advancing after level 1....." << endl;
		level1Vec.push_back(rosterPtr[7]);
		totalPoints = (results1 * 10);
		cout << "Total points: " << totalPoints << endl << endl;		
		results1 = 0;
	}
	outfile << rosterPtr[7] << " " << totalPoints << endl;
	totalPoints = 0;

	makeKeysAs(tst1stu9, LVL1_SIZE);
	results1 = gradeTest(lvl1KeyArr, tst1stu9, LVL1_SIZE, LVL1_SIZE);
	cout << rosterPtr[8] << " is taking the test...." << endl;
	cout << "Percentage Report: " << (results1 * 10) << endl;
	if ((results1 * 10) >= 50)
	{
		cout << "Advancing to level 2....." << endl;
		level2Vec.push_back(rosterPtr[8]);
		testPtr = new int[LVL2_SIZE];
		makeKeysAs(testPtr, LVL2_SIZE);
		results2 = gradeTest(lvl2KeyArr, testPtr, LVL2_SIZE, LVL2_SIZE);
		cout << "Percentage report: " << (results2 * 2) << endl;
		if ((results2 * 2) >= 20)
		{
			cout << "Advancing to level 3....." << endl;
			level3Vec.push_back(rosterPtr[8]);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[LVL3_SIZE];
			makeKeysAs(testPtr, LVL3_SIZE);
			results3 = gradeTest(lvl3KeyArr, testPtr, LVL3_SIZE, LVL3_SIZE);
			cout << "Percentage report: " << results3 << endl;
			lvl4Size = (results3 * .1);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[lvl4Size];
			keyPtr = new int[lvl4Size];
			makeKeysAs(keyPtr, lvl4Size);
			makeKeysAs(testPtr, lvl4Size);
			cout << "The size of test 4: " << lvl4Size << endl;
			results4 = gradeTest(keyPtr, testPtr, lvl4Size, lvl4Size);
			cout << "Percentage report: " << results4 << endl;
			totalPoints = ((results1 * 10) + (results2 * 2) + results3 + (results4 + 10));
			cout << "Total points: " << totalPoints << endl << endl;			
			level4Vec.push_back(rosterPtr[8]);
			delete[] testPtr;
			delete[] keyPtr;
			testPtr = nullptr;
			keyPtr = nullptr;
		}
		else
		{
			cout << "Not Advancing after level 2." << endl;
			totalPoints = ((results1 * 10) + (results2 * 2));
			cout << "Total Points: " << totalPoints << endl << endl;			
			results1 = 0, results2 = 0;
			delete[] testPtr;
			testPtr = nullptr;
		}
	}
	else
	{
		cout << "Not advancing after level 1....." << endl;
		level1Vec.push_back(rosterPtr[8]);
		totalPoints = (results1 * 10);
		cout << "Total points: " << totalPoints << endl << endl;		
		results1 = 0;
	}
	outfile << rosterPtr[8] << " " << totalPoints << endl;
	totalPoints = 0;

	makeKeysAs(tst1stu10, LVL1_SIZE);
	results1 = gradeTest(lvl1KeyArr, tst1stu10, LVL1_SIZE, LVL1_SIZE);
	cout << rosterPtr[9] << " is taking the test...." << endl;
	cout << "Percentage Report: " << (results1 * 10) << endl;
	if ((results1 * 10) >= 50)
	{
		cout << "Advancing to level 2....." << endl;
		level2Vec.push_back(rosterPtr[9]);
		testPtr = new int[LVL2_SIZE];
		makeKeysAs(testPtr, LVL2_SIZE);
		results2 = gradeTest(lvl2KeyArr, testPtr, LVL2_SIZE, LVL2_SIZE);
		cout << "Percentage report: " << (results2 * 2) << endl;
		if ((results2 * 2) >= 20)
		{
			cout << "Advancing to level 3....." << endl;
			level3Vec.push_back(rosterPtr[9]);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[LVL3_SIZE];
			makeKeysAs(testPtr, LVL3_SIZE);
			results3 = gradeTest(lvl3KeyArr, testPtr, LVL3_SIZE, LVL3_SIZE);
			cout << "Percentage report: " << results3 << endl;
			lvl4Size = (results3 * .1);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[lvl4Size];
			keyPtr = new int[lvl4Size];
			makeKeysAs(keyPtr, lvl4Size);
			makeKeysAs(testPtr, lvl4Size);
			cout << "The size of test 4: " << lvl4Size << endl;
			results4 = gradeTest(keyPtr, testPtr, lvl4Size, lvl4Size);
			cout << "Percentage report: " << results4 << endl;
			totalPoints = ((results1 * 10) + (results2 * 2) + results3 + (results4 + 10));
			cout << "Total points: " << totalPoints << endl << endl;			
			level4Vec.push_back(rosterPtr[9]);
			delete[] testPtr;
			delete[] keyPtr;
			testPtr = nullptr;
			keyPtr = nullptr;
		}
		else
		{
			cout << "Not Advancing after level 2." << endl;
			totalPoints = ((results1 * 10) + (results2 * 2));
			cout << "Total Points: " << totalPoints << endl << endl;			
			results1 = 0, results2 = 0;
			delete[] testPtr;
			testPtr = nullptr;
		}
	}
	else
	{
		cout << "Not advancing after level 1....." << endl;
		level1Vec.push_back(rosterPtr[9]);
		totalPoints = (results1 * 10);
		cout << "Total points: " << totalPoints << endl << endl;		
		results1 = 0;
	}
	outfile << rosterPtr[9] << " " << totalPoints << endl;
	totalPoints = 0;

	makeKeysAs(tst1stu11, LVL1_SIZE);
	results1 = gradeTest(lvl1KeyArr, tst1stu11, LVL1_SIZE, LVL1_SIZE);
	cout << rosterPtr[10] << " is taking the test...." << endl;
	cout << "Percentage Report: " << (results1 * 10) << endl;
	if ((results1 * 10) >= 50)
	{
		cout << "Advancing to level 2....." << endl;
		level2Vec.push_back(rosterPtr[10]);
		testPtr = new int[LVL2_SIZE];
		makeKeysAs(testPtr, LVL2_SIZE);
		results2 = gradeTest(lvl2KeyArr, testPtr, LVL2_SIZE, LVL2_SIZE);
		cout << "Percentage report: " << (results2 * 2) << endl;
		if ((results2 * 2) >= 20)
		{
			cout << "Advancing to level 3....." << endl;
			level3Vec.push_back(rosterPtr[10]);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[LVL3_SIZE];
			makeKeysAs(testPtr, LVL3_SIZE);
			results3 = gradeTest(lvl3KeyArr, testPtr, LVL3_SIZE, LVL3_SIZE);
			cout << "Percentage report: " << results3 << endl;
			lvl4Size = (results3 * .1);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[lvl4Size];
			keyPtr = new int[lvl4Size];
			makeKeysAs(keyPtr, lvl4Size);
			makeKeysAs(testPtr, lvl4Size);
			cout << "The size of test 4: " << lvl4Size << endl;
			results4 = gradeTest(keyPtr, testPtr, lvl4Size, lvl4Size);
			cout << "Percentage report: " << results4 << endl;
			totalPoints = ((results1 * 10) + (results2 * 2) + results3 + (results4 + 10));
			cout << "Total points: " << totalPoints << endl << endl;			
			level4Vec.push_back(rosterPtr[10]);
			delete[] testPtr;
			delete[] keyPtr;
			testPtr = nullptr;
			keyPtr = nullptr;
		}
		else
		{
			cout << "Not Advancing after level 2." << endl;
			totalPoints = ((results1 * 10) + (results2 * 2));
			cout << "Total Points: " << totalPoints << endl << endl;			
			results1 = 0, results2 = 0;
			delete[] testPtr;
			testPtr = nullptr;
		}
	}
	else
	{
		cout << "Not advancing after level 1....." << endl;
		level1Vec.push_back(rosterPtr[10]);
		totalPoints = (results1 * 10);
		cout << "Total points: " << totalPoints << endl << endl;		
		results1 = 0;
	}
	outfile << rosterPtr[10] << " " << totalPoints << endl;
	totalPoints = 0;

	makeKeysAs(tst1stu12, LVL1_SIZE);
	results1 = gradeTest(lvl1KeyArr, tst1stu12, LVL1_SIZE, LVL1_SIZE);
	cout << rosterPtr[11] << " is taking the test...." << endl;
	cout << "Percentage Report: " << (results1 * 10) << endl;
	if ((results1 * 10) >= 50)
	{
		cout << "Advancing to level 2....." << endl;
		level2Vec.push_back(rosterPtr[11]);
		testPtr = new int[LVL2_SIZE];
		makeKeysAs(testPtr, LVL2_SIZE);
		results2 = gradeTest(lvl2KeyArr, testPtr, LVL2_SIZE, LVL2_SIZE);
		cout << "Percentage report: " << (results2 * 2) << endl;
		if ((results2 * 2) >= 20)
		{
			cout << "Advancing to level 3....." << endl;
			level3Vec.push_back(rosterPtr[11]);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[LVL3_SIZE];
			makeKeysAs(testPtr, LVL3_SIZE);
			results3 = gradeTest(lvl3KeyArr, testPtr, LVL3_SIZE, LVL3_SIZE);
			cout << "Percentage report: " << results3 << endl;
			lvl4Size = (results3 * .1);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[lvl4Size];
			keyPtr = new int[lvl4Size];
			makeKeysAs(keyPtr, lvl4Size);
			makeKeysAs(testPtr, lvl4Size);
			cout << "The size of test 4: " << lvl4Size << endl;
			results4 = gradeTest(keyPtr, testPtr, lvl4Size, lvl4Size);
			cout << "Percentage report: " << results4 << endl;
			totalPoints = ((results1 * 10) + (results2 * 2) + results3 + (results4 + 10));
			cout << "Total points: " << totalPoints << endl << endl;			
			level4Vec.push_back(rosterPtr[11]);
			delete[] testPtr;
			delete[] keyPtr;
			testPtr = nullptr;
			keyPtr = nullptr;
		}
		else
		{
			cout << "Not Advancing after level 2." << endl;
			totalPoints = ((results1 * 10) + (results2 * 2));
			cout << "Total Points: " << totalPoints << endl << endl;			
			results1 = 0, results2 = 0;
			delete[] testPtr;
			testPtr = nullptr;
		}
	}
	else
	{
		cout << "Not advancing after level 1....." << endl;
		level1Vec.push_back(rosterPtr[11]);
		totalPoints = (results1 * 10);
		cout << "Total points: " << totalPoints << endl << endl;		
		results1 = 0;
	}
	outfile << rosterPtr[11] << " " << totalPoints << endl;
	totalPoints = 0;

	makeKeysAs(tst1stu13, LVL1_SIZE);
	results1 = gradeTest(lvl1KeyArr, tst1stu13, LVL1_SIZE, LVL1_SIZE);
	cout << rosterPtr[12] << " is taking the test...." << endl;
	cout << "Percentage Report: " << (results1 * 10) << endl;
	if ((results1 * 10) >= 50)
	{
		cout << "Advancing to level 2....." << endl;
		level2Vec.push_back(rosterPtr[12]);
		testPtr = new int[LVL2_SIZE];
		makeKeysAs(testPtr, LVL2_SIZE);
		results2 = gradeTest(lvl2KeyArr, testPtr, LVL2_SIZE, LVL2_SIZE);
		cout << "Percentage report: " << (results2 * 2) << endl;
		if ((results2 * 2) >= 20)
		{
			cout << "Advancing to level 3....." << endl;
			level3Vec.push_back(rosterPtr[12]);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[LVL3_SIZE];
			makeKeysAs(testPtr, LVL3_SIZE);
			results3 = gradeTest(lvl3KeyArr, testPtr, LVL3_SIZE, LVL3_SIZE);
			cout << "Percentage report: " << results3 << endl;
			lvl4Size = (results3 * .1);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[lvl4Size];
			keyPtr = new int[lvl4Size];
			makeKeysAs(keyPtr, lvl4Size);
			makeKeysAs(testPtr, lvl4Size);
			cout << "The size of test 4: " << lvl4Size << endl;
			results4 = gradeTest(keyPtr, testPtr, lvl4Size, lvl4Size);
			cout << "Percentage report: " << results4 << endl;
			totalPoints = ((results1 * 10) + (results2 * 2) + results3 + (results4 + 10));
			cout << "Total points: " << totalPoints << endl << endl;			
			level4Vec.push_back(rosterPtr[12]);
			delete[] testPtr;
			delete[] keyPtr;
			testPtr = nullptr;
			keyPtr = nullptr;
		}
		else
		{
			cout << "Not Advancing after level 2." << endl;
			totalPoints = ((results1 * 10) + (results2 * 2));
			cout << "Total Points: " << totalPoints << endl << endl;			
			results1 = 0, results2 = 0;
			delete[] testPtr;
			testPtr = nullptr;
		}
	}
	else
	{
		cout << "Not advancing after level 1....." << endl;
		level1Vec.push_back(rosterPtr[12]);
		totalPoints = (results1 * 10);
		cout << "Total points: " << totalPoints << endl << endl;		
		results1 = 0;
	}
	outfile << rosterPtr[12] << " " << totalPoints << endl;
	totalPoints = 0;

	makeKeysAs(tst1stu14, LVL1_SIZE);
	results1 = gradeTest(lvl1KeyArr, tst1stu14, LVL1_SIZE, LVL1_SIZE);
	cout << rosterPtr[13] << " is taking the test...." << endl;
	cout << "Percentage Report: " << (results1 * 10) << endl;
	if ((results1 * 10) >= 50)
	{
		cout << "Advancing to level 2....." << endl;
		level2Vec.push_back(rosterPtr[13]);
		testPtr = new int[LVL2_SIZE];
		makeKeysAs(testPtr, LVL2_SIZE);
		results2 = gradeTest(lvl2KeyArr, testPtr, LVL2_SIZE, LVL2_SIZE);
		cout << "Percentage report: " << (results2 * 2) << endl;
		if ((results2 * 2) >= 20)
		{
			cout << "Advancing to level 3....." << endl;
			level3Vec.push_back(rosterPtr[13]);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[LVL3_SIZE];
			makeKeysAs(testPtr, LVL3_SIZE);
			results3 = gradeTest(lvl3KeyArr, testPtr, LVL3_SIZE, LVL3_SIZE);
			cout << "Percentage report: " << results3 << endl;
			lvl4Size = (results3 * .1);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[lvl4Size];
			keyPtr = new int[lvl4Size];
			makeKeysAs(keyPtr, lvl4Size);
			makeKeysAs(testPtr, lvl4Size);
			cout << "The size of test 4: " << lvl4Size << endl;
			results4 = gradeTest(keyPtr, testPtr, lvl4Size, lvl4Size);
			cout << "Percentage report: " << results4 << endl;
			totalPoints = ((results1 * 10) + (results2 * 2) + results3 + (results4 + 10));
			cout << "Total points: " << totalPoints << endl << endl;			
			level4Vec.push_back(rosterPtr[13]);
			delete[] testPtr;
			delete[] keyPtr;
			testPtr = nullptr;
			keyPtr = nullptr;
		}
		else
		{
			cout << "Not Advancing after level 2." << endl;
			totalPoints = ((results1 * 10) + (results2 * 2));
			cout << "Total Points: " << totalPoints << endl << endl;			
			results1 = 0, results2 = 0;
			delete[] testPtr;
			testPtr = nullptr;
		}
	}
	else
	{
		cout << "Not advancing after level 1....." << endl;
		level1Vec.push_back(rosterPtr[13]);
		totalPoints = (results1 * 10);
		cout << "Total points: " << totalPoints << endl << endl;		
		results1 = 0;
	}
	outfile << rosterPtr[13] << " " << totalPoints << endl;
	totalPoints = 0;

	makeKeysAs(tst1stu15, LVL1_SIZE);
	results1 = gradeTest(lvl1KeyArr, tst1stu15, LVL1_SIZE, LVL1_SIZE);
	cout << rosterPtr[14] << " is taking the test...." << endl;
	cout << "Percentage Report: " << (results1 * 10) << endl;
	if ((results1 * 10) >= 50)
	{
		cout << "Advancing to level 2....." << endl;
		level2Vec.push_back(rosterPtr[14]);
		testPtr = new int[LVL2_SIZE];
		makeKeysAs(testPtr, LVL2_SIZE);
		results2 = gradeTest(lvl2KeyArr, testPtr, LVL2_SIZE, LVL2_SIZE);
		cout << "Percentage report: " << (results2 * 2) << endl;
		if ((results2 * 2) >= 20)
		{
			cout << "Advancing to level 3....." << endl;
			level3Vec.push_back(rosterPtr[14]);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[LVL3_SIZE];
			makeKeysAs(testPtr, LVL3_SIZE);
			results3 = gradeTest(lvl3KeyArr, testPtr, LVL3_SIZE, LVL3_SIZE);
			cout << "Percentage report: " << results3 << endl;
			lvl4Size = (results3 * .1);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[lvl4Size];
			keyPtr = new int[lvl4Size];
			makeKeysAs(keyPtr, lvl4Size);
			makeKeysAs(testPtr, lvl4Size);
			cout << "The size of test 4: " << lvl4Size << endl;
			results4 = gradeTest(keyPtr, testPtr, lvl4Size, lvl4Size);
			cout << "Percentage report: " << results4 << endl;
			totalPoints = ((results1 * 10) + (results2 * 2) + results3 + (results4 + 10));
			cout << "Total points: " << totalPoints << endl << endl;			
			level4Vec.push_back(rosterPtr[14]);
			delete[] testPtr;
			delete[] keyPtr;
			testPtr = nullptr;
			keyPtr = nullptr;
		}
		else
		{
			cout << "Not Advancing after level 2." << endl;
			totalPoints = ((results1 * 10) + (results2 * 2));
			cout << "Total Points: " << totalPoints << endl << endl;			
			results1 = 0, results2 = 0;
			delete[] testPtr;
			testPtr = nullptr;
		}
	}
	else
	{
		cout << "Not advancing after level 1....." << endl;
		level1Vec.push_back(rosterPtr[14]);
		totalPoints = (results1 * 10);
		cout << "Total points: " << totalPoints << endl << endl;		
		results1 = 0;
	}
	outfile << rosterPtr[14] << " " << totalPoints << endl;
	totalPoints = 0;

	makeKeysAs(tst1stu16, LVL1_SIZE);
	results1 = gradeTest(lvl1KeyArr, tst1stu16, LVL1_SIZE, LVL1_SIZE);
	cout << rosterPtr[15] << " is taking the test...." << endl;
	cout << "Percentage Report: " << (results1 * 10) << endl;
	if ((results1 * 10) >= 50)
	{
		cout << "Advancing to level 2....." << endl;
		level2Vec.push_back(rosterPtr[15]);
		testPtr = new int[LVL2_SIZE];
		makeKeysAs(testPtr, LVL2_SIZE);
		results2 = gradeTest(lvl2KeyArr, testPtr, LVL2_SIZE, LVL2_SIZE);
		cout << "Percentage report: " << (results2 * 2) << endl;
		if ((results2 * 2) >= 20)
		{
			cout << "Advancing to level 3....." << endl;
			level3Vec.push_back(rosterPtr[15]);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[LVL3_SIZE];
			makeKeysAs(testPtr, LVL3_SIZE);
			results3 = gradeTest(lvl3KeyArr, testPtr, LVL3_SIZE, LVL3_SIZE);
			cout << "Percentage report: " << results3 << endl;
			lvl4Size = (results3 * .1);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[lvl4Size];
			keyPtr = new int[lvl4Size];
			makeKeysAs(keyPtr, lvl4Size);
			makeKeysAs(testPtr, lvl4Size);
			cout << "The size of test 4: " << lvl4Size << endl;
			results4 = gradeTest(keyPtr, testPtr, lvl4Size, lvl4Size);
			cout << "Percentage report: " << results4 << endl;
			totalPoints = ((results1 * 10) + (results2 * 2) + results3 + (results4 + 10));
			cout << "Total points: " << totalPoints << endl << endl;			
			level4Vec.push_back(rosterPtr[15]);
			delete[] testPtr;
			delete[] keyPtr;
			testPtr = nullptr;
			keyPtr = nullptr;
		}
		else
		{
			cout << "Not Advancing after level 2." << endl;
			totalPoints = ((results1 * 10) + (results2 * 2));
			cout << "Total Points: " << totalPoints << endl << endl;			
			results1 = 0, results2 = 0;
			delete[] testPtr;
			testPtr = nullptr;
		}
	}
	else
	{
		cout << "Not advancing after level 1....." << endl;
		level1Vec.push_back(rosterPtr[15]);
		totalPoints = (results1 * 10);
		cout << "Total points: " << totalPoints << endl << endl;		
		results1 = 0;
	}
	outfile << rosterPtr[15] << " " << totalPoints << endl;
	totalPoints = 0;

	makeKeysAs(tst1stu17, LVL1_SIZE);
	results1 = gradeTest(lvl1KeyArr, tst1stu17, LVL1_SIZE, LVL1_SIZE);
	cout << rosterPtr[16] << " is taking the test...." << endl;
	cout << "Percentage Report: " << (results1 * 10) << endl;
	if ((results1 * 10) >= 50)
	{
		cout << "Advancing to level 2....." << endl;
		level2Vec.push_back(rosterPtr[16]);
		testPtr = new int[LVL2_SIZE];
		makeKeysAs(testPtr, LVL2_SIZE);
		results2 = gradeTest(lvl2KeyArr, testPtr, LVL2_SIZE, LVL2_SIZE);
		cout << "Percentage report: " << (results2 * 2) << endl;
		if ((results2 * 2) >= 20)
		{
			cout << "Advancing to level 3....." << endl;
			level3Vec.push_back(rosterPtr[16]);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[LVL3_SIZE];
			makeKeysAs(testPtr, LVL3_SIZE);
			results3 = gradeTest(lvl3KeyArr, testPtr, LVL3_SIZE, LVL3_SIZE);
			cout << "Percentage report: " << results3 << endl;
			lvl4Size = (results3 * .1);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[lvl4Size];
			keyPtr = new int[lvl4Size];
			makeKeysAs(keyPtr, lvl4Size);
			makeKeysAs(testPtr, lvl4Size);
			cout << "The size of test 4: " << lvl4Size << endl;
			results4 = gradeTest(keyPtr, testPtr, lvl4Size, lvl4Size);
			cout << "Percentage report: " << results4 << endl;
			totalPoints = ((results1 * 10) + (results2 * 2) + results3 + (results4 + 10));
			cout << "Total points: " << totalPoints << endl << endl;			
			level4Vec.push_back(rosterPtr[16]);
			delete[] testPtr;
			delete[] keyPtr;
			testPtr = nullptr;
			keyPtr = nullptr;
		}
		else
		{
			cout << "Not Advancing after level 2." << endl;
			totalPoints = ((results1 * 10) + (results2 * 2));
			cout << "Total Points: " << totalPoints << endl << endl;			
			results1 = 0, results2 = 0;
			delete[] testPtr;
			testPtr = nullptr;
		}
	}
	else
	{
		cout << "Not advancing after level 1....." << endl;
		level1Vec.push_back(rosterPtr[16]);
		totalPoints = (results1 * 10);
		cout << "Total points: " << totalPoints << endl << endl;		
		results1 = 0;
	}
	outfile << rosterPtr[16] << " " << totalPoints << endl;
	totalPoints = 0;

	makeKeysAs(tst1stu18, LVL1_SIZE);
	results1 = gradeTest(lvl1KeyArr, tst1stu18, LVL1_SIZE, LVL1_SIZE);
	cout << rosterPtr[17] << " is taking the test...." << endl;
	cout << "Percentage Report: " << (results1 * 10) << endl;
	if ((results1 * 10) >= 50)
	{
		cout << "Advancing to level 2....." << endl;
		level2Vec.push_back(rosterPtr[17]);
		testPtr = new int[LVL2_SIZE];
		makeKeysAs(testPtr, LVL2_SIZE);
		results2 = gradeTest(lvl2KeyArr, testPtr, LVL2_SIZE, LVL2_SIZE);
		cout << "Percentage report: " << (results2 * 2) << endl;
		if ((results2 * 2) >= 20)
		{
			cout << "Advancing to level 3....." << endl;
			level3Vec.push_back(rosterPtr[17]);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[LVL3_SIZE];
			makeKeysAs(testPtr, LVL3_SIZE);
			results3 = gradeTest(lvl3KeyArr, testPtr, LVL3_SIZE, LVL3_SIZE);
			cout << "Percentage report: " << results3 << endl;
			lvl4Size = (results3 * .1);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[lvl4Size];
			keyPtr = new int[lvl4Size];
			makeKeysAs(keyPtr, lvl4Size);
			makeKeysAs(testPtr, lvl4Size);
			cout << "The size of test 4: " << lvl4Size << endl;
			results4 = gradeTest(keyPtr, testPtr, lvl4Size, lvl4Size);
			cout << "Percentage report: " << results4 << endl;
			totalPoints = ((results1 * 10) + (results2 * 2) + results3 + (results4 + 10));
			cout << "Total points: " << totalPoints << endl << endl;			
			level4Vec.push_back(rosterPtr[17]);
			delete[] testPtr;
			delete[] keyPtr;
			testPtr = nullptr;
			keyPtr = nullptr;
		}
		else
		{
			cout << "Not Advancing after level 2." << endl;
			totalPoints = ((results1 * 10) + (results2 * 2));
			cout << "Total Points: " << totalPoints << endl << endl;			
			results1 = 0, results2 = 0;
			delete[] testPtr;
			testPtr = nullptr;
		}
	}
	else
	{
		cout << "Not advancing after level 1....." << endl;
		level1Vec.push_back(rosterPtr[17]);
		totalPoints = (results1 * 10);
		cout << "Total points: " << totalPoints << endl << endl;		
		results1 = 0;
	}
	outfile << rosterPtr[17] << " " << totalPoints << endl;
	totalPoints = 0;

	makeKeysAs(tst1stu19, LVL1_SIZE);
	results1 = gradeTest(lvl1KeyArr, tst1stu19, LVL1_SIZE, LVL1_SIZE);
	cout << rosterPtr[18] << " is taking the test...." << endl;
	cout << "Percentage Report: " << (results1 * 10) << endl;
	if ((results1 * 10) >= 50)
	{
		cout << "Advancing to level 2....." << endl;
		level2Vec.push_back(rosterPtr[18]);
		testPtr = new int[LVL2_SIZE];
		makeKeysAs(testPtr, LVL2_SIZE);
		results2 = gradeTest(lvl2KeyArr, testPtr, LVL2_SIZE, LVL2_SIZE);
		cout << "Percentage report: " << (results2 * 2) << endl;
		if ((results2 * 2) >= 20)
		{
			cout << "Advancing to level 3....." << endl;
			level3Vec.push_back(rosterPtr[18]);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[LVL3_SIZE];
			makeKeysAs(testPtr, LVL3_SIZE);
			results3 = gradeTest(lvl3KeyArr, testPtr, LVL3_SIZE, LVL3_SIZE);
			cout << "Percentage report: " << results3 << endl;
			lvl4Size = (results3 * .1);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[lvl4Size];
			keyPtr = new int[lvl4Size];
			makeKeysAs(keyPtr, lvl4Size);
			makeKeysAs(testPtr, lvl4Size);
			cout << "The size of test 4: " << lvl4Size << endl;
			results4 = gradeTest(keyPtr, testPtr, lvl4Size, lvl4Size);
			cout << "Percentage report: " << results4 << endl;
			totalPoints = ((results1 * 10) + (results2 * 2) + results3 + (results4 + 10));
			cout << "Total points: " << totalPoints << endl << endl;			
			level4Vec.push_back(rosterPtr[18]);
			delete[] testPtr;
			delete[] keyPtr;
			testPtr = nullptr;
			keyPtr = nullptr;
		}
		else
		{
			cout << "Not Advancing after level 2." << endl;
			totalPoints = ((results1 * 10) + (results2 * 2));
			cout << "Total Points: " << totalPoints << endl << endl;			
			results1 = 0, results2 = 0;
			delete[] testPtr;
			testPtr = nullptr;
		}
	}
	else
	{
		cout << "Not advancing after level 1....." << endl;
		level1Vec.push_back(rosterPtr[18]);
		totalPoints = (results1 * 10);
		cout << "Total points: " << totalPoints << endl << endl;		
		results1 = 0;
	}
	outfile << rosterPtr[18] << " " << totalPoints << endl;
	totalPoints = 0;

	makeKeysAs(tst1stu20, LVL1_SIZE);
	results1 = gradeTest(lvl1KeyArr, tst1stu20, LVL1_SIZE, LVL1_SIZE);
	cout << rosterPtr[19] << " is taking the test...." << endl;
	cout << "Percentage Report: " << (results1 * 10) << endl;
	if ((results1 * 10) >= 50)
	{
		cout << "Advancing to level 2....." << endl;
		level2Vec.push_back(rosterPtr[19]);
		testPtr = new int[LVL2_SIZE];
		makeKeysAs(testPtr, LVL2_SIZE);
		results2 = gradeTest(lvl2KeyArr, testPtr, LVL2_SIZE, LVL2_SIZE);
		cout << "Percentage report: " << (results2 * 2) << endl;
		if ((results2 * 2) >= 20)
		{
			cout << "Advancing to level 3....." << endl;
			level3Vec.push_back(rosterPtr[19]);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[LVL3_SIZE];
			makeKeysAs(testPtr, LVL3_SIZE);
			results3 = gradeTest(lvl3KeyArr, testPtr, LVL3_SIZE, LVL3_SIZE);
			cout << "Percentage report: " << results3 << endl;
			lvl4Size = (results3 * .1);
			delete[] testPtr;
			testPtr = nullptr;
			testPtr = new int[lvl4Size];
			keyPtr = new int[lvl4Size];
			makeKeysAs(keyPtr, lvl4Size);
			makeKeysAs(testPtr, lvl4Size);
			cout << "The size of test 4: " << lvl4Size << endl;
			results4 = gradeTest(keyPtr, testPtr, lvl4Size, lvl4Size);
			cout << "Percentage report: " << results4 << endl;
			totalPoints = ((results1 * 10) + (results2 * 2) + results3 + (results4 + 10));
			cout << "Total points: " << totalPoints << endl << endl;			
			level4Vec.push_back(rosterPtr[19]);
			delete[] testPtr;
			delete[] keyPtr;
			testPtr = nullptr;
			keyPtr = nullptr;
		}
		else
		{
			cout << "Not Advancing after level 2." << endl;
			totalPoints = ((results1 * 10) + (results2 * 2));
			cout << "Total Points: " << totalPoints << endl << endl;			
			results1 = 0, results2 = 0;
			delete[] testPtr;
			testPtr = nullptr;
		}
	}
	else
	{
		cout << "Not advancing after level 1....." << endl;
		level1Vec.push_back(rosterPtr[19]);
		totalPoints = (results1 * 10);
		cout << "Total points: " << totalPoints << endl << endl;		
		results1 = 0;
	}
	outfile << rosterPtr[19] << " " << totalPoints << endl;
	totalPoints = 0;

	cout << "The list of students based on the levels they completed the test: " << endl;
	cout << "Level 1: ";
	displayVector(level1Vec);
	cout << "Level 2: ";
	displayVector(level2Vec);
	cout << "Level 3: ";
	displayVector(level3Vec);
	cout << "Level 4: ";
	displayVector(level4Vec);

	infile.close();
	outfile.close();
	rosterPtr = nullptr;
	return 0;
}

//Function Definition

int getRand(int min, int max)
{
	int number = (rand() % (max - min + 1)) + min;
	return number;
}

void makeKeysAs(int* arr, int size)
{
	const int MIN = 1, MAX = 3;

	for (int i = 0; i < size; i++)
		arr[i] = getRand(MIN, MAX);
}

int gradeTest(int* key, int* test, int keySize, int testSize)
{
	int points = 0;
	for (int i = 0; i < keySize; i++)
		if (key[i] == test[i])
			points++;
	return points;
}

void displayVector(vector <string> level)
{
	for (string cell : level)
		cout << "[" << cell << "] ";
	cout << endl;
}
