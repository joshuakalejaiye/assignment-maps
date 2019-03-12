#include "pch.h"
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <string>
#include <fstream>
using namespace std;

const int kLineNum = 18;
const int kGroupSize = 3;
const int kMapSize = kGroupSize * kLineNum;
void ReadAndPrint(ifstream &inputStream, int (&arr)[kLineNum][kGroupSize]);
void PrintMenu();

const string mediaFolder = "C:/Users/syndr/Documents/";

int main()
{
	PrintMenu();
	system("pause");
}

void PrintMenu()
{
	int mapArray[kLineNum][kGroupSize];
	int choice = 0;
	string textFileName = "map1";
	cout << "         -------Welcome to Assignment:Maps-------" << endl;
	cout << "Enter the corresponding integer to the option you wish to select" << endl;

	while (choice != 4)
	{

		cout << endl;
		cout << "		       1. Load a map" << endl;
		cout << "		2. Display the map to screen." << endl;
		cout << "		      3. Mountain Pass." << endl;
		cout << "		    4. Quit the program." << endl;
		cout << "         ----------------------------------------" << endl;
		cout << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Enter the name of the map you want to load (with the file extension)" << endl;
			cin >> textFileName;
			cout << endl;
			break;
		}
		case 2:
		{
			cout << endl;
			string filePath = mediaFolder + textFileName + ".txt";
			ifstream infile(filePath);

			ReadAndPrint(infile, mapArray);
			break;

		};
		case 3:
		{

		};
		case 4:
		{
			break;
		}

		}
	}
}

void ReadAndPrint(ifstream &inputStream, int (&arr)[kLineNum][kGroupSize])
{
	int charNum = 0;
	int ThreeNumPerLine = 0;
	if (!inputStream)
	{
		cout << "ERROR: ";
		cout << "Can't open input file\n";
	}
	int LinesPerGrid = 0;
	int LineNo = 8;
	//inputStream >> noskipws;

	while (!inputStream.eof())
	{
		charNum++;
		ThreeNumPerLine++;
		char ch;
		int arr[kMapSize];
		inputStream >> arr[LineNo][LinesPerGrid]; // not sure why this doesnt work but ok
		if (!inputStream.eof())
		{
			cout << arr[LineNo][LinesPerGrid] << " "; //not sure why this doesnt work but ok sure
		
		}

		if (ThreeNumPerLine >= 9)
		{
			LinesPerGrid++;
			LineNo--;
			cout << endl;
			ThreeNumPerLine = 0;
		}

		if (LinesPerGrid == 3)
		{
			cout << endl;
			LinesPerGrid = 0;
		}
		
	}

	inputStream.close();
}