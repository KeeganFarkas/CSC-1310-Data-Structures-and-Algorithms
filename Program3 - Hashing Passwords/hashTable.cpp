#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "hashTable.h"
using std::string;
using std::cout;
using namespace std;

hashTable::hashTable(int size){
	//you need to add everything else that belongs in the constructor--------------------------------------
	tableSize = size;
	hashArray = new entry*[tableSize];

	for(int i = 0; i < size; i++){
		hashArray[i] = NULL;
	}
	srand (time(0));	//this needs to be in the constructor, otherwise every user gets the same salt
}

hashTable::~hashTable(){
	entry *nextPtr;
	entry *current;

	for(int i = 0; i < tableSize; i++){
		if(hashArray[i]){
			current = hashArray[i];
			nextPtr = current->next;
			while(current->next){
				delete current;
				current = nextPtr;
				nextPtr = current->next;
				cout << "User Deleted" << endl;
			}
			delete current;
			cout << "User Deleted" << endl;
		}
	}
	delete hashArray;
	cout << "hashArray Deleted" << endl;
}

string hashTable::getSalt(string uname){
	entry *user = getEntry(uname);
	if(user)
		return getEntry(uname)->getSalt();
	else
		return "\0";
}

void hashTable::addEntry(string uname, string salt, string passHash){
	entry *newEntry = new entry(uname, salt, passHash);

	int bucket = hash(uname);

	if(hashArray[bucket] == NULL)
		hashArray[bucket] = newEntry;

	else if(hashArray[bucket]->getUsername() == uname){
		delete newEntry;
		cout << "Username not available" << endl;
	}
	else if(hashArray[bucket]->next == NULL)
		hashArray[bucket]->next = newEntry;

	else{
		entry *current = hashArray[bucket];

		do{
			current = current->next;

			if(current->getUsername() == uname){
				delete newEntry;
				cout << "Username not available" << endl;
			}
		}while(current->next);
		current->next = newEntry;
		cout << "Account Created" << endl;
	}
}

bool hashTable::validateLogin(string uname, string passHash){
	entry *user = getEntry(uname);
	if(user){
		if(user->getHashedpwd() == passHash)
			return true;
	}
	return false;
}

bool hashTable::removeUser(string uname, string passHash){
	if(validateLogin(uname, passHash)){
		int bucket = hash(uname);
		entry *current = hashArray[bucket]->next;

		if(hashArray[bucket]->getUsername() == uname){
			delete hashArray[bucket];
			if(current == NULL)
				hashArray[bucket] = NULL;
			else{
				hashArray[bucket] = current;
				if(current->next == NULL)
					hashArray[bucket]->next = NULL;
				else
					hashArray[bucket]->next = current->next;
			}
		}
		else{
			current = hashArray[bucket];
			entry *user = getEntry(uname);

			while(current->next->getUsername() != uname){
				current = current->next;
			}
			if(user->next == NULL)
				current->next = NULL;
			else
				current->next = user->next;
			delete user;
		}
		return true;
	}
	else
		return false;
}

hashTable::entry::entry(string uname, string salt, string passHash){
	this->uname = uname;
	this->salt = salt;
	this->passHash = passHash;
	next = NULL;
}

string hashTable::entry::getUsername(){
	return uname;
}

string hashTable::entry::getSalt(){
	return salt;
}

string hashTable::entry::getHashedpwd(){
	return passHash;
}

hashTable::entry* hashTable::getEntry(string key){
	int bucket = hash(key);

	if(hashArray[bucket] == NULL)
		return NULL;

	if(hashArray[bucket]->getUsername() == key)
		return hashArray[bucket];
	else{
		entry *current = hashArray[bucket];
		while(current->next){
			current = current->next;

			if(current->getUsername() == key)
				return current;
		}
		return NULL;
	}
}

//don't touch this!
int hashTable::hash(string key)
{
	int sum = 0;
	for(int i = 0; i < key.size(); i++)
		sum += key[i];
	
	return sum % tableSize;
}

//don't touch this!
string hashTable::generateSalt()
{
	string s = "";
	
	for(int i = 0; i < tableSize; i++)
		s = s + char('!' + (rand() % 93));
	return s;
}