#include<iostream>
#include<string>
#include<stack>
using namespace std;



void reverseSentence(string s){

    stack<string> st;

    for(int i=0; i<s.length(); i++){
        string temp = "";
        
        while(s[i] != ' ' && i<s.length()){
            temp += s[i];
            i++;
        }

        // found space
        st.push(temp);


    }

    // print the word from the stack
    // by continuously popping the stack

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}




int main(){

    string sentence = "Hello World! How are you doing?";

    reverseSentence(sentence);


    return 0;
}