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

void deletion(Node* &head, int val){
    Node* temp = head;
    
    if(head == NULL) return;

    while(temp->next->data != val){
        temp = temp->next;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void deletionAtHead(Node* &head, int val){
    Node* toDelete = head;
    head = head->next;
    delete toDelete;
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
    insertAtHead(head,101);
    

    display(head);

    cout << "After deletion" << endl;

    deletion(head,100);

    display(head);


    return 0;
}