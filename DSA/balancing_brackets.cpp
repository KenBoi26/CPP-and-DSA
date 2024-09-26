#include<iostream>
#include<string>
#include<stack>
using namespace std;


bool isBalanced(string s){

    stack<char> st;
    bool flag = true;

    for(int i=0; i<s.size(); i++){
        if(s[i] == '[' || s[i] == '{' || s[i] == '('){
            st.push(s[i]);
        }else if(s[i] == ']'){
            if(!st.empty() && st.top() == '['){
                st.pop();
            }else{
                flag = false;
                break;
            }
        }else if(s[i] == '}'){
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }else{
                flag = false;
                break;
            }
        }else if(s[i] == ')'){
            if(!st.empty() && st.top() == '('){
                st.pop();
            }else{
                flag = false;
                break;
            }
        }
    }

    return flag && st.empty();
}



int main(){

    string s = "{[()]}";

    if(isBalanced(s)){
        cout << "Balanced";
    }else{
        cout << "Not Balanced";
    }


    return 0;
}