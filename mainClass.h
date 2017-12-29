#pragma once
#ifndef MAIN_CLASS_H
#define MAIN_CLASS_H
#include <string>
#include <vector>
#include <iostream>
#include "fileStream.h"

using namespace std;

class mainClass
{
public:
	mainClass();
	~mainClass();
	//options about correction in text
	void writeToFile();
	//chose what correction do you want
	void options();
	//set name of the file what we will work
	void setFileName();
	void getLinesFromFile(string s);
	void start();
	void collectTheLastConntent();
protected:
	fileStream file;
	vector<string> linesFromFile;
	string theLastConntent;
};

#endif