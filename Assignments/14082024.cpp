// Question 1
#include <iostream>
using namespace std;

int main(){
    

    char str1[50], str2[50];
    cout << "Enter the first string: ";
    cin >> str1;

    cout << "Enter the second string: ";
    cin >> str2;

    cout << str1 << str2;

    
    
    return 0;
}

// Question 2

#include <iostream>
using namespace std;

int main(){
    int sum=0;
    float avg;

    for(int i=0; i<5; i++){
        int grade;
        cout << "Enter grade "<<i+1<<": ";
        cin >> grade;
        sum += grade;
        
    }
    avg = sum/5;
    
    cout << "The average grade is: " << avg;

    
    
    return 0;
}


// Question 3
#include <iostream>
using namespace std;

int square(int number){
    
    int ans = number*number;
    
    return ans;
}

int main() {
    
    int number;
    cout << "Enter a number: ";
    cin >> number;
    
    cout << "The square of "<< number << " is: " << square(number) << endl;

    return 0;
}