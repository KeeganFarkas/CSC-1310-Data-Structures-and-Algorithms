#ifndef QUEUE_H
#define QUEUE_H
using namespace std;

class Queue{
    private:
        struct QueueNode{
            string riderName;
            QueueNode *next;
        };
        int numNodes;
        QueueNode *head, *tail;
    public:
        Queue(){
            head = NULL;
            tail = NULL;
            numNodes = 0;
        }

        void enqueue(string name){
            QueueNode *newNode = new QueueNode;
            newNode->riderName = name;
            newNode->next = NULL;

            if(isEmpty()){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
            numNodes++;
        }

        void dequeue(string &name){
            QueueNode *temp;

            name = head->riderName;
            temp = head;
            head = head->next;
            delete temp;
            numNodes--;
        }

        void dequeue(){
            QueueNode *temp;

            temp = head;
            head = head->next;
            delete temp;
            numNodes--;
        }

        bool isEmpty(){
            if(!head)
                return true;
            else
                return false;
        }

        ~Queue(){
            for(int i = 0; i < numNodes; i++){
                cout << "Oh shoot, I am sorry, our park is closed so " << head->riderName;
                cout << " will not get to ride today." << endl;
                dequeue();
                numNodes++;
            }
        }
};
#endif