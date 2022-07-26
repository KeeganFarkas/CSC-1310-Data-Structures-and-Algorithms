/*
	Title:  Lab2.cpp
	Author: Keegan Farkas
	Date:  2/3/2022
	Purpose:  Demonstrate your knowledge of recursive functions
*/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

//function prototypes for the recursive functions
int sumOfNumbers(int);
bool isMember(int*, int, int);
void stringReverser(string, int);
bool isPalindrome(string);
int multiply(int, int);

const int ARRAY_SIZE = 10;

int main()
{
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(NULL));
	string userString, userStrModified;
	
	do{
		
		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while(choice < 1 || choice > 6)
		{
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch(choice)
		{
			case 1:
				cout << "\n\nSUM OF NUMBERS\n";
				cout << "Enter an integer:  ";
				cin >> num;
				//print out the result of the sumOfNumbers function here
				cout << "\nThe result is:  " << sumOfNumbers(num);
				break;
				
				
			case 2:
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					myArray[x] = (rand()%100)+1;
				}
				cout << "\n\nISMEMBER ARRAY FUNCTION\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nHere are the array values:  ";
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					cout << myArray[x] << " ";
				}
				//print if the value that the user entered is in the array or not here
				if (isMember(myArray, ARRAY_SIZE, num) == false)
					cout << "\nNo! " << num << " is NOT in the array.";
				else
					cout << "\nYes! " << num << " IS in the array.";				
				break;
				
				
			case 3:
				cout << "\n\nSTRING REVERSER\n";
				cout << "Enter a string and I will reverse it:  ";
				cin.ignore();
				getline(cin, userString);
				//call string reverser function here
				stringReverser(userString, userString.length());
				break;
				
				
			case 4:
				cout << "\n\nPALINDROME DETECTOR\n";
				cout << "Enter a string and I will tell you if it is a palindrome:  ";
				cin.ignore();
				getline(cin, userString);
				
				//change string to be all uppercase
				for(int x=0; x<userString.length(); x++)
				{
					userString[x] = toupper(userString[x]);
				}
				
				//remove spaces and commas from string
				userStrModified = userString;
				for(int x=0; x<userStrModified.size(); x++)
				{
					if(userStrModified[x] == ' ') 
					{
						userStrModified.erase(x, 1);
					}
					if(userStrModified[x] == ',') 
					{
						userStrModified.erase(x, 1);
					}
				}				
				//print out whether the user's string is a palindrome or not here.
				//when you print out the user's string, print out the uppercase version that doesn't have the spaces removed.
				if (isPalindrome(userStrModified) == false)
					cout << "\n\nNo! " << userString << " is NOT a palindrome!";
				else
					cout << "\n\nYes! " << userString << " IS a palindrome!";
				break;
				
				
			case 5:
				cout << "\n\nRECURSIVE MULTIPLICATION\n";
				cout << "Enter in the first integer:  ";
				cin >> num1;
				cout << "\nEnter in the second integer:  ";
				cin >> num2;
				//print out the value returned from the multiply function here
				cout << "\n\nThe value of " << num1 << " x " << num2 << " is " << multiply(num1, num2);
				break;
				
		}		
	}while(choice != 6);
	
	cout << "\n\nGOODBYE!\n\n";
	return 0;
}


//implement the five recursive functions below!!!!
int sumOfNumbers(int num){
	if (num >= 1)
		return sumOfNumbers(num - 1) + num; 
}

bool isMember(int* array, int size, int num){
	if (size == 0)
		return false;	
	else if(array[size - 1] == num)
		return true;
	isMember(array, size - 1, num);
}

void stringReverser(string userString, int length){
	if (length > 0){
		cout << userString.at(length - 1);
		stringReverser(userString, length - 1);
	}
}

bool isPalindrome(string userString){
	if (userString.length() > 1){		
		if(userString.at(0) == userString.at(userString.length() - 1)){
			userString.erase(userString.length() - 1);
			userString.erase(0 + 0);	
			isPalindrome(userString);
		}			
		else
			return false;
	}
	return true;
}

int multiply(int num1, int num2){
	if (num1 != 0)
		return multiply(num1 - 1, num2) + num2;
}