// Question 1
// Write a C++ code that take linked list from user input that is in sorted order and a value integer. Now insert the value inside linkedlist such that new likedlist is also in sorted order. Sample Input:- 10->20->30->40 value =25 Sample Output:- 10->20->25->30->40

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        this->data = val;
        this->next = nullptr;
    }
};

void insertAtEnd(Node* &head, int val){
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
}


void insertAtSortedPosition(Node* &head, int val){
    Node* n = new Node(val);

    if(head == nullptr){
        head = n;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr && temp->next->data < val){
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
}


void print(Node* &head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}


int main() {
    Node *head = nullptr;  

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    cout << "Original linked list: ";
    print(head);

    int value = 25;
    cout << "Inserting value: " << value << endl;
    insertAtSortedPosition(head, value);

    cout << "Updated linked list: ";
    print(head);

    return 0;
}