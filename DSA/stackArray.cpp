#include <iostream>
using namespace std;

class MyStack {
    int* arr;
    int size;
    int top;

public:
    // Constructor to initialize stack
    MyStack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    // Destructor to clean up allocated memory
    ~MyStack() {
        delete[] arr;
    }

    // Push function to add an element to the stack
    void push(int val) {
        if (top == size - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = val;
    }

    // Pop function to remove an element from the stack
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }

    // Function to check if the stack is empty
    bool empty() {
        return top == -1;
    }

    // Peek function to get the top element of the stack
    int peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1; // Return an invalid value to indicate stack is empty
        }
        return arr[top];
    }

    // Display function to show all elements in the stack
    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    MyStack stack(size);

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Stack after pushing 10, 20, 30: ";
    stack.display();

    cout << "Top element is: " << stack.peek() << endl;

    stack.pop();
    cout << "Stack after popping an element: ";
    stack.display();

    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl;

    return 0;
}
