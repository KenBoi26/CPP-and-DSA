// Question 1
#include <iostream>
#include <stack>
using namespace std;

class TextEditor{
    stack<char> st;
    public:
    void push(char c){
        if(st.size() < 100){
            st.push(c);
            cout << "Typed character: " << c << endl;
        }else{
            cout << "Editor is full." << endl;
        }
    }
    
    void pop(){
        if (st.empty()) {
            cout << "Text editor buffer is empty. Nothing to undo." << endl;
        } else {
            char ch = st.top();
            st.pop();
            cout << "Undo: Removed character " << ch << endl;
        
        }
    }
    
    void display(){
        if(st.empty()){
            cout << "Text editor buffer is empty." << endl;
        }else{
            stack<char> temp(st);
            cout << "Current text: ";
            while (!temp.empty()) {
                char ch = temp.top();
                cout << ch << " ";
                temp.pop();
            }
            cout << endl;
        }
    }

};


int main(){
    
    
    TextEditor editor;
    int choice;
    char ch;

    while (true) {
        cin >> choice;
        if(choice == 1){
            cin >> ch;
            editor.push(ch);
        }else if(choice == 2){
            editor.pop();
        }else if(choice == 3){
            editor.display();
        }else if(choice == 4){
            return 0;
        }else{
            cout << "Invalid choice";
        }
        
    }
    
    return 0;
}


// Question 2
// You are using GCC
#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedListStack {
    Node* top;

public:
    LinkedListStack() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << value << " is pushed onto the stack" << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
        } else {
            Node* temp = top;
            cout << top->data << " is popped from the stack" << endl;
            top = top->next;
            delete temp;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            Node* temp = top;
            cout << "Elements in the stack: ";
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    LinkedListStack stack;
    int choice, value;

    while (true) {
        cin >> choice;
        
        if(choice == 1){
            cin >> value;
            stack.push(value);
        }else if(choice == 2){
            stack.pop();
        }else if(choice == 3){
            stack.display();
        }else if(choice == 4){
            cout << "Exiting the program" << endl;
            return 0;
        }else{
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}


// Question 3
// You are using GCC
#include <iostream>
using namespace std;

class Queue {
    int arr[5];
    int front, rear, size;

public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(int ticketID) {
        if (size == 5) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        rear = (rear + 1) % 5;
        arr[rear] = ticketID;
        size++;
        cout << "Helpdesk Ticket ID " << ticketID << " is enqueued." << endl;
    }

    void dequeue() {
        if (size == 0) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Dequeued Helpdesk Ticket ID: " << arr[front] << endl;
        front = (front + 1) % 5;
        size--;
    }

    void display() {
        if (size == 0) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Helpdesk Ticket IDs in the queue are: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % 5] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, ticketID;

    while (true) {
        cin >> choice;
        
        if(choice == 1){
            cin >> ticketID;
            q.enqueue(ticketID);
        }else if(choice == 2){
            q.dequeue();
        }else if(choice == 3){
            q.display();
        }else if(choice == 4){
            cout << "Exiting the program" << endl;
            return 0;
        }else{
            cout << "Invalid option." << endl;
        }
    }
    
    return 0;
}


// Question 4
// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int customerID;
    Node* next;
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int customerID) {
        Node* newNode = new Node();
        newNode->customerID = customerID;
        newNode->next = nullptr;
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Customer ID " << customerID << " is enqueued" << endl;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        cout << "Dequeued customer ID: " << front->customerID << endl;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        cout << "Customer IDs in the queue are: ";
        while (temp != nullptr) {
            cout << temp->customerID << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, customerID;

    while (true) {
        cin >> choice;
        if (choice == 1) {
            cin >> customerID;
            q.enqueue(customerID);
        } else if (choice == 2) {
            q.dequeue();
        } else if (choice == 3) {
            q.display();
        } else if (choice == 4) {
            return 0;
        } else {
            cout << "Invalid option" << endl;
        }
    }

    return 0;
}


// Question 5
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Patient {
    string name;
    int severity;
};

bool compare(const Patient& a, const Patient& b) {
    return a.severity > b.severity;
}

int main() {
    int N;
    cin >> N;
    vector<Patient> patients;
    
    for (int i = 0; i < N; ++i) {
        Patient p;
        cin >> p.name >> p.severity;
        patients.push_back(p);
    }
    
    sort(patients.begin(), patients.end(), compare);
    
    for (const auto& p : patients) {
        cout << "Treating patient: " << p.name << " (Severity: " << p.severity << ")" << endl;
    }
    
    return 0;
}
