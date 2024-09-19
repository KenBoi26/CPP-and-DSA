// Question 1
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
    
}


void insert(Node* &head, int val){
    Node* n = new Node(val);
    Node* temp = head;
    
    if(head == nullptr || head->data >= val){
        n->next = head;
        head = n;
        return;
    }
    
    while(temp->next != nullptr && temp->next->data <= val){
        temp = temp->next;
    }
    
    n->next = temp->next;
    temp->next = n;
    
}


void display(Node* head){
    Node* temp = head;
    
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}


int main(){
    
    Node* head = nullptr;
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        insertAtTail(head, num);
    }
    
    cout << "Original data points: ";
    display(head);
    cout << endl;
    
    int num1;
    cin >> num1;
    
    insert(head, num1);
    
    cout << "Updated data points: ";
    display(head);
    
    return 0;
}



// Question 2
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* head, int data) {
    if (head == NULL)
        head = createNode(data);
    else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = createNode(data);
    }
    return head;
}

struct Node* leftShiftLinkedList(struct Node* head, int k) {
    //Type your code here
    if(k==0){
        return head;
    }
    
    int length = 1;
    Node* tail = head;
    while (tail->next != NULL){
        tail = tail->next;
        length++;
    }
    
    k %= length;
    
    if(k==0){
        return head;
    }
    
    struct Node* newT = head;
    for(int i=1; i<k; i++){
        newT = newT->next;
    }
    
    tail->next = head;
    head = newT->next;
    newT->next = NULL;
    
    return head;
    
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int N, k;
    scanf("%d", &N);

    struct Node* head = NULL;
    for (int i = 0; i < N; i++) {
        int value;
        scanf("%d", &value);
        head = insertNode(head, value);
    }

    scanf("%d", &k);

    head = leftShiftLinkedList(head, k);

    printList(head);

    return 0;
}