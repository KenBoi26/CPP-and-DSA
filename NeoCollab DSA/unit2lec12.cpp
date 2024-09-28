// Question 1

#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* createNode(int newData) {
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

void insert(Node*& header, int newData) {
    Node* newNode = createNode(newData);
    
    if (header->next == nullptr) {
        header->next = newNode;
        newNode->next = header;
    } else {
        Node* current = header->next;
        while (current->next != header) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = header;
    }
}

void printAlternateNodes(const Node* header) {
    if (header->next == nullptr) {
        std::cout << "Linked List is empty";
        return;
    }
    
    std::cout << "Alternate Nodes: ";
    bool printNode = true;
    const Node* current = header->next;
    while (current != header) {
        if (printNode) {
            std::cout << current->data << " ";
        }
        printNode = !printNode;
        current = current->next;
    }
    std::cout << std::endl;
}

void deleteList(Node*& header) {
    if (header->next == nullptr) {
        delete header;
        header = nullptr;
        return;
    }
    Node* current = header->next;
    Node* nextNode;
    while (current != header) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    delete header;
    header = nullptr;
}

int main() {
    Node* header = new Node;
    header->next = nullptr;
    int listSize;
    std::cin >> listSize;
    for (int i = 0; i < listSize; i++) {
        int newData;
        std::cin >> newData;
        insert(header, newData);
    }
    printAlternateNodes(header);
    deleteList(header);
    return 0;
}

// Question 2
#include <iostream>

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* header;

public:
    CircularLinkedList() {
        header = new Node();
        header->next = header;
    }

    void insert(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        
        if (header->next == header) {
            header->next = newNode;
            newNode->next = header;
        } else {
            Node* temp = header;
            while (temp->next != header) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = header;
        }
    }

    void deleteAtPosition(int position) {
        if (header->next == header) {
            std::cout << "Invalid position." << std::endl;
            return;
        }

        int count = 1;
        Node* temp = header->next;
        Node* prev = header;

        while (temp != header && count < position) {
            prev = temp;
            temp = temp->next;
            count++;
        }

        if (temp == header || count < position) {
            std::cout << "Invalid position." << std::endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    void display() {
        std::cout << "Contents of the CLL:" << std::endl;
        if (header->next == header) {
            std::cout << "Empty list" << std::endl;
            return;
        }

        Node* temp = header->next;
        while (temp != header) {
            std::cout << "|" << temp->data << "| --> ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    ~CircularLinkedList() {
        if (header->next == header) {
            delete header;
            return;
        }

        Node* temp = header->next;
        Node* next;
        while (temp != header) {
            next = temp->next;
            delete temp;
            temp = next;
        }
        delete header;
    }
};

int main() {
    CircularLinkedList cll;

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int data;
        std::cin >> data;
        cll.insert(data);
    }

    cll.display();

    int position;
    std::cin >> position;

    std::cout << "After deleting at position " << position << ":" << std::endl;
    cll.deleteAtPosition(position);
    cll.display();

    return 0;
}