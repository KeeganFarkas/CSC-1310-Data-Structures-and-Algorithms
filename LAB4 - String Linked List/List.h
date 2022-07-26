/*****************************************************************
	Title:  		List.h
	Creation Date:  2-24-2022
	Last Updated:	2-25-2022
	Author: 		Keegan Farkas
	Purpose:		CSC 1310 Lab 4
******************************************************************/
#ifndef LIST_H
#define LIST_H
using namespace std;

class List{
    private:
        struct ListNode{
            string word;
            ListNode *next;
        };

        ListNode *head, *tail;

    public:
        void appendNode(string word){
            ListNode *newNode = new ListNode;
            newNode->word = word;

            if(head == NULL){
                head = newNode;
                tail = newNode;
                newNode->next = NULL;
            }

            tail->next = newNode;
            tail = newNode;
            newNode->next = NULL;
        }

        void insertNode(string word){
            ListNode *nodePtr;
            ListNode *newNode = new ListNode;

            newNode->word = word;
            nodePtr = head;

            if(nodePtr->word > newNode->word){
                newNode->next = head;
                head = newNode;
            }

            while(nodePtr->next->word < newNode->word){
             nodePtr = nodePtr->next;

             if(nodePtr->next == NULL){
                    tail = newNode;
                    break;
                }
            }

            newNode->next = nodePtr->next;
            nodePtr->next = newNode;
        }

        void deleteNode(string word){
            ListNode *nodePtr;
            ListNode *prevNode;

            nodePtr = head;

            if(nodePtr->word == word){
                head = nodePtr->next;
                delete nodePtr;
            }
            else{
                while(nodePtr->word != word){
                    if(nodePtr->next == tail){
                        delete nodePtr->next;
                        nodePtr->next = NULL;
                        tail = nodePtr;
                        return;
                    }

                    prevNode = nodePtr;
                    nodePtr = nodePtr->next;
                }
                
                prevNode->next = nodePtr->next;
                delete nodePtr;
            }
        }

        void displayList(){
            ListNode *nodePtr;

            nodePtr = head;

            while(nodePtr != NULL){
                cout << nodePtr->word << endl;

                nodePtr = nodePtr->next;
            }
        }

        List(){
            head = NULL;
            tail = NULL;
        }

        ~List(){
            ListNode *nodePtr;
            ListNode *currentNode;

            nodePtr = head;
            currentNode = head;
            
            while(currentNode){
                currentNode = nodePtr->next;
                delete nodePtr;
                nodePtr = currentNode;
            }

            cout << "\nAll list nodes have been removed.";
        }
};
#endif