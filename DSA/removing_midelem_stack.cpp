// Iterative Method

#include <iostream>
#include <stack>
using namespace std;


void deleteMid(stack<int>& s, int sizeOfStack) {
    stack<int> tempStack;
    int mid = sizeOfStack / 2;  
    for (int i = 0; i < mid; i++) {
        tempStack.push(s.top());
        s.pop();
    }
    s.pop();
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {
    stack<int> myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);

    deleteMid(myStack, 5);

    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }

    return 0;
}


// Recursive Method
#include <iostream>
#include <stack>
using namespace std;

void deleteMid(stack<int> &st, int count, int size){
    if(st.empty() || count == size/2){
        st.pop();
        return;
    }

    int num = st.top();
    st.pop();

    deleteMid(st, count+1, size);

    st.push(num);
}