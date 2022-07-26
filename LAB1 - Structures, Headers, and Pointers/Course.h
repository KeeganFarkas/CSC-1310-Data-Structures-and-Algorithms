/*
	Header File for Course Structure
	LAB 1 - CSC1310
	Keegan Farkas
	
	1/10/2019
*/
#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;
struct Course{
    string Name, Location;
    int numSections, numCreditHours;
    string *Sections;
};

Course* createCourse (string, string, int, int);

void destroyCourse (Course* myCourse);

void printCourse (Course* myCourse);

#endif