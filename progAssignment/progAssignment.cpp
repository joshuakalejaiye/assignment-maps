#include "pch.h"
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

const int kLineNum = 9;
const int kIntLength = 9;
const int kMapSize = kIntLength * kLineNum;
const string mediaFolder = "C:/Users/syndr/Documents/";
void PrintMenu();
void DisplayLoadedMap(ifstream &inputStream, int(&arr)[kLineNum][kIntLength]);
int Traversal(int(&Arr)[kLineNum][kIntLength], int x, int y);
void Translation(int(&Arr)[kLineNum][kIntLength], int(&holderArr)[kLineNum][kIntLength], int operation, ifstream &inputStream);
void CreateLake(int(&Arr)[kLineNum][kIntLength], int x, int y, int depth, ifstream &inputStream);
void PrintNewMap(int(&Arr)[kLineNum][kIntLength], ifstream &inputStream);
void OnlyLoadMap(int(&Arr)[kLineNum][kIntLength], ifstream &inputStream);
const int Quit = 8;
const int kX = 4;
const int kY = 4;
const int kDepth = 300;
const string kTextFileName = "map2";

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
	cout << "       ---------Welcome to Assignment:Maps---------" << endl;
	cout << "Enter the corresponding integer to the option you wish to select" << endl;

	while (userChoice != Quit)
	{

		cout << endl;
		cout << "		       1. Load a map" << endl;
		cout << "		2. Display the map to screen." << endl;
		cout << "		      3. Mountain Pass." << endl;
		cout << "        4. Rotate the map by 90 degrees clockwise" << endl;
		cout << "	      5. Reflect the map vertically" << endl;
		cout << "	  6. Reflect the map along the diagonal" << endl;
		cout << "	  	     7. Create Lake" << endl;
		cout << "		   8. Quit the program." << endl;
		cout << "       ------------------------------------------" << endl;
		cout << endl;
		cin >> userChoice;
		string filePath = mediaFolder + textFileName + ".txt";
		ifstream infile(filePath);
		if (!(userChoice > 0) && (userChoice <= Quit))
		{	
			cout << endl;
			cout << "Invalid Menu Option Chosen, Closing Program....\n";
			userChoice = Quit;
		}
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
				DisplayLoadedMap(infile, mapArray);
				break;

			};
			case 3:
			{

				cout << "         ------ Welcome To Mountain Pass ------" << endl;
				DisplayLoadedMap(infile, mapArray);
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
				} while (yPos > 0); // when the base of the mountain is reached.

				break;
			};
			case 4:
			{
				Translation(mapArray, holderArray, 0, infile);
				break;
			}
			case 5:
			{
				Translation(mapArray, holderArray, 1, infile);
				break;
			}
			case 6:
			{
				Translation(mapArray, holderArray, 2, infile);
				break;
			}
			case 7:
			{
				cout << endl;
				string textFileName = kTextFileName;
				int x = kX;
				int y = kY;
				int depth = kDepth;

				cout << "Enter the name of the map you would like to load" << endl;
				cin >> textFileName;
				ifstream inputStream(mediaFolder + textFileName + ".txt");
				OnlyLoadMap(mapArray, inputStream);
				cout << endl;

				cout << "Enter x-coordinate: \n";
				if (!(cin >> x)) 
				{
					x = kX;
					cin.clear(); 
				}
				cout << endl;

				cout << "Enter y-coordinate: \n";
				if (!(cin >> y)) 
				{
					y = kY;
					cin.clear();
				}
				cout << endl;

				cout << "Enter depth: \n";
				if (!(cin >> depth))
				{
					depth = kDepth;
					cin.clear();
				}

				CreateLake(mapArray, x, y, depth, inputStream);
				PrintNewMap(mapArray, inputStream);
				break;
			}
			case 8:
			{
				break;
			}

		}
	}
}

void DisplayLoadedMap(ifstream &inputStream, int (&mapArray)[kLineNum][kIntLength])
{
	if (!inputStream)
	{
		cout << "ERROR: ";
		cout << "Can't open input file\n";
	}

	for (int j = kIntLength - 1; j >= 0; j--)
	{
	
		cout << endl;
		for (int i = 0; i < kLineNum; i++)
		{
			if (!inputStream.eof()) 
			{
				inputStream >> mapArray[i][j]; //mapArray[x][y]
				if (mapArray[i][j] == 0) cout << "000" << " ";
				else cout << mapArray[i][j] << " "; 

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

void Translation(int(&Arr)[kLineNum][kIntLength], int(&holderArr)[kLineNum][kIntLength], int operation, ifstream &inputStream)
{
	const int rot90clockwise  =	0;
	const int reflectVertical = 1;
	const int reflectDiagonal = 2;
	
	OnlyLoadMap(Arr, inputStream);

	switch (operation)
	{
		case rot90clockwise:
		{

			for (int i = 0; i < kLineNum; i++)
			{
				for (int j = 0; j < kIntLength; j++)
				{
					holderArr[i][j] = Arr[j][i];
				}
			}

			for (int i = 0; i < kLineNum; i++)
			{
				for (int j = 0; j < kIntLength; j++)
				{
					Arr[i][j] = holderArr[i][j];
				}
			}

			break;
		}
		case reflectVertical:
		{
			for (int i = 0; i < kLineNum; i++)
			{
				for (int j = 0; j < kIntLength; j++)
				{
					holderArr[(kIntLength - 1) - i][j] = Arr[i][j];
				}
			}

			for (int i = 0; i < kLineNum; i++)
			{
				for (int j = 0; j < kIntLength; j++)
				{
					Arr[i][j] = holderArr[i][j];
				}
			}
			break;
		}
		case reflectDiagonal:
		{	

			for (int i = 0; i < kLineNum; i++)
			{
				for (int j = 0; j < kIntLength; j++)
				{
					holderArr[(kIntLength - 1) - i][(kLineNum - 1) - j] = Arr[i][j];
				}
			}

			for (int i = 0; i < kLineNum; i++)
			{
				for (int j = 0; j < kIntLength; j++)
				{
					Arr[i][j] = holderArr[i][j];
				}
			}

			break;
		}
	}
	
	PrintNewMap(Arr, inputStream);

	cout << endl << endl;
	inputStream.close();
}

void OnlyLoadMap(int(&Arr)[kLineNum][kIntLength], ifstream &inputStream)
{
	for (int j = kIntLength - 1; j >= 0; j--)
	{
		for (int i = 0; i < kLineNum; i++)
		{
			if (!inputStream.eof())
			{
				inputStream >> Arr[i][j]; //mapArray[x][y]
			}
		}

	}
}

void PrintNewMap(int(&Arr)[kLineNum][kIntLength], ifstream &inputStream)
{

	for (int j = kIntLength - 1; j >= 0; j--)
	{
		cout << endl;
		for (int i = 0; i < kLineNum; i++)
		{
			if (!inputStream.eof())
			{
				if (Arr[i][j] == 0) cout << "000" << " ";
				else cout << Arr[i][j] << " ";
				
			}
		}

	}

	cout << endl;
}

void CreateLake(int(&Arr)[kLineNum][kIntLength], int x, int y, int depth, ifstream &inputStream)
{
	if (x >= 9 ||  y>= 9) return;
	if (x < 0 || y < 0) return;
	if (Arr[x][y] == 000) return;
	if (Arr[x][y] < depth)
	{
		Arr[x][y] = 000;
		CreateLake(Arr, x - 1, y - 1, depth, inputStream);
		CreateLake(Arr, x - 1, y, depth, inputStream);
		CreateLake(Arr, x - 1, y + 1, depth, inputStream);
		CreateLake(Arr, x, y - 1, depth, inputStream);
		CreateLake(Arr, x, y + 1, depth, inputStream);
		CreateLake(Arr, x + 1, y - 1, depth, inputStream);
		CreateLake(Arr, x + 1, y, depth, inputStream);
		CreateLake(Arr, x + 1, y + 1, depth, inputStream);
	}
}

