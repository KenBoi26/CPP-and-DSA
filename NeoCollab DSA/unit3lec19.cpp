// Question 1
// You are using GCC
#include <iostream>
#include <stdlib.h>

struct Node {
    int data;
    Node* next;
};

struct Deque {
    Node* front;
    Node* rear;
};

void initDeque(Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

bool isEmpty(Deque* deque) {
    return deque->front == NULL;
}

void pushBack(Deque* deque, int data) {
    //Type your code here
    Node* n = new Node();
    n->data = data;
    n->next = NULL;
    
    if(isEmpty(deque)){
        deque->front = n;
        deque->rear = n;
    }else{
        deque->rear->next = n;
        deque->rear = n;
    }
    
    
}

int popFront(Deque* deque) {
    //Type your code here
    if(isEmpty(deque)){
        std::cout << "Dequeu is empty" << std::endl;
        return -1;
    }
    
    Node* t = deque->front;
    int d = t->data;
    deque->front = deque->front->next;
    if(deque->front == NULL){
        deque->rear = NULL;
    }
    return d;
    
}

int main() {
    Deque myDeque;
    initDeque(&myDeque);
    int num;
    while (1) {
        std::cin >> num;
        if (num == -1)
            break;
        pushBack(&myDeque, num);
    }
    int count = 0;
    Node* current = myDeque.front;
    while (current != NULL) {
        count++;
        current = current->next;
        if (current != NULL) {
            current = current->next;
        }
    }
    std::cout<<"Number of alternate elements in the deque: "<<count;
    return 0;
}

// Question 2
// You are using GCC
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Deque {
    Node* front;
    Node* rear;
};

void initDeque(Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

bool isEmpty(Deque* deque) {
    return deque->front == NULL;
}

void pushBack(Deque* deque, int data) {
    //Type your code here
    Node* n = new Node();
    n->data = data;
    n->next = NULL;
    
    if(isEmpty(deque)){
        deque->front = n;
        deque->rear = n;
    }else{
        deque->rear->next = n;
        deque->rear = n;
    }
    
}

int popFront(Deque* deque) {
    //Type your code here
    if(isEmpty(deque)){
        std::cout << "DeQueue is empty" << std::endl;
        return -1;
    }
    
    Node* temp = deque->front;
    int data = temp->data;
    deque->front = deque->front->next;
    if(deque->front == NULL){
        deque->rear = NULL;
    }
    
    return data;
    
    
}

int main() {
    Deque myDeque;
    initDeque(&myDeque);
    int num;
    while (1) {
        std::cin >> num;
        if (num == -1)
            break;
        pushBack(&myDeque, num);
    }
    std::cout << "Even elements: ";
    
    //Type your code here
    Node* current = myDeque.front;
    while(current != NULL){
        if(current->data % 2 == 0){
            std::cout << current->data << " ";
        }
        current = current->next;
    }
    
    cout<<endl;
    std::cout << "Odd elements: ";
    
    //Type your code here
    current = myDeque.front;
    while(current != NULL){
        if(current->data % 2 != 0){
            std::cout << current->data << " ";
        }
        current = current->next;
    }
    
    cout<<endl;
    return 0;
}

// Question 3
// You are using GCC
#include <iostream>
#include <stdlib.h>

struct Node {
    int data;
    Node* next;
    Node* prev;
};

struct Deque {
    Node* front;
    Node* rear;
    int size;
};

void initDeque(Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
    deque->size = 0;
}

bool isEmpty(Deque* deque) {
    return deque->size == 0;
}

void pushBack(Deque* deque, int data) {
    //Type your code here
    Node* n = new Node();
    n->data = data;
    n->next = NULL;
    
    if(isEmpty(deque)){
        deque->front = n;
        deque->rear = n;
        deque->size = 1;
    }else{
        deque->rear->next = n;
        deque->rear = n;
        deque->size++;
    }
    
}

int getSize(Deque* deque) {
    //Type your code here
    return deque->size;
    
}

int main() {
    Deque myDeque;
    initDeque(&myDeque);
    int num;
    while (1) {
        std::cin >> num;
        if (num == -1)
            break;
        pushBack(&myDeque, num);
    }
    int count = getSize(&myDeque);
    std::cout << count;
    return 0;
}

// Question 4
// You are using GCC
#include <iostream>
using namespace std;
#define MAX 100

class Deque {
	int arr[MAX];
	int front;
	int rear;
	int size;

public:
	Deque(int size)
	{
		front = -1;
		rear = 0;
		this->size = size;
	}

	// Operations on Deque:
	void insertfront(int key);
	void insertrear(int key);
	void deletefront();
	void deleterear();
	bool isFull();
	bool isEmpty();
	int getFront();
	int getRear();
};


bool Deque::isFull()
{
	return ((front == 0 && rear == size - 1)
			|| front == rear + 1);
}


bool Deque::isEmpty() { 
    return (front == -1); 
}

void Deque::insertfront(int key) {
    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (front == 0) {
        front = size - 1;
    } else {
        front = front - 1;
    }
    arr[front] = key;
}

void Deque::deletefront() {
    if (isEmpty()) {
        cout << "Deque is empty" << endl;
        return;
    }
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        if (front == size - 1)
            front = 0;
        else
            front = front + 1;
    }
}

int Deque::getFront() {
    if (isEmpty()) {
        return -1;
    }
    return arr[front];
}

int main()
{
	int len;
	cin>>len;
	Deque dq(len);
	int val;
    for(int i=0;i<len;i++)
    {
        cin>>val;
	    dq.insertfront(val);
    }

	cout << "The front element is " << dq.getFront() << endl;

    int del;
    cin>>del;
    for(int i=0;i<del;i++)
    {
        dq.deletefront();
    }

	cout << "After deletion, the front element becomes " << dq.getFront() ;
	return 0;
}