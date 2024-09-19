// You are using GCC
#include <iostream>

struct Node {
    char data;
    Node* next;
    
};

Node* createNode(char value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void displayList(Node* head){
    Node* current = head->next;
    while(current != nullptr){
        std::cout << current->data << " ";
        current = current->next;
    }
    
    std::cout << std::endl;
}

void insertAfterPosition(Node* head, int position, char value) {
    //Type your code here
    int length = 1;
    Node* temp1 = head;
    while(temp1!=NULL){
        temp1=temp1->next;
        length++;
    }
    
    if(position >= length){
        std::cout << "Invalid position." << std::endl;
        
        return;
    }
    
    Node* temp = head;
    int count = 0;
    
    while(temp->next != NULL && count != position){
        temp = temp->next;
        count++;
    }
    
    Node* current = createNode(value);
    current->next = temp->next;
    temp->next = current;
    
    
}


void deleteList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

int main() {
    Node* head = createNode('\0'); 
    int n;
    char value;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> value;
        insertAfterPosition(head, i, value);
    }

    int position;
    std::cin >> position;

    std::cin >> value;

    insertAfterPosition(head, position, value);
    std::cout << "Updated list: ";

    displayList(head);

    deleteList(head);

    return 0;
}



// You are using GCC
#include <iostream>

struct Node {
    int data;
    Node* next;
};

void deleteNode(Node* head, int value) {
    //Type your code here
    Node* temp = head;
    
    while(temp->next != nullptr && temp->next->data != value){
        temp=temp->next;
    }
    
    if(temp->next->data == value){
        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }else{
        return;
    }
    
}

int main() {
    Node* head = new Node();
    head->next = nullptr;

    int value;
    while (std::cin >> value && value != -1) {
        Node* newNode = new Node();
        newNode->data = value;

        newNode->next = head->next;
        head->next = newNode;
    }
    while (std::cin >> value && value != -1) {
        deleteNode(head, value);
    }

    Node* current = head->next;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    return 0;
}



// You are using GCC
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of a linked list
void insertNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to merge two linked lists alternately
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    //Type your code here
    Node* temp1 = list1;
    Node* temp2 = list2;
    Node* header = createNode(NULL);
    
    while(temp1 != nullptr && temp2 != nullptr){
        insertNode(header, temp1->data);
        insertNode(header, temp2->data);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    
    while(temp1 != nullptr){
        insertNode(header,temp1->data);
        temp1 = temp1->next;
    }
    while(temp2 != nullptr){
        insertNode(header,temp2->data);
        temp2 = temp2->next;
    }
    
    return header;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head->next->next->next;  
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node* list1 = createNode(0);  // Grounded header node for list1
    struct Node* list2 = createNode(0);  // Grounded header node for list2

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insertNode(list1, data);
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insertNode(list2, data);
    }

    struct Node* mergedList = mergeLists(list1, list2);

    displayList(mergedList);

    return 0;
}