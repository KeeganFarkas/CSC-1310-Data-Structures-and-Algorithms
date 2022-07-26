
#include <iostream>
#include <iomanip>
#include "Queue.h"
using namespace std;

int menu();

int main()
{
	//make 2 queues, a normal and instant queue---------------------------------------------------------------
	Queue normal, instant;
	int choice, passChoice;
	string name;
	
	do
	{
		choice = menu();
		switch(choice)
		{
			case 1:		cout << "\t\tWhat is your name?\t";
						getline(cin, name);
			
						cout << "\t\t"<< name << ", do you have a(n):\n";
						cout << "\t\t1)Normal Pass?\n";
						cout << "\t\t2)InstantPass?\n";
						cout << "\t\tCHOOSE 1 or 2:\t";
						cin >> passChoice;
						while(passChoice < 1 || passChoice > 2)
						{
							cout << "\t\tOOPS!  That ain't right.  CHOOSE 1 or 2:\t";
							cin >> passChoice;
						}
						cin.ignore();
						
						if(passChoice == 1)
							//add name to the normal queue--------------------------------------------------
							normal.enqueue(name);
						else
							//add name to the instant queue-------------------------------------------------
							instant.enqueue(name);
						break;
						
			case 2:		if(!instant.isEmpty()) //check if there's anyone in the instant queue---------------------------------------------
						{
							//remove the front of the instant queue-----------------------------------------
							instant.dequeue(name);
							cout << "\t\t" << name << ", InstantPass holder, YOU ARE RIDING!\n";
						}
						else if(!normal.isEmpty()) //check if there's anyone in the normal queue---------------------------------
						{
							//remove the front of the normal queue------------------------------------------
							normal.dequeue(name);
							cout << "\t\t" << name << ", normal pass holder, YOU ARE RIDING!\n";
						}
						else
							cout << "\t\tTHERE IS NO ONE IN LINE!\n";
						break;
						
			case 3:		cout << "**IT IS QUITTING TIME!**\n\n";
		}
	}while(choice != 3);
	
	return 0;
}

int menu()
{
	int choice;
	
	cout << "\n\t1)\tADD RIDER TO WAIT LINE.\n";
	cout << "\t2)\tREMOVE RIDER FROM LINE.\n";
	cout << "\t3)\tDONE FOR THE DAY.\n";
	cout << "\tCHOOSE 1-3:\t";
	cin >> choice;
	while(choice < 1 || choice > 3)
	{
		cout << "\tOOPS!  That ain't right.  CHOOSE 1-3:\t";
		cin >> choice;
	}
	cin.ignore();
	
	return choice;
}