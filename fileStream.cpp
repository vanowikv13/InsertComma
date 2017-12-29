#include "stdafx.h"
#include "fileStream.h"
#include <Windows.h>
#include <iostream>

fileStream::fileStream()
{
	fileName = "";
}


fileStream::~fileStream()
{
}

bool fileStream::checkIfFileOpen() {
	if (!file.is_open())
	{
		MessageBoxW(
			NULL,
			L"Please check if file exist or if you write good path",
			L"The file isn't open, sorry", IDOK
		);
		MessageBoxW(
			NULL,
			L"Now app will close, please try again",
			L"Sorry for trouble", IDOK
		);
		FatalExit(1);
	}
	return true;
}

void fileStream::connectToFile(string f, bool toRead)
{
	if (file.is_open())
		file.close();
	if (toRead) {
		file.open(f, ios::in);
		this->fileName = f;
	}
	else
		file.open(f, ios::out | ios::trunc);
	checkIfFileOpen();
}

//return the whole file .txt in vector (line by line)
vector<string> fileStream::returnLinesFromFile(string f)
{
	connectToFile(f, true);
	string line;
	vector<string> lines;
	while (getline(file, line)) {
		lines.push_back(line);
	}
	return lines;
}

//write to exist file or new file erasing content
void fileStream::writeToFile(string path, string textToWrite)
{
	connectToFile(path, false);
	file << textToWrite;
	MessageBoxW(
		NULL,
		L"Operation sucessed",
		L"Communication", IDOK
	);
}

void fileStream::coleFile()
{
	if(checkIfFileOpen())
		file.close();
}

string fileStream::getFileName()
{
	return fileName;
}

void fileStream::setFileName(string f)
{
	fileName = f;
}
