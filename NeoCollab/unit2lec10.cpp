// You are using GCC
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteMiddleNode(struct Node* head) {
    //Type your code here
    Node* temp = head;
    int length = 1;
    
    while(temp->next != NULL){
        length++;
        temp = temp->next;
    }
    
    temp = head;
    
    for(int i=0; i<length/2 - 1; i++){
        temp = temp->next;
    }
    Node* del = temp->next;
    temp->next = temp->next->next;
    
    delete del;
    
    
    
    
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int size;
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        int value;
        scanf("%d", &value);
        insertNode(&head, value);
    }

    printf("Original Linked List: ");
    displayList(head);

    deleteMiddleNode(head);

    printf("Updated Linked List: ");
    displayList(head);

    struct Node* temp = head;
    while (head != NULL) {
        head = head->next;
        free(temp);
        temp = head;
    }

    return 0;
}


// You are using GCC
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int valueExists(struct Node* second, int value) {
    //Type your code here
    struct Node* temp = second;
    while(temp!=NULL){
        if(temp->data == value){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
    
    
    
}

void deleteNodesInSecondList(struct Node** first, struct Node* second) {
    //Type your code here
    struct Node* prev = NULL;
    struct Node* current = *first;
    
    while(current != NULL){
        if(valueExists(second, current->data)){
            if(prev == NULL){
                *first = current->next;
                
                delete current;
                current = *first;
            }else{
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
        }else{
            prev = current;
            current = current->next;
        }
    }
    
}

void displayLinkedList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteLinkedList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int areAllElementsSame(struct Node* head) {
    //Type your code here
    if(head == NULL){
        return 1;
    }
    
    int firstValue = head->data;
    struct Node* temp = head -> next;
    while(temp!=NULL){
        if(temp->data != firstValue){
            return 0;
        }
        temp = temp->next;
    }
    return 1;
    
}

int main() {
    struct Node* first = NULL;
    struct Node* second = NULL;
    int size1, size2;

    scanf("%d", &size1);
    for (int i = 0; i < size1; i++) {
        int value;
        scanf("%d", &value);
        insertNode(&first, value);
    }

    scanf("%d", &size2);
    for (int i = 0; i < size2; i++) {
        int value;
        scanf("%d", &value);
        insertNode(&second, value);
    }

    printf("Before deletion: ");
    displayLinkedList(first);

    deleteNodesInSecondList(&first, second);

    printf("After deletion: ");
    displayLinkedList(first);

    if (areAllElementsSame(first)) {
        printf("Elements in both lists are same");
    }

    deleteLinkedList(first);
    deleteLinkedList(second);

    return 0;
}