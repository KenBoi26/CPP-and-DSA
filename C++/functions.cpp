#include <iostream>
using namespace std;


/*
Function with no return type and no argument
Function with no return type and arguments
Function with return type and no argument
Function with return type and arguments
*/


void function1(string name){
    cout << "My name is " << name << endl;
}

int function_add(int a, int b){
    int ans = a + b;
    return ans;
}

int main(){
    function1("Hello");
    cout << function_add(2,3);

    return 0;
}