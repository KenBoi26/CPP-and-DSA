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


Node* reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}


int main(){




    return 0;
}