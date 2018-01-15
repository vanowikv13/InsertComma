#pragma once
#ifndef CORRECTIVE_FUNCTIONS_H
#define CORRECTIVE_FUNCTIONS_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace correction {

	//this struct is partents for other struct what will be in use
	struct correct {
		correct(string str = "") {
			inUse = true;
			informationAboutStruct = str;
		}
		//this variable is for check if functilality is in use
		bool inUse;
		//basic information about functionality of structure
		string informationAboutStruct;
	};

	struct co : correct {
		co() :correct("Put always comma before this words: bo, ale, gdyż, lecz") {}
	};
	

	/// ------ basic functions -----------------------------------------------

	void writeAboutYou(correct * cor) {
		cout << cor->informationAboutStruct << endl;
	}

	//copy string from x with x to y without y ---> { <x;y) }
	string copyx(int x, int y, string a) {
		string coping = "";
		for (int i = x; i < y; i++)
			coping += a[i];
		return coping;
	}

	//put the comma behind the place (place schould be index to the last letter)
	string putTheCommaInSomePlace(string str, int place) {
		string result;
		///here we need check if there is comma
		int i = place;
		while(true) {
			if (str[i] == ',' || str[i] == '.')
				return str;
			if (str[i] != '\n' || str[i] != ' ')
				i++;
			else
				break; //this is when index is \n or ' '
		}
		//here is put the comma in the right way
		result = copyx(0, i, str) + "," + copyx(i, str.size(), str);
		return result;
	}

	/*
		Basic Information About how schould work first functionality
		1)Programo
	*/

}

#endif // !CORRECTIVE_FUNCTIONS_H