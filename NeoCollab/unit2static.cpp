// Question 1


// You are using GCC
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node **head, int newID) {
    Node *newNode = createNode(newID);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node **head, int newID) {
    Node *newNode = createNode(newID);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtPosition(Node **head, int position, int newID) {
    if (position < 0) return; 

    Node *newNode = createNode(newID);
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        free(newNode);
        insertAtEnd(head, newID);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    Node *head = NULL;
    int bookID;

    for (int i = 0; i < N; i++) {
        scanf("%d", &bookID);
        insertAtEnd(&head, bookID);
    }

    int newID1, newID2, randomPosition, newID3;
    scanf("%d", &newID1);
    scanf("%d", &newID2);
    scanf("%d", &randomPosition);
    scanf("%d", &newID3);

    insertAtBeginning(&head, newID1);
    insertAtEnd(&head, newID2);
    insertAtPosition(&head, randomPosition, newID3);

    printList(head);
    freeList(head);

    return 0;
}


