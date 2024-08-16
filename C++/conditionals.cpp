#include <iostream>
using namespace std;

int main() {
    
    int num;
    cout << "Enter a number: ";
    cin >> num;
    
    if(num >= 0){
        cout << "Positive" << endl;
    } else {
        cout << "Negative" << endl;
    }
    
    //OR
    
    if(num >=0) cout << "Positive" << endl;
    
    else cout << "Negative" << endl;
    
    // else if
    
    if(num > 0){
        cout << "Positive" << endl;
    } else if(num < 0) {
        cout << "Negative" << endl;
    } else{
        cout << "Zero" << endl;
    }
    
    
    // nested if...else
    
    if(num != 0){
        if(num > 0){
            cout << "Number is Positive" << endl;
        } else {
            cout << "Number is Negative" << endl;
        }
    } else {
        cout << "Number is Zero" << endl;
    }

    return 0;
}


// Practice Question

#include <iostream>
using namespace std;

int main() {
    
    int marks;
    cout << "Enter the marks: ";
    cin >> marks;
    
    if(marks <= 100 && marks >= 0){
        if(marks >= 90) cout << "Grade A" << endl;
        else if(marks >= 80 && marks < 90) cout << "Grade B" << endl;
        else if(marks >= 70 && marks < 80) cout << "Grade C" << endl;
        else if(marks >= 60 && marks < 70) cout << "Grade D" << endl;
        else if(marks < 60) cout << "Grade F" << endl;
    } else {
        cout << "Invalid Marks" << endl;
    }
    
    

    return 0;
}


// Ternary Operator


#include <iostream>
using namespace std;

int main() {
    
    // condition ? expression1 : expression2;
    int num;
    
    cout << "Enter a number: ";
    cin >> num;
    
    string ans = (num >= 0) ? "Positive" : "Negative";
    
    cout << ans;
    
    
    string ans1 = (num == 0) ? "Zero" : (num > 0) ? "Positive" : "Negative";
    
    cout << ans1;

    return 0;
}