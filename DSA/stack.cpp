#include<iostream>
#include<stack>
using namespace std;


int main(){

    stack<int> st;

    //push
    st.push(1);
    st.push(2);
    st.pop();

    cout << st.empty() << endl;

    // checking the size
    cout << "Size: " << st.size() << endl;

    // checking the top element
    cout << "Top Element: " << st.top() << endl;


    return 0;
}