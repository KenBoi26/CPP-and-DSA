// Ques 1. Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// Input: nums = [2,2,1]
// Output: 1


#include <iostream>
using namespace std;

int main(){
    
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i != j && arr[i] == arr[j]){
                break;
            }
            if(j == n-1){
                cout << arr[i] << endl;
                return 0;
            }
        }
    }

    
    return 0;
}


// Question 2: Implement the stack using linked list

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        this->data = val;
        this->next = nullptr;
    }
};

class Stack{
    public:
    Node* top;
    Stack(){
        this->top = nullptr;
    }

    void push(int val){
        Node* n = new Node(val);
        if(top == nullptr){
            top = n;
            return;
        }
        n->next = top;
        top = n;
    }

    void pop(){
        if(top == nullptr){
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek(){
        if(top == nullptr){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty(){
        return top == nullptr;
    }

};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    cout << s.isEmpty() << endl;
    s.pop();
    s.pop();
    cout << s.isEmpty() << endl;
    s.pop();
    return 0;
}