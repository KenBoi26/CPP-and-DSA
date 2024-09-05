#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        this->data = val;
        next = NULL;
    }

};


void insertAtTail(Node* &head, int val){
    Node* n = new Node(val);

    if (head == NULL) {
        head = n;
    } else {
        Node* temp = head;

        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = n;
    }
}

void insertAtHead(Node* &head, int val){

    Node* n = new Node(val);

    n->next = head;
    head = n;
}

void display(Node* head){
    Node* temp = head;
    
    while (temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
    
}


int main(){

    Node* head = NULL;

    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtHead(head,100);

    display(head);


    return 0;
}