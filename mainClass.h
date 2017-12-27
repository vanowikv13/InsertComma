#pragma once
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
	void setFileName();
	void getLinesFromFile(string s);
	void writeToNewFile(); /// after+"name file from the begin".txt
	void writeToThisSameFile();
	void start();
protected:
	fileStream file;
	vector<string> linesFromFile;
	string theLastConntent;
};

