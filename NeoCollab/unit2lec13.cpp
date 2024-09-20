// Question 1
// You are using GCC
#include <iostream>
#include <string>

struct Node {
    std::string data;
    Node* prev;
    Node* next;
};

// Function to split a doubly linked list into two halves
void splitDoublyLinkedList(Node* head, Node** firstHalf, Node** secondHalf) {
    if (head == nullptr || head->next == nullptr) {
        *firstHalf = head;
        *secondHalf = nullptr;
        return;
    }

    Node* slow = head;
    Node* fast = head;

    // Find the middle of the list
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split the list
    *firstHalf = head;
    *secondHalf = slow->next;
    slow->next = nullptr;

    // Update prev pointers
    if (*secondHalf != nullptr) {
        (*secondHalf)->prev = nullptr;
    }
}

// Function to insert a node at the end of a doubly linked list
void insertAtEnd(Node** head, const std::string& newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;

    if (*head == nullptr) {
        newNode->prev = nullptr;
        *head = newNode;
        return;
    }

    Node* lastNode = *head;
    while (lastNode->next != nullptr) {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
    newNode->prev = lastNode;
}

// Function to display a doubly linked list
void displayLinkedList(Node* head) {
    Node* currentNode = head;

    while (currentNode != nullptr) {
        std::cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }

    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;
    Node* firstHalf = nullptr;
    Node* secondHalf = nullptr;

    int n;
    std::string name;

    std::cin >> n;
    std::cin.ignore(); // Ignore the newline character

    for (int i = 0; i < n; i++) {
        std::getline(std::cin, name);
        insertAtEnd(&head, name);
    }

    //displayLinkedList(head);

    splitDoublyLinkedList(head, &firstHalf, &secondHalf);

    displayLinkedList(firstHalf);

    displayLinkedList(secondHalf);

    return 0;
}


// Question 2
// You are using GCC
#include <stdio.h>
#include <stdlib.h>

// Node structure for two-way linked list
struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert a new node at the end of the list
void insertAtTail(struct Node** head, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    
    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    
    last->next = newNode;
    newNode->prev = last;
}

// Function to display the list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%c", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to rotate the list by k positions
void rotateByN(struct Node** head, int pos) {
    if (*head == NULL || pos == 0) {
        return;
    }
    
    struct Node* current = *head;
    int count = 1;
    
    while (count < pos && current != NULL) {
        current = current->next;
        count++;
    }
    
    if (current == NULL) {
        return;
    }
    
    struct Node* kthNode = current;
    
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = *head;
    (*head)->prev = current;
    *head = kthNode->next;
    (*head)->prev = NULL;
    kthNode->next = NULL;
}


// Main function
int main() {
    struct Node* head = NULL;
    int n, k;
    char data;

    // Input number of nodes
    scanf("%d", &n);
    getchar(); // To consume the newline character

    // Input characters and create the list
    for (int i = 0; i < n; i++) {
        scanf("%c", &data);
        getchar(); // To consume the newline character
        insertAtTail(&head, data);
    }

    // Input number of positions to rotate
    scanf("%d", &k);

    // Rotate the list by k positions
    rotateByN(&head, k);

    // Display the rotated list
    display(head);

    return 0;
}


// Question 3
// You are using GCC
#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertAtBeginning(Node** head, int newData) {
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->prev = nullptr;
    newNode->next = *head;

    if (*head != nullptr)
        (*head)->prev = newNode;

    *head = newNode;
}

void reverseList(Node** head) {
    
    if (*head == nullptr) {
        return; 
    }

    Node* curr = *head;
    Node* temp = nullptr;

    
    while (curr != nullptr) {
        temp = curr->prev; 
        curr->prev = curr->next; 
        curr->next = temp; 
        curr = curr->prev; 
    }

    if (temp != nullptr) {
        *head = temp->prev;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;
    int n, data;

    std::cin >> n;

    // Create the doubly linked list
    for (int i = 0; i < n; i++) {
        std::cin >> data;
        insertAtBeginning(&head, data);
    }

    std::cout << "Original List: ";
    printList(head);

    // Reverse the list
    reverseList(&head);

    std::cout << "Reversed List: ";
    printList(head);

    return 0;
}