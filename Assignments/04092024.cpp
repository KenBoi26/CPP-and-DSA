// Question 1
// Write a program that defines a Student class and uses the this pointer in a member function to display the student's details.

#include <iostream>
using namespace std;

class Student {
    string name;
    int age;
    int rollno;

public:
    Student(){
        cin >> name;
        cin >> age;
        cin >> rollno;
    }

    void display() {
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
        cout << "Roll no: " << this->rollno << endl;
    }
};

int main() {
    Student s1;
    s1.display();

    return 0;
}


// Question 2
// Write a C++ code that take linked list from user input and a value integer . Delete the value from the linkedlist. Sample Input :- 10->20->30->40 value = 20 Sample Output :- 10->30->40

#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    
    Node(int val)
    {
        this->data = val;
        this->next = nullptr; 
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void delete_node(int val) {
        if (head == nullptr) {
            cout << "Nothing to delete as LL doesn't exist" << endl;
            return;
        }

        // Handle deletion of head node
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp; // Free memory
            cout << "Deleted node with value " << val << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            if (temp->next->data == val) {
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
                cout << "Deleted node " << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Value " << val << " not found in the list." << endl;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    LinkedList list;

    
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    
    list.display();
    
    int val;
    cin >> val;
    list.delete_node(val);
    
    list.display();

    return 0;
}

