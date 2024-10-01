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


// Ques 2: Write C++ program that detect the cycle inside a given linkedlist if their is any cycle present then print true otherwise print false. Input: head = [3,2,0,-4], pos = 1. Output: true. Explanation: There is a cycle in the linked list, where the tail connects to the 1st node

#include<iostream>
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

int main(){
    
        Node* head = new Node(3);
        head->next = new Node(2);
        head->next->next = new Node(0);
        head->next->next->next = new Node(-4);
        head->next->next->next->next = head->next;
    
        Node* slow = head;
        Node* fast = head;
    
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
    
            if(slow == fast){
                cout << "true" << endl;
                return 0;
            }
        }
    
        cout << "false" << endl;
        return 0;
}