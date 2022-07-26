#include "BST.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
	BST* tree1 = new BST;
	BST* tree2;
	int random;
	srand(time(NULL));

	cout << "adding values: ";
	for(int i = 0; i < 10; i++)
	{
		random = rand() % 100;
		cout << random << " ";
		tree1->insertNode(random);
	}

	cout << "\ndisplay tree 1: ";
	tree1->display();

	tree2 = new BST(*(tree1));
	cout << "\ndisplay tree 2: ";
	tree2->display();
	cout << endl;

	cout << "\nadding to tree 2: ";
	for(int i = 0; i < 3; i++)
	{
		random = rand() % 100;
		cout << random << " ";
		tree2->insertNode(random);
	}

	cout << "\ndisplay tree 1 again: ";
	tree1->display();

	cout << "\ndisplay tree 2 again: ";
	tree2->display();
	cout << endl;

	delete[] tree1, tree2;

	return 0;
}