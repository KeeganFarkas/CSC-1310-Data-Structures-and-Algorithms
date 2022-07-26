#include<iostream>
#include "markovMat.h"
#include "markovList.h"
using namespace std;

int main()
{
	markovMat* chain = new markovMat("corpus.txt");
	//markovList* chain = new markovList("corpus.txt");

	//chain->print();

	cout << chain->generate(100) << endl;

	delete chain;
	return 0;
}