#ifndef BST_H
#define BST_H

#include<iostream>
using namespace std;

class BST
{
	private:
		struct treeNode
		{
			int value;
			treeNode* left;
			treeNode* right;
		};
		treeNode* root;

		void copy(treeNode*& newNodePtr, treeNode* nodePtr){
			if(nodePtr){
				treeNode *newNode = new treeNode;

				newNode->value = nodePtr->value;
				newNode->left = newNode->right = NULL;
				
				insert(newNodePtr, newNode);

				copy(newNodePtr->left, nodePtr->left);
				copy(newNodePtr->right, nodePtr->right);
			}
		}

		void insert(treeNode*& nodePtr, treeNode* newNode){
			if(nodePtr == NULL)
				nodePtr = newNode;
			else if(newNode->value < nodePtr->value)
				insert(nodePtr->left, newNode);
			else
				insert(nodePtr->right, newNode);
		}

		void displayInOrder(treeNode* nodePtr) const{
			if(nodePtr){
				displayInOrder(nodePtr->left);

				cout << nodePtr->value << " ";

				displayInOrder(nodePtr->right);
			}
		}

		void destroySubTree(treeNode* nodePtr){
			if(nodePtr){
				if(nodePtr->left)
					destroySubTree(nodePtr->left);
				if(nodePtr->right)
					destroySubTree(nodePtr->right);
				delete nodePtr;
			}
		}

	public:
		//default constructor
		BST(){
			root = NULL;
		}

		//copy constructor
		BST(const BST &tree){
			root = NULL;
			copy(root, tree.root);
		}

		~BST(){
			destroySubTree(root);
		}

		void insertNode(int num){
			treeNode *newNode = new treeNode;

			newNode->value = num;
			newNode->left = newNode->right = NULL;

			insert(root, newNode);
		}

		void display(){
			displayInOrder(root);
		}
};

#endif