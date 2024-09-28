// Question 1

// You are using GCC
#include<iostream>
#include<stack>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    stack<int> st;
    
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        st.push(temp);
    }
    
    if(st.empty()){
        cout << "The STACK is empty";
        return 0;
    }
    
    int val;
    cin >> val;
    
    while(!st.empty()){
        if(st.top() == val){
            cout << "Element Found";
            return 0;
        }
        
        st.pop();
    }
    
    cout << "Element not found";
    
    
    
    
    return 0;
}


// Question 2

// You are using GCC
#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> st;
    stack<int> st2;
    
    int n;
    cin >> n;
    int count = 0;
    
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        st.push(temp);
    }
    
    while(!st.empty() && count < 2){
        for(int i=0; i<n-count; i++){
            cout << st.top() <<" ";
            st2.push(st.top());
            st.pop();
        }
        
        cout << endl;
        
        for(int i=0; i<n-count; i++){
            st.push(st2.top());
            st2.pop();
        }
        
        cout << "Top element is " << st.top();
        st.pop();
        count++;
        cout << endl;
    }
    
    if(count != 2){
        cout << "Stack is empty";
    }
    
    return 0;
    
}


// Question 3

#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* next;
};


void allocateBed(stack<Node*>& NStack, int val) {
    Node* n = new Node;
    n->data = val;
    n->next = nullptr;
    NStack.push(n);
}

void viewOriginal(stack<Node*> NStack) {
    cout << "Original Stack: ";
    while (!NStack.empty()) {
        cout << NStack.top()->data << " ";
        NStack.pop();
    }
    cout << endl;
}


void sortedInsert(stack<Node*>& s, Node* n) {
    
    if (s.empty() || n->data > s.top()->data) {
        s.push(n);
        return;
    }

    Node* temp = s.top();
    s.pop();
    sortedInsert(s, n);

    s.push(temp);
}

void sortStack(stack<Node*>& s) {
    if (s.empty()) 
        return;

    Node* temp = s.top();
    s.pop();
    sortStack(s);

    sortedInsert(s, temp);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    stack<Node*> NStack;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        allocateBed(NStack, val);
    }

    viewOriginal(NStack);

    sortStack(NStack);

    cout << "Sorted Stack: ";
    while (!NStack.empty()) {
        cout << NStack.top()->data << " ";
        NStack.pop();
    }
    cout << endl;

    return 0;
}
