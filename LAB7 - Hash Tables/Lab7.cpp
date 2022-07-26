/*
	Title:    Lab8.cpp
	Author:   April Crockett
	Date:     October 6, 2020
	Purpose:  Costume Inventory Data stored in Hash Table
*/

#include <iostream>
#include "HashTable.h"
#include "Costume.h"
using namespace std;

int main()
{
	int size;
	int key;
	Costume *newCostume;
	string name;
	float price;
	int stock;
	
	cout << "\nHello.\n\n";
	
	cout <<"What size is the table?   ";
	cin >> size;
	
	//create a Hash Table
	HashTable myHashTable(size);
	
	//fill the table
	for(int i=0; i<size; i++)
	{
		cout << "\n*****COSTUME " << i+1 << "*****\n";
		cout << "COSTUME ID:  ";
		cin >> key;
		cin.ignore();
		cout << "NAME:  ";
		getline(cin, name);
		cout << "PRICE:  $";
		cin >> price;
		cout << "STOCK:  ";
		cin >> stock;
		newCostume = new Costume(key, name, price, stock);
		myHashTable.putValue(key, newCostume);
	}
		
	cout << "\n\nHERE IS THE TABLE:\n\n";
	myHashTable.printHashTable();
	cout << endl << endl;
	
	return 0;
	
}