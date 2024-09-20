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


// Question 3
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int membershipNumber;
    struct Node *next;
} Node;

Node* createNode(int membershipNumber) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->membershipNumber = membershipNumber;
    newNode->next = NULL;
    return newNode;
}

int isMemberInList(Node* head, int membershipToCheck) {
    Node* current = head;
    while (current != NULL) {
        if (current->membershipNumber == membershipToCheck) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);

    Node* head = NULL;
    Node* tail = NULL;

    
    for (int i = 0; i < N; i++) {
        int membershipNumber;
        scanf("%d", &membershipNumber);
        Node* newNode = createNode(membershipNumber);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int membershipToCheck;
    scanf("%d", &membershipToCheck);


    if (isMemberInList(head, membershipToCheck)) {
        printf("Membership number %d is active\n", membershipToCheck);
    } else {
        printf("Membership number %d is not in the list\n", membershipToCheck);
    }

    return 0;
}


// Question 4
#include <iostream>
using namespace std;

class Node {
public:
    int petCode;
    Node* next;

    Node(int petCode) : petCode(petCode), next(nullptr) {}
};

Node* createNode(int petCode) {
    return new Node(petCode);
}

void printList(Node* head) {
    if (head == nullptr) {
        return;
    }
    
    Node* temp = head;
    do {
        cout << temp->petCode << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

Node* insertAtEnd(Node* head, int newPetCode) {
    Node* newNode = createNode(newPetCode);
    if (head == nullptr) {
        newNode->next = newNode;
        return newNode;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    
    return head;
}

Node* removeByCode(Node* head, int petToRemove) {
    if (head == nullptr) {
        return nullptr;
    }

    if (head->next == head && head->petCode == petToRemove) {
        delete head;
        return nullptr;
    }

    Node* temp = head;
    Node* prev = nullptr;

    if (head->petCode == petToRemove) {
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return head;
    }

    temp = head;
    do {
        prev = temp;
        temp = temp->next;
        if (temp->petCode == petToRemove) {
            prev->next = temp->next;
            delete temp;
            return head;
        }
    } while (temp != head);

    return head;
}

int main() {
    int N;
    cin >> N;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < N; i++) {
        int petCode;
        cin >> petCode;
        Node* newNode = createNode(petCode);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    int newPetCode, petToRemove;
    cin >> newPetCode;
    cin >> petToRemove;

    head = insertAtEnd(head, newPetCode);
    printList(head);

    head = removeByCode(head, petToRemove);
    printList(head);

    return 0;
}


// Question 5
#include <iostream>
using namespace std;

struct Node {
    int recipeCode;
    Node* prev;
    Node* next;
    
    Node(int code) : recipeCode(code), prev(nullptr), next(nullptr) {}
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->recipeCode << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtEnd(Node** head, Node** tail, int newRecipeCode) {
    Node* newNode = new Node(newRecipeCode);
    if (*head == nullptr) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

void removeByCode(Node** head, Node** tail, int recipeToRemove) {
    if (*head == nullptr) {
        return;
    }

    Node* temp = *head;


    if (temp->recipeCode == recipeToRemove) {
        if (temp->next != nullptr) {
            *head = temp->next;
            (*head)->prev = nullptr;
        } else {
            *head = nullptr;
            *tail = nullptr;
        }
        delete temp;
        return;
    }


    while (temp != nullptr && temp->recipeCode != recipeToRemove) {
        temp = temp->next;
    }

   
    if (temp != nullptr) {
        if (temp->next != nullptr) {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        } else {
            temp->prev->next = nullptr;
            *tail = temp->prev;
        }
        delete temp;
    }
}

int main() {
    int N;
    cin >> N;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < N; i++) {
        int recipeCode;
        cin >> recipeCode;
        insertAtEnd(&head, &tail, recipeCode);
    }

    int newRecipeCode, recipeToRemove;
    cin >> newRecipeCode;
    cin >> recipeToRemove;

    insertAtEnd(&head, &tail, newRecipeCode);
    printList(head);

    removeByCode(&head, &tail, recipeToRemove);
    printList(head);

    return 0;
}
