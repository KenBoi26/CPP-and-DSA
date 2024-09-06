// Question 1

#include <iostream>
#include <string>
using namespace std;


int checkLength(string &str1){
    int counter = 0;
    
    for(char i : str1){
        counter++;
    }
    
    return counter;
}


int main() {
    
    string str1;
    getline(cin, str1);
    
    int length = checkLength(str1);
    
    cout << length;

    return 0;
}


// Question 2

