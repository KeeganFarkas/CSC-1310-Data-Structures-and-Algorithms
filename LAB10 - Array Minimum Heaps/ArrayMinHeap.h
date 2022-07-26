#ifndef ARRAYMINHEAP_H
#define ARRAYMINHEAP_H
#include <cmath>
#include "creature.h"
using namespace std;

class ArrayMinHeap{
    private:
        Creature *heapArray;
        int capacity, heap_size;
        Creature emptyCreature;

        void swap(Creature *x, Creature *y)
		{
			Creature temp = *x;
			*x = *y;
			*y = temp;
		}			
		
		int parent(int i)
		{ 
			return (i - 1) / 2; 
		}

		int left(int i)
		{ 
			return (2 * i + 1); 
		}

		int right(int i)
		{ 
			return (2 * i + 2); 
		}

    public:
        ArrayMinHeap(int capacity){
            heap_size = 0;
            this->capacity = capacity;

            heapArray = new Creature[capacity];
        }

        ~ArrayMinHeap(){
            delete [] heapArray;
        }

        void minHeapify(int i){
            int l = left(i);
            int r = right(i);
            int smallest = i;

            if(l < heap_size && heapArray[l].getName() < heapArray[i].getName())
                smallest = l;
            if(r < heap_size && heapArray[r].getName() < heapArray[smallest].getName())
                smallest = r;
            if(smallest != i){
                swap(&heapArray[i], &heapArray[smallest]);
                minHeapify(smallest);
            }
        }

        Creature peek(){
            return heapArray[0];
        }

        bool remove(){
            if(isEmpty()){
                cout << "Error: There are no Creatures in the heap.";
                return false;
            }

            if(heap_size == 1){
                heap_size--;
                return true;
            }

            Creature root = heapArray[0];
            heapArray[0] = heapArray[heap_size - 1];
            heap_size--;
            minHeapify(0);
            return true;
        }

        void insert(Creature newCreature){
            if(heap_size == capacity)
                resizeArray();

            heapArray[heap_size] = newCreature;
            heap_size++;
            int i = heap_size - 1;

            while(i != 0 && heapArray[parent(i)].getName() > heapArray[i].getName()){
                swap(&heapArray[i], &heapArray[parent(i)]);
                i = parent(i);
            }
        }

        void resizeArray(){
            int cap = capacity * 2;
            Creature *newHeapArray = new Creature[cap];

            for(int i = 0; i < capacity; i++){
                newHeapArray[i] = heapArray[i];
            }

            delete [] heapArray;
            heapArray = newHeapArray;
            capacity = cap;
        }

        bool isEmpty(){
            if(heap_size == 0)
                return true;
            else
                return false;
        }

        int getNumberOfNodes(){
            return heap_size;
        }

        int getHeight(){
            return ceil(log2(heap_size + 1));
        }

        void display(){
            if(isEmpty()){
                cout << "Error: there are no creatures in the heap.";
                return;
            }

            for(int i = 0; i < heap_size; i++){
                cout << heapArray[i].getName() << endl;
            }
        }

        void saveToFile(){
            for(int i = 0; i < heap_size; i++){
                heapArray[i].printCreatureToFile("savedCreatures.txt");
            }
        }
};

#endif  