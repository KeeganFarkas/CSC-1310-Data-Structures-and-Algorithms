/*
	Title:  VideoGame.h
	Author: Keegan Farkas
	Date:  2/22/2022
	Purpose:  HeaderFile for VideoGame class
*/
#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include "Text.h"
#include <fstream>
using namespace std;

class VideoGame{
    private:
    Text *title, *developer, *publisher;
    int year;

    public:
    //VideoGame object constructor
    VideoGame(Text *, Text *, Text *, int);

    //VideoGame object destructor
    ~VideoGame();

    //Function to print the details for a certain video game
    void printVideoGameDetails();

    //Function to print the details for a certain video game to a file
    void printVideoGameDetailsToFile(ofstream&);

    //Function to return only the title for a certain video game
    Text *getVideoGameTitle();
};
#endif