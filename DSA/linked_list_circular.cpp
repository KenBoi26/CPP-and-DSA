#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node* &head, int val){
    Node* n = new Node(val);

    if(head == NULL){
        head = n;
        n->next = head;
        return;
    }

    Node* temp = head;

    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
}

void insertAtHead(Node* &head, int val){
    Node* n = new Node(val);
    if(head==NULL){
        n->next = n;
        head = n;
        return;
    }

    Node* temp = head;

    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
    head = n;

}



void deleteNode(Node* &head, int pos){
    if(pos == 1){
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }

        Node* toDelete = head;
        temp->next = head->next;
        head = head->next;

        delete toDelete;
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count != pos-1){
        temp = temp->next;
        count++;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;

    delete toDelete;
}

Node* floydDetectLoop(Node* head){
    if(head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return slow;
    }

    return NULL;
}

void display(Node* head){
    Node* temp = head;

    do{
        cout << temp->data << " -> ";
        temp = temp->next;  
    }while(temp != head);
}

Node* getStartingNode(Node* head){
    if(head == NULL) return NULL;

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

int main(){

    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);

    display(head);


    return 0;
}