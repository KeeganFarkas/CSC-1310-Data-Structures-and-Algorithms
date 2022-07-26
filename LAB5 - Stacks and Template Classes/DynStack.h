#ifndef DYNOSTACK_H
#define DYNOSTACK_H
using namespace std;

template <class T>
class DynamicStack{
    private:
        struct stackNode{
            T value;
            stackNode *next;
        };
        stackNode *top;

    public:
        DynamicStack(){
            top = NULL;
        }

        void push(T item){
            stackNode *newNode = new stackNode;
            newNode->value = item;

            newNode->next = top;
            top = newNode;    
        }

        void pop(T &item){
            stackNode *temp = top->next;
            item = top->value;
            delete top;
            top = temp;
        }

        bool isEmpty(){
            if(!top)
                return true;
            else    
                return false;
        }
};
#endif