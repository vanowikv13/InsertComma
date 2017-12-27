#include "stdafx.h"
#include "mainClass.h"


mainClass::mainClass()
{
	start();
}


mainClass::~mainClass()
{
}

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

void mainClass::writeToNewFile()
{
	file.writeToFile("new"+file.getFileName(), theLastConntent);
}

void mainClass::writeToThisSameFile()
{
	file.writeToFile(file.getFileName(), theLastConntent);
}

void mainClass::start()
{
	cout << "Welcome !!!\nWe Want to help you to put Comma in the right place for you" << endl;
	setFileName();
	getLinesFromFile(file.getFileName());
	writeToNewFile();
}
