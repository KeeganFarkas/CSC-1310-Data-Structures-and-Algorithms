/*
	Function Definitions for Course Structure
	LAB 1 - CSC1310
	Keegan Farkas
	
	1/10/2019
*/
#include "Course.h"
#include <iostream>
#include <string>
using namespace std;

Course* createCourse (string name, string location, int numCreditHours, int numSections){
    Course *data;
    data = new Course;

    data->Name = name;
    data->Location = location;
    data->numCreditHours = numCreditHours;
    data->numSections = numSections;
    data->Sections = new string[numSections];
    
    return data;
}

void destroyCourse (Course* myCourse){
    delete [] myCourse;
}

void printCourse (Course* myCourse){
    cout << "COURSE NAME:\t\t" << myCourse->Name << endl;
    cout << "COURSE LOCATION:\t" << myCourse->Location << endl;
    cout << "COURSE HOURS:\t\t" << myCourse->numCreditHours << endl;
    cout << "COURSE SECTIONS:";

    for(short i = 0; i < myCourse->numSections; i++){
        cout << "\n\t\t\t" << myCourse->Sections[i];
    }
    cout << endl;
}



