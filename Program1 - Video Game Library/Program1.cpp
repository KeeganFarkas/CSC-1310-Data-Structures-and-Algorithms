/*
	Title:  Program1.cpp
	Author: Keegan Farkas
	Date:  2/22/2022
	Purpose:  
*/
#include "VideoGameLibrary.h"
#include "VideoGame.h"
#include "Text.h"
#include <iostream>
using namespace std;

int main(){
	//Variable declarations
	short userChoice;
	int maxGames;
	char fileName[1000];

	//Creating library
	cout << "How many video games can your library hold?" << endl;
	cin >> maxGames;
	VideoGameLibrary library(maxGames);

	//To make sure the program keeps looping until the user picks choice 6
	do{
		//User options
		cout << "\nWhat would you like to do?" << endl;
		cout << "1.  Load video games from file." << endl;
		cout << "2.  Save video games to a file." << endl;
		cout << "3.  Add a video game." << endl;
		cout << "4.  Remove a video game." << endl;
		cout << "5.  Display all video games." << endl;
		cout << "6.  Remove ALL video games from this library and end the program." << endl;
	
		//Making sure the user chooses a number between 1 and 6
		do{
			cout << "CHOOSE 1-6:  ";
			cin >> userChoice;

			if(userChoice < 1 || userChoice > 6)
				cout << "That is not a valid choice." << endl;				
		}
		while(userChoice < 1 || userChoice > 6);

		//Switch statements
		switch(userChoice){
		
			//If the user chooses to load a video game from a file
			case 1:
				cout << "\nWhat is the name of the file? (example.txt):  ";
				cin >> fileName;
				library.loadVideoGamesFromFile(fileName);
				break;

			//If the user chooses to save video games to a file
			case 2:
				cout << "\nWhat do you want to name the file? (example.txt):  ";
				cin >> fileName;
				library.saveToFile(fileName);
				break;

			//If the user chooses to add a video game
			case 3:
				library.addVideoGameToArray();
				break;

			//If user chooses to remove a video game
			case 4:
				library.removeVideoGameFromArray();
				break;

			//If the user chooses to display all video games
			case 5:
				library.displayVideoGames();
				break;

			//If the user chooses to remove all video games from the library and end the program
			case 6:
				break;
		}	
	}
	while(userChoice != 6);

	return 0;
}