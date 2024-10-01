// Ques 1: Write C++ program that create a stack using Array.

#include <iostream>
using namespace std;

class Stack{
    public:
    int* arr;
    int top;
    int size;

    Stack(int n){
        this->size = n;
        this->arr = new int[n];
        this->top = -1;
    }

    void push(int x){
        if(top == size-1){
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;

    }

    void pop(){
        if(top == -1){
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }
    
    int peek(){
        if(top == -1){
            cout << "Stack is Empty" << endl;
            return -1;
        }

        return arr[top];
    }

    bool isEmpty(){
        return top == -1;
    }
    

};



// Ques 2 : Write C++ program that take n from the user the number of elements and insert all the value inside stack after inserting all value inside stack pop all the values and print. 
// Input: n=5 values = 1,2,3,4,5 
// Output :- 5,4,3,2,1.

#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;

    stack<int> st;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        st.push(x);
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}