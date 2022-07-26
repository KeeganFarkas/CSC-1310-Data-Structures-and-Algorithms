#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
using std::string;

class hashTable
{
	private:
		class entry;

		//add the attributes you need for the class---------------------------------------------------------
		int tableSize;
		entry **hashArray;

		int hash(string);
		entry *getEntry(string);
	public:
		//add all the functions you need--------------------------------------------------------------------
		string generateSalt();
		hashTable(int);
		~hashTable();
		string getSalt(string);
		void addEntry(string, string, string);
		bool validateLogin(string, string);
		bool removeUser(string, string);
};

class hashTable::entry
{
	private:
		string uname;
		string salt;
		string passHash;
	public:
		entry* next;

		//add the constructor and getter functions-----------------------------------------------------------
		entry(string, string, string);
		string getUsername();
		string getSalt();
		string getHashedpwd();
};

#endif