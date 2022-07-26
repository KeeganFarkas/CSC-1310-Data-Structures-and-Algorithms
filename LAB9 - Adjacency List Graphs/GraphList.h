/*
	Title:    GraphList.h
	Author:   Keegan Farkas
	Date:     April 15, 2022
	Purpose:  Header file for the GraphList class
*/
#ifndef GRAPHLIST_H
#define GRAPHLIST_H
using namespace std;

class GraphList{
    private:
        struct ListNode{
            int value;
            ListNode *next;
        };
        ListNode **headArray;
        int numVertices, numEdges = 0;

    public:
        GraphList(int num){
            numVertices = num;
            cout << "There are " << numVertices << " vertices in the graph.\n";

            headArray = new ListNode *[numVertices];

            for(int i = 0; i < numVertices; i++){
                ListNode *newNode = new ListNode;
                newNode->value = i;
                newNode->next = NULL;

                headArray[i] = newNode;
            }
        }

        ~GraphList(){
            ListNode *current, *previous;

            for(int i = 0; i < numVertices; i++){
                current = headArray[i];

                do{
                    previous = current;
                    current = current->next;
                    delete previous;
                }while(current);
            }
            delete[] headArray;
        }

        void addEdge(int vertice1, int vertice2){
            cout << "\nAdding an edge from " << vertice1 << " to " << vertice2 << ".";
            
            ListNode *newNode = new ListNode, *nodePtr;
            newNode->next = NULL;
            newNode->value = vertice2;

            nodePtr = headArray[vertice1];

            while(nodePtr->next){
                nodePtr = nodePtr->next;
            }
            nodePtr->next = newNode;
            numEdges++;
        }

        void printGraph(){
            ListNode *nodePtr;

            cout << "\n\nAdjacency List...\n";

            for(int i = 0; i < numVertices; i++){
                nodePtr = headArray[i];
                do{
                    cout << nodePtr->value << "--->";
                    nodePtr = nodePtr->next;
                }while(nodePtr);

                cout << "NULL\n";
            }
        }
};
#endif