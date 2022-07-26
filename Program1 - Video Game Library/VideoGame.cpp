/*
	Title:  Program1.cpp
	Author: Keegan Farkas
	Date:  2/22/2022
	Purpose:  Function definitions for VideoGame class
*/
#include "VideoGame.h"
#include "Text.h"
#include <iostream>
#include <fstream>
using namespace std;

VideoGame::VideoGame(Text *t, Text *d, Text *p, int y){ 
	title = t;
	developer = d;
	publisher = p;
	year = y;
}

VideoGame::~VideoGame(){
	delete this->title;
	delete this->developer;
	delete this->publisher;
	cout << "VideoGame destructor: Released memory for VideoGame object." << endl;
}

void VideoGame::printVideoGameDetails(){
	cout << "\t\t   Game Title:  ";
	title->displayText();
	cout << endl;
	cout << "\t\t    Developer:  ";
	developer->displayText();
	cout << endl;
	cout << "\t\t    Publisher:  ";
	publisher->displayText();
	cout << endl;
	cout << "\t\tYear Released:  " << year << "\n\n\n";
}

void VideoGame::printVideoGameDetailsToFile(ofstream &outputFile){
	outputFile << title->getText() << endl;
	outputFile << developer->getText() << endl;
	outputFile << publisher->getText() << endl;
	outputFile << year << endl;
}

Text *VideoGame::getVideoGameTitle(){
	return title;
}