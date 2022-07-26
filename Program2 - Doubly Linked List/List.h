#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

template <class T>
class List{
    private:
        struct listNode{
            T value;
            listNode *next, *previous;
        };
        listNode *head, *tail;

        void print(listNode *node){
            while(node){
                cout << *(node->value) << endl;
                node = node->next;
            }
        }

        List<T>::listNode* mergesort(listNode *beg, listNode *end){
            if(beg == end)
                return beg;
            
            listNode *Lbeg, *Rbeg;
            Rbeg = split(beg, end);

            Lbeg = mergesort(beg, Rbeg->previous);
            Rbeg = mergesort(Rbeg, end);

            return merge(Lbeg, Rbeg);
        }

        List<T>::listNode* merge(listNode *Lbeg, listNode *Rbeg){
            if(!Lbeg)
                return Rbeg;
            if(!Rbeg)
                return Lbeg;

            if(*(Lbeg->value) > *(Rbeg->value)){
                Lbeg->next = merge(Lbeg->next, Rbeg);
                Lbeg->next->previous = Lbeg;
                Lbeg->previous = NULL;
                return Lbeg;
            }
            else{
                Rbeg->next = merge(Lbeg, Rbeg->next);
                Rbeg->next->previous = Rbeg;
                Rbeg->previous = NULL;
                return Rbeg;
            }
        }

        List<T>::listNode* split(listNode *beg, listNode *end){
            while(beg != end && beg->previous != end){
                beg = beg->next;
                end = end->previous;
            }

            beg = end->next;
            end->next = NULL;
            return beg;
        }

    public:
        List(){
            head = NULL;
            tail = NULL;
        }

        ~List(){
            if(!head){
                cout << "\nDeleted empty list";
                return;
            }

            listNode *nodePtr;
            nodePtr = head;

            while(nodePtr->next){
                nodePtr = nodePtr->next;
                delete nodePtr->previous;
            }

            delete nodePtr;

            cout << "\nDeleted memory for each node in the list and the list itself.";
        }

        void print(){
            if(!head){
                cout << "\nCannot print an empty list";
                return;
            }

            print(head);
        }
        
        void append(T newValue){
            listNode *newNode = new listNode;
            newNode->value = newValue;

            if(!head){
                head = newNode;
                tail = newNode;
                newNode->previous = NULL;
                newNode->next = NULL;
            }
            else{
                newNode->previous = tail;
                newNode->next = NULL;
                tail->next = newNode;
                tail = newNode;
            }
        }

        void mergesort(){
            head = mergesort(head, tail);

            listNode *nodePtr;
            nodePtr = head;

            while(nodePtr->next){
                nodePtr = nodePtr->next;
            }

            tail = nodePtr;
        }
};

#endif