#include "pch.h"
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <string>
#include <fstream>
using namespace std;

const int kSIZE = 8;
void ReadAndPrint(ifstream &inputStream);
const string mediaFolder = "C:/Users/syndr/Documents/";

int main()
{
	string textFileName = "input";

	cout << "Enter the name of the map you want to load (with the file extension)" << endl;
	cin >> textFileName;
	cout << endl;

	string filePath = mediaFolder + textFileName + ".txt";
	ifstream infile(filePath);

	ReadAndPrint(infile);
	cout << endl;

	system("pause");
}

void ReadAndPrint(ifstream &inputStream)
{
	if (!inputStream)
	{
		cout << "ERROR: ";
		cout << "Can't open input file\n";
	}

	inputStream >> noskipws;

	while (!inputStream.eof())
	{
		char ch;
		inputStream >> ch;
		if (!inputStream.eof())
		{
			cout << ch;
		}
	}

	inputStream.close();
}