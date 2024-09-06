#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int val){
        data = val;
        prev = NULL;
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
        n->prev = temp;
    }
}


// insert at head
void insertAtHead(Node* &head, int val){
    Node* n = new Node(val);
    n->next = head;
    if (head != NULL) {
        head->prev = n;
    }
    head = n;
}

// deletion
void deleteAtHead(Node* &head){
    Node* del = head;
    head = head->next;
    head->prev = NULL;

    delete del;
}

void deletion(Node* &head, int pos){
    Node* temp = head;
    int counter = 1;

    if(pos == 1){
        deleteAtHead(head);
        return;
    }

    while(temp != NULL && counter != pos){
        temp = temp->next;
        counter++;
    }


    temp->prev->next = temp->next;
    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }
    
    

    delete temp;
}

// display
void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " --> ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){

    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);

    insertAtHead(head, 10);

    deletion(head, 4);

    display(head);


    return 0;
}