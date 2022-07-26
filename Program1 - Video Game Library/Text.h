/*
	Title:  Program1.cpp
	Author: Keegan Farkas
	Date:  2/22/2022
	Purpose:  Header file for Text class
*/
#ifndef TEXT_H
#define TEXT_H
using namespace std;

class Text{
    private:
    const char *textArray;
    int textLength;

    public:
    //Text object constructor 
    Text(char *);

    //Text object destructor
    ~Text();

    //Function to print the text stored in the Text object
    void displayText();

    //Function to return the text stored in the Text object
    const char *getText();

    //Function to return the length of the text stored in the Text object
    int getLength();
};
#endif