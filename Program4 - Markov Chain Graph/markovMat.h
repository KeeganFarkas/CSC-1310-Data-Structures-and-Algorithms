#ifndef MARKOVMAT_H
#define MARKOVMAT_H

#include<map>
#include<fstream>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

class markovMat
{
	private:
		struct matrix{
			map<string, int> buckets;
			float **array;
		};
		matrix corpus;
		int corpusSize;
	public:
		markovMat(const char*);
		~markovMat();
		
		string generate(int);
		void print();
};

markovMat::markovMat(const char* filename)
{
	ifstream file(filename);
	stringstream* parser;
	stringstream splitter;
	string line, word;
	float weight;
	int i = 0;
	srand (time(0));
	
	if(file.good()) {
	file >> corpusSize;
	file.ignore(1, '\n');
	//allocate memory for the matrix and set every value to 0---
	corpus.array = new float*[corpusSize];

	for(int i = 0; i < corpusSize; i++){
		corpus.array[i] = new float[corpusSize];
	}

	for(int i = 0; i < corpusSize; i++){
		for(int j = 0; j < corpusSize; j++){
			corpus.array[i][j] = 0;
		}
	}

	parser = new stringstream[corpusSize];
	
	while(getline(file, line, '\n')) //map every word to a position in the matrix, keep the line in an array of buffers for later
	{
		parser[i] << line;
		getline(parser[i], word,',');
		//assign an index number to the map for the current word
		corpus.buckets[word] = i;
		i++;
	}
	for(i = 0; i < corpusSize; i++) //populate matrix using buffer array
	{
		while(getline(parser[i], word, ','))
		{
			splitter.clear();
			splitter.str(word);
			splitter >> word >> weight;
			//add weight into the matrix, with the first index as the starting node and the second index at the destination node
			corpus.array[i][corpus.buckets[word]] = weight;
		}
	}}
	delete[] parser;
}

markovMat::~markovMat()
{
//write this
for(int i = 0; i < corpusSize; i++){
	delete[] corpus.array[i];
}
delete[] corpus.array;
}

string markovMat::generate(int length)
{
	string output, word;
	float random, sum;
	//pick random starting node
	map<string, int>::iterator it = corpus.buckets.begin();		//initialize an iterator to find a random node in the next line
	advance(it,rand() % corpusSize);	//this grabs a random node from your corpus as a starting point
	//you'll need to write the rest of this
	output = it->first;
	word = it->first;

	for(int i = 1; i < length; i++){
		random = (float)rand()/RAND_MAX;
		sum = 0;

		for(map<string, int>::iterator it = corpus.buckets.begin(); random > sum; it++){
			sum += corpus.array[corpus.buckets[word]][it->second];

			if(random < sum){
				output = output + " " + it->first;
				word = it->first;
			}
		}
	}
	return output;
}

void markovMat::print(){
	cout << "corpusSize = " << corpusSize << endl;
	for(map<string, int>::iterator it = corpus.buckets.begin(); it != corpus.buckets.end(); it++){
		cout << it->first << " = " << it->second << endl;
	}
	for(int i = 0; i < corpusSize; i++){
		for(int j = 0; j < corpusSize; j++){
			if(corpus.array[i][j] != 0)
				cout << i << " to " << j << " = " << corpus.array[i][j] << " \n";
		}
	}
}
#endif