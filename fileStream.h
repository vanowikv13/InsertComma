#pragma once
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class fileStream
{
public:
	fileStream();
	~fileStream();
	string getFileName();
	void setFileName(string f);
	//this function connect or reconect to file used flag ios::in and ios::out
	void connectToFile(string f, bool toRead);
	vector<string> returnLinesFromFile(string f);
	void writeToFile(string f, string text);
	void coleFile();
protected:
	bool checkIfFileOpen();
	fstream file;
	string fileName;
};

