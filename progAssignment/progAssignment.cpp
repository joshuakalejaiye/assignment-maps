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
int Traversal(int(&Arr)[kLineNum][kIntLength], int x, int y);
void Translation(int(&Arr)[kLineNum][kIntLength], int(&holderArr)[kLineNum][kIntLength], int operation);

int main()
{
	PrintMenu();
	system("pause");
}

void PrintMenu()
{
	int mapArray[kLineNum][kIntLength];
	int holderArray[kLineNum][kIntLength];
	int userChoice = 0;
	int xPos = 4;
	int yPos = 8;
	string textFileName = "map1";
	cout << "         -------Welcome to Assignment:Maps-------" << endl;
	cout << "Enter the corresponding integer to the option you wish to select" << endl;

	while (userChoice != 4)
	{

		cout << endl;
		cout << "		       1. Load a map" << endl;
		cout << "		2. Display the map to screen." << endl;
		cout << "		      3. Mountain Pass." << endl;
		cout << "        4. Rotate the map by 90 degrees clockwise" << endl;
		cout << "	      5. Reflect the map vertically" << endl;
		cout << "		   6. Quit the program." << endl;
		cout << "         ----------------------------------------" << endl;
		cout << endl;
		cin >> userChoice;
		string filePath = mediaFolder + textFileName + ".txt";
		ifstream infile(filePath);

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
				ReadAndPrint(infile, mapArray);
				break;

			};
			case 3:
			{

				cout << "         ------ Welcome To Mountain Pass ------" << endl;
				ReadAndPrint(infile, mapArray);
				cout << " Where do you want to start ?"  << endl;
				cout << " Type the x co-ordinate below" << endl;
				cin >> xPos;
				cout << " Type the y co-ordinate below" << endl;
				cin >> yPos;
				cout << endl;

				do
				{
					xPos = Traversal(mapArray, xPos, yPos);
					if (yPos - 1 >= 0) yPos--;	
					cout << mapArray[xPos][yPos] << " ";
				} while (yPos > 0);

				break;
			};
			case 4:
			{
				Translation(mapArray, holderArray, 0);
			}
			case 5:
			{
				Translation(mapArray, holderArray, 1);
			}
			case 6:
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
				inputStream >> mapArray[i][j]; //mapArray[x][y]
				cout << mapArray[i][j] << " "; //mapArray[x][y]
			}
		}

	}
	
	cout << endl << endl;
	inputStream.close();
}

int Traversal(int(&Arr)[kLineNum][kIntLength], int x, int y)
{
	if ((x < 0 || x > 8) || (y < 0 || y > 8))
	{
		cout << "please enter a valid coordinate";
		return 0;
	}

	int	minVal = Arr[x][y - 1];
	int xPos = x;
	for (int i = 0; i <= 2; i++)
	{
		if (Arr[x - 1 + i][y - 1] < minVal)
		{
			xPos = x - 1 + i;
			minVal = Arr[xPos][y - 1];
		}

	}
	
	return xPos;
}

void Translation(int(&Arr)[kLineNum][kIntLength], int(&holderArr)[kLineNum][kIntLength], int operation)
{
	const int rot90clockwise  =	0;
	const int reflectVertical = 1;
	const int reflectDiagonal = 2;
	
	switch (operation)
	{
		case rot90clockwise:
		{

		}
		case reflectVertical:
		{

		}
	}
}


