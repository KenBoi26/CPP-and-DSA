// Ques 1: Write C++ program to create a doubly linkedlist and insert a node at any position. 
// Input: 2<->4<->5 ,p = 2, x = 6 
// Output: 2 4 5 6
// Explanation: p = 2, and x = 6. So, 6 is inserted after p, i.e, at position 3

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        this->data = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

void insertAtTail(Node* &head, int val){
    Node* n = new Node(val);
    if(head == nullptr){
        head = n;
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}


void insertAtPos(Node* &head, int pos, int val){
    Node* n = new Node(val);
    if(head == nullptr){
        head = n;
        return;
    }
    Node* temp = head;
    int count = 1;
    while(count < pos){
        temp = temp->next;
        count++;
    }
    n->next = temp->next;
    temp->next = n;
    n->prev = temp;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}


int main(){

    Node* head = nullptr;  

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);

    cout << "Original linked list: ";
    print(head);

    int key = 50;
    int pos = 2;
    insertAtPos(head, pos, key);

    cout << "Updated linked list: ";
    print(head);
}