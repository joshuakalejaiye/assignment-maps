#include "pch.h"
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <string>
#include <fstream>
using namespace std;

const int kLineNum = 9;
const int kIntLength = 9;
const int kMapSize = kIntLength * kLineNum;
const string mediaFolder = "C:/Users/syndr/Documents/";
void ReadAndPrint(ifstream &inputStream, int (&arr)[kLineNum][kIntLength]);
void PrintMenu();
int* BinarySearch(int(&arr)[kLineNum][kIntLength]);


int main()
{
	PrintMenu();
	system("pause");
}

void PrintMenu()
{
	int mapArray[kLineNum][kIntLength];
	int userChoice = 0;
	string textFileName = "map1";
	cout << "         -------Welcome to Assignment:Maps-------" << endl;
	cout << "Enter the corresponding integer to the option you wish to select" << endl;

	while (userChoice != 4)
	{

		cout << endl;
		cout << "		       1. Load a map" << endl;
		cout << "		2. Display the map to screen." << endl;
		cout << "		      3. Mountain Pass." << endl;
		cout << "		    4. Quit the program." << endl;
		cout << "         ----------------------------------------" << endl;
		cout << endl;
		cin >> userChoice;

		switch (userChoice)
		{
		case 1:
		{
			cout << endl;
			cout << "Enter the name of the map you want to load (with the file extension): ";
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
			//([4],[8]) compares with ([+1][s]) one forward, ([-1][s]) one back,
			//([s][-1]) one below and ([s][+1]) one above
			//where s is the same as original index
			//no value is not greater than 8 or less 0

		};
		case 4:
		{
			break;
		}

		}
	}
}
 

void ReadAndPrint(ifstream &inputStream, int (&mapArray)[kLineNum][kIntLength])
{
	if (!inputStream)
	{
		cout << "ERROR: ";
		cout << "Can't open input file\n";
	}
	//inputStream >> noskipws;
	for (int j = kIntLength - 1; j >= 0; j--)
	{
	
		cout << endl;
		for (int i = 0; i < kLineNum; i++)
		{
			if (!inputStream.eof()) 
			{
				inputStream >> mapArray[i][j]; //mapArray[y][x]
				cout << mapArray[i][j] << " "; //mapArray[y][x]
			}
		}

	}
	
	cout << endl << endl;
	inputStream.close();
}

int* BinarySearch (int(&arr)[kLineNum][kIntLength])
{

	return &arr[9][0];
}