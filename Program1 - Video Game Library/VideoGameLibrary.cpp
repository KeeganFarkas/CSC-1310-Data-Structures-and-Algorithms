/*
	Title:  VideoGamesLibrary.cpp
	Author: Keegan Farkas
	Date:  2/22/2022
	Purpose:  Function definitions for VideoGameLibrary Class
*/
#include "VideoGameLibrary.h"
#include "VideoGame.h"
#include "Text.h"
#include <iostream>
#include <fstream>
using namespace std;

void VideoGameLibrary::resizeVideoGameArray (){
	cout << "Resizing videoGameArray from " << maxGames << " to " << maxGames * 2 << ".\n";
	VideoGame *tempArray[numGames];
	for(int i = 0; i < numGames; i++){
		tempArray[i] = videoGamesArray[i];
	}

	videoGamesArray = new VideoGame*[maxGames * 2];

	for(int i = 0; i < numGames; i++){
		videoGamesArray[i] = tempArray[i];
	}

	maxGames = maxGames * 2;
}

VideoGameLibrary::VideoGameLibrary(int maxGames){
	videoGamesArray = new VideoGame*[maxGames];
	numGames = 0;
	this->maxGames = maxGames;
}

VideoGameLibrary::~VideoGameLibrary(){
	for(int i = 0; i < numGames; i++){
		delete this->videoGamesArray[i];
	}
	cout << "VideoGameLibrary destructor: Released memory for each game in the video game array and the array itself." << endl;
	cout << "\nGOODBYE!";
}

void VideoGameLibrary::addVideoGameToArray(){
	char text[10000];
	int year;

	cout << "\nVideo Game TITLE: ";
	cin.ignore();
	cin.getline(text, 10000);
	Text *title = new Text(text);

	cout << "\nVideo Game DEVELOPER: ";
	cin.getline(text, 10000);
	Text *developer = new Text(text);

	cout << "\nVideo Game PUBLISHER: ";
	cin.getline(text, 10000);
	Text *publisher = new Text(text);

	cout << "\nVideo Game YEAR: ";
	cin >> year;

	VideoGame *game = new VideoGame(title, developer, publisher, year);

	if(numGames == maxGames)
		resizeVideoGameArray();
	
	videoGamesArray[numGames] = game;

	numGames++;
}

void VideoGameLibrary::displayVideoGames(){
	for(int i = 0; i < numGames; i++){
		cout << "\t\t\t----------Video Game " << i + 1 << "----------" << endl;
		videoGamesArray[i]->printVideoGameDetails();
	}
}

void VideoGameLibrary::displayVideoGameTitles(){
	for(int i = 0; i < numGames; i++){
		cout << "Video Game " << i + 1 << ": "; 
		videoGamesArray[i]->getVideoGameTitle()->displayText();
		cout << endl;
	}
}

void VideoGameLibrary::loadVideoGamesFromFile(char * fileName){
	char text [10000] = {"\0"};
	int year, i;

	ifstream inputFile;
	inputFile.open(fileName);

	if(inputFile.is_open()){
		while(inputFile.getline(text, 10000)){
			Text *title = new Text(text);

			inputFile.getline(text, 10000);
			Text *developer = new Text(text);

			inputFile.getline(text, 10000);
			Text *publisher = new Text(text);

			inputFile >> year;
			inputFile.ignore();

			VideoGame *game = new VideoGame(title, developer, publisher, year);

			if(numGames == maxGames)
				resizeVideoGameArray();
	
			videoGamesArray[numGames] = game;

			numGames++;

			title->displayText();
			cout << " was added successfully" << endl;
			i++;
		}
		inputFile.close();
		cout << i << " video games were read from the file and added to your VideoGame library.\n\n";
	}
	else
		cerr << "sorry, I was unable to open the file.";
}

void VideoGameLibrary::removeVideoGameFromArray(){
	if(numGames < 1){
		cout << "There must be at least one game in the video game library.\n\n";
		return;
	}

	int userChoice;

	cout << "\n\nChoose from the following video games to remove:\n\n";
	displayVideoGameTitles();

	do{
		cout << "Choose a video game to remove between 1 & " << numGames << ":  ";
		cin >> userChoice;
		userChoice--;

		if(userChoice < 0 || userChoice > numGames - 1)
			cout << "That is not a valid choice." << endl;
	}
	while(userChoice < 0 || userChoice > numGames - 1);
	
	cout << "\n\nThe video game \"";
	videoGamesArray[userChoice]->getVideoGameTitle()->displayText();
	cout << "\" has been successfully deleted.\n\n";

	delete videoGamesArray[userChoice];

	numGames--;

	for(int i = userChoice; i < numGames; i++){
		videoGamesArray[i] = videoGamesArray[i + 1];
	}
}

void VideoGameLibrary::saveToFile(char *fileName){


	ofstream outputFile;
	outputFile.open(fileName);

	for(int i = 0; i < numGames; i++){
		videoGamesArray[i]->printVideoGameDetailsToFile(outputFile);
	}

	outputFile.close();
	cout << "ALL video games in your library have been printed to " << fileName << endl;
}