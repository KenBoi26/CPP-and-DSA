#include <iostream>
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


Node* reverseKGroup(Node* head, int k) {
    if (!head || k == 1) return head;
    
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    
    int count = 0;
    
    Node* temp = head;
    
    for (int i = 0; i < k; i++) {
        if (!temp) return head;
        temp = temp->next;
    }
    
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    if (next != NULL) {
        head->next = reverseKGroup(next, k);
    }
    
    return prev;
}
void display(Node* head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main(){
	Node* a= new Node(10);
	Node* b= new Node(20);
	Node* c= new Node(30);
	Node* d= new Node(40);
	Node* e= new Node(50);
	Node* f= new Node(60);
	a->next=b;
	b->next=c;
	c->next=d;
	d->next=e;
	e->next=f;
	
	Node*temp=reverseKGroup(a,3);
	display(temp);
	
	return 0;
}