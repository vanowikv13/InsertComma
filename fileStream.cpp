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
		EXIT_FAILURE;
		return false;
	}
	return true;
}

void fileStream::connectToFile(string f, bool toRead)
{
	if (file.is_open())
		file.close();

	if (toRead) {
		file.open(f, ios::in);
		checkIfFileOpen();
		this->fileName = f;
	}
	else
		file.open(f, ios::out | ios::trunc);

}

//return the whole file .txt in vector
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


void fileStream::writeToFile(string f, string text)
{
	connectToFile(f,false);
	file << text;
	MessageBoxW(
		NULL,
		L"Communication",
		L"Now we write to file", IDOK
	);
}

string fileStream::getFileName()
{
	return fileName;
}

void fileStream::setFileName(string f)
{
	fileName = f;
}
