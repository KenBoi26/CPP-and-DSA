#include <iostream>

class Stack {
private:
    int elements[100];
    int topIndex;

public:
    Stack() : topIndex(-1) {}

    void push(int element) {
        if (topIndex < 99) {
            elements[++topIndex] = element;
        } else {
            std::cout << "Stack is full. Cannot push element." << std::endl;
        }
    }

    void pop() {
        if (!empty()) {
            topIndex--;
        }
    }

    int top() {
        if (!empty()) {
            return elements[topIndex];
        }
        return -1; // or throw an exception
    }

    bool empty() {
        return topIndex == -1;
    }

    int size() {
        return topIndex + 1;
    }
};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top element: " << stack.top() << std::endl;
    std::cout << "Size: " << stack.size() << std::endl;

    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << std::endl;

    return 0;
}