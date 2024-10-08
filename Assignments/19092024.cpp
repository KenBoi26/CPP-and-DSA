#include<iostream>
using namespace std;

class priorityQueue{
    public:
    int data;
    int priority;
};

void enqueue(priorityQueue pqueue[], int& size, int data, int priority){
    size++;
    if(size == 0){
        pqueue[size].data = data;
        pqueue[size].priority = priority;
        return;
    }
    int i = size -1;
    for(i; i >= 0; i--){
        if(pqueue[i].priority <= priority){
            i++;
            for(int j=size; j>i; j--){
                pqueue[j] = pqueue[j-1];
            }

            break;
        }
    }

    pqueue[i].data = data;
    pqueue[i].priority = priority;
}

void dequeue(priorityQueue pqueue[], int& size){
    if(size == 0){
        cout << "The Queue is empty" << endl;
        return;
    }

    cout << "Dequeued: " << pqueue[0].data << endl;
    for(int i=0; i<size; i++){
        pqueue[i] = pqueue[i+1];
    }
    size--;
}

void peek(priorityQueue pqueue[], int size){
    if(size == 0){
        cout << "The Queue is empty" << endl;
        return;
    }

    cout << "Peek: " << pqueue[0].data << endl;
}

void display(priorityQueue pqueue[], int size){
    if(size == 0){
        cout << "The Queue is empty" << endl;
        return;
    }

    for(int i=0; i<size; i++){
        cout << pqueue[i].data << " ";
    }
    cout << endl;
}




int main(){

    priorityQueue pqueue[100];
    int size = -1;

    enqueue(pqueue, size, 10, 1);
    display(pqueue, size);
    enqueue(pqueue, size, 20, 2);
    display(pqueue, size);
    enqueue(pqueue, size, 30, 3);
    display(pqueue, size);
    enqueue(pqueue, size, 25, 2);
    display(pqueue, size);

    dequeue(pqueue, size);
    display(pqueue, size);

    peek(pqueue, size);

    


    return 0;
}