/*
	Title:  Program1.cpp
	Author: Keegan Farkas
	Date:  2/22/2022
	Purpose:  Function defintions for Text class
*/
#include "Text.h"
#include <iostream>
#include <cstring>
using namespace std;

Text::Text(char *text){
	textLength = strlen(text);
	char *temp = new char[textLength + 1];

	strcpy(temp, text);
	
	textArray = temp;
}	

Text::~Text(){
	cout << "Text destructor: Released memory for textArray." << endl;
}

void Text::displayText(){
	cout << textArray;
}

const char *Text::getText(){
	return textArray;
}

int Text::getLength(){
	return textLength;
}