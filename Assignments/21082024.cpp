// Question 1

#include <iostream>
using namespace std;

int main() {
    
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    if(n%2 == 0){
        cout << "Even";
    }else{
        cout << "Odd";
    }

    return 0;
}


// Question 2

#include <iostream>
using namespace std;

int main() {
    
    string str;
    cout << "Enter a string: ";
    cin >> str;
    
    cout << "Reversed string: ";
    for(int i = str.length()-1; i >= 0; i--){
        cout << str[i];
    }

    return 0;
}


// Question 3

#include <iostream>
using namespace std;

int main(){

    string str;
    cout << "Enter a string: ";
    cin >> str;

    int vowel = 0;
    int consonant = 0;

    for(int i=0; i<str.length(); i++){
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u'){
            vowel += 1;
        }else{
            consonant += 1;
        }
    }
    
    cout << "Number of vowels: " << vowel << endl;
    cout << "Number of consonants: " << consonant;
    return 0;
}