/*
	Title:  		Costume.h
	Author:			April Crockett
	Date Created:  	October 6, 2020
	Purpose:  		Implementation of the Costume class
				
*/
#ifndef COSTUME_H
#define COSTUME_H

#include <iostream>
using namespace std;

class Costume
{
	private:
		//attributes
		int id; // costume id
		string costumeName;
		float price;
		int stock;
		
	public:
		Costume(int id, string name, float price, int stock){
			this->id = id;
			this->costumeName = name;
			this->price = price;
			this->stock = stock;
		}
		int getID() const
		{
			return this->id;
		}
		string getCostumeName() const
		{
			return this->costumeName;
		}
		float getPrice() const
		{
			return this->price;
		}
		int getStock() const
		{
			return this->stock;
		}
		void setStock(int newStock)
		{
			stock = newStock;
		}
		friend ostream & operator<< (ostream & os, Costume c)
		{
			os << c.getID() << ", " << c.getCostumeName();
			return os;
		}
		
};

#endif