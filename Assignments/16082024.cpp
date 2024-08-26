// Question 1

#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter a number:";
    cin >> n;
    
    int sum = 0;
    for(int i=1; i<=n; i++){
        sum += i;
    }
    


    cout << "The sum of first " << n << " natural numbers is: " << sum;
    
    return 0;
}


// Question 2
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter a number:";
    cin >> n;
    
    int fact = 1;
    for(int i=1; i<=n; i++){
        fact *= i;
    }

    cout<<"factorial: "<<fact;


    return 0;
}


// Question 3

#include <iostream>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    for(int i=1; i<=10; i++){
        cout << n <<" x " << i << " = " << n*i << endl;
    }
    
    
    return 0;
}
