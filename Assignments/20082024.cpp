// Question 1

#include <iostream>
using namespace std;

int main(){
    int n1;
    cout << "Enter first integer:";
    cin >> n1;

    int n2;
    cout << "Enter second integer:";
    cin >> n2;
    
    cout << "Addition: " << n1+n2 << endl;
    cout << "Subtraction: " << n1-n2 << endl;
    cout << "Multiplication: " << n1*n2 << endl;

    if(n2 == 0){
        cout << "Invalid 2nd number for division " << endl;
    } else {
        cout << "Division: " << (float) n1/n2 << endl;
    }
    
    return 0;
}


// QUestion 2
