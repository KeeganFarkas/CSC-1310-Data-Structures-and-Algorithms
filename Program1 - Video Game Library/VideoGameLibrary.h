/*
	Title:  VideoGameLibrary.h
	Author: Keegan Farkas
	Date:  2/22/2022
	Purpose:  Header File for VideoGameLibrary class
*/
#ifndef VIDEOGAMELIBRARY_H
#define VIDEOGAMELIBRARY_H
#include "VideoGame.h"
using namespace std;

class VideoGameLibrary{
    private:
    VideoGame** videoGamesArray;
    int maxGames, numGames;
    
    public:
    //Function to double the size of the video game library array
    void resizeVideoGameArray();

    //VideoGameLibrary object constructor
    VideoGameLibrary(int);

    //VideoGameLibrary object destructor
    ~VideoGameLibrary();

    //Function to add a single video game to the library
    void addVideoGameToArray();

    //Function to display the details of all the video games in the library
    void displayVideoGames();

    //Function to display the titles of all the video games in the library
    void displayVideoGameTitles();

   /*Function to add all the video games from a .txt file to the library
    * .txt file must be in the format: Title
    *                                 Developer
    *                                 Publisher
    *                                 Year
    */
    void loadVideoGamesFromFile(char *);

    //Function to remove a single video game from the library
    void removeVideoGameFromArray();

    //Function to print all of the video games details to a .txt file that the user chooses
    void saveToFile(char *);
};
#endif