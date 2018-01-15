#include "stdafx.h"
#include "mainClass.h"
#include "correctiveFunctions.h"

mainClass::mainClass()
{
	start();
}

mainClass::~mainClass()
{
	file.coleFile();
}

void mainClass::writeToFile()
{
	do {
		cout << "operation on text ended, now file is ready to save\n";
		cout << "you have two options: \n";
		cout << "1. Write to this same file waht you send\n";
		cout << "2. Write to difrent file than this one\n";
		int x;
		cin >> x;
		if (x == 1) {
			file.writeToFile(file.getFileName(), theLastConntent);
		}
		else if (x == 2) {
			string name;
			cout << "Write the name for the file:";
			cin >> name;
			file.writeToFile(name+".txt", theLastConntent);
		}
		else {
			system("clear");
			cout << "WRONG NUMBER!!!\n";
			continue;
		}
	} while (0);
	
}

//some options in program like change theme
void mainClass::options()
{

}

//this function is for set file name at the begining
void mainClass::setFileName()
{
	cout << "write path and name of file " << endl;
	string filex;
	cin >> filex;
	file.setFileName(filex);
}

void mainClass::getLinesFromFile(string s)
{
	linesFromFile = file.returnLinesFromFile(s);
}

void mainClass::start()
{
	cout << "Welcome !!!\nWe Want to help you to put Comma in the right place for you" << endl;
	setFileName();
	getLinesFromFile(file.getFileName());
	collectTheLastConntent();
	writeToFile();
}

//erase theLastConntent variable and put there content from vector<string> with lines of file
void mainClass::collectTheLastConntent()
{
	theLastConntent = "";
	for (auto & x : linesFromFile) {
		theLastConntent += x;
	}
}
