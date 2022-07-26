/*  Title: HashTable.h
   Author: Keegan Farkas
     Date: March 31, 2022
  Purpose: Hash Table Implementation
		   Values	                -	Costume objects
		   Hash Function			-	modulus operator
		   Collision resolution     -	linear probing
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "costume.h"
#include "HashEntry.h"
#include <iostream>
using namespace std;

class HashTable{
    private:
        int tableSize;
        HashEntry **hashArray;
    public:
        HashTable(int size){
            tableSize = size;
            hashArray = new HashEntry *[tableSize];

            for(int i = 0; i < tableSize; i++){
                hashArray[i] = NULL;
            }
        }

        ~HashTable(){
            for(int i = 0; i < tableSize; i++){
                if(hashArray[i])
                    delete hashArray[i];
            }
            delete[] hashArray;
        }

       void putValue(int key, Costume *costume){
           HashEntry *newEntry = new HashEntry(key, costume);

           int bucket = key % tableSize;

           while(hashArray[bucket] != NULL && hashArray[bucket]->getKey() != key){
               cout << "Collision at bucket " << bucket << endl;
               bucket = (bucket + 1) % tableSize;
           }

           cout << "BUCKET " << bucket << endl;
           hashArray[bucket] = newEntry;
       }

        void printHashTable(){
            cout << "----------" << endl;
            for(int i = 0; i < tableSize; i++){
                cout << i << ": ";
                if(hashArray[i])
                    cout << *(hashArray[i]->getValue()) << endl; 
                else
                    cout << "Empty" << endl;               
            }
            cout << "----------";
       }
};

#endif