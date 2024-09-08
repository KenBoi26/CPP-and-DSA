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

#include <iostream>
#include <string>
using namespace std;


int characterCount(string str1, char ch){
    int counter = 0;

    for(char i : str1){
        if(i==ch){
            counter += 1;
        }
    }

    return counter;
}




int main() {
    
    string str1;
    getline(cin, str1);
    
    char ch;
    cin >> ch;

    int counter = characterCount(str1, ch);
    
    cout << counter;

    return 0;
}

// Question 3
#include <iostream>
#include <string>
using namespace std;

string concatenateStrings(const string &str1, const string &str2){
    return str1 + str2;
}


int main(){
    
    string str1;
    string str2;

    cout << "str1 = ";
    getline(cin, str1);

    cout << "str2 = ";
    getline(cin, str2);

    string concatenated = concatenateStrings(str1,str2);

    cout << concatenated;
    
    
    return 0;
}