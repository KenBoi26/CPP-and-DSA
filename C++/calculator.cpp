// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;


int main() {
    int a,b;
    cin >> a;
    cin >> b;
    
    char oper;
    cin >> oper;
    
    if(oper == '+'){
        cout << a+b;
    }else if(oper == '-'){
        cout << a-b;
    }else if(oper == '*'){
        cout << a*b;
    }else if(oper == '/'){
        if(b==0){
            cout << "Invalid input";
        }else{
            cout << a/b;
        }
    }

    return 0;
}