#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        this->data = val;
        this->next = NULL;
    }

};

// Question 1


void printLinkedList(Node* head){
    Node* current = head;

    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
}


// Question 2

void insertAtEnd(Node* &head, int data){
    Node* n = new Node(data);

    if(head == NULL){
        head = n;
        return;
    }else{
        Node* current = head;

        while(current->next!=NULL){
            current = current->next;
        }

        current->next = n;

    }
}