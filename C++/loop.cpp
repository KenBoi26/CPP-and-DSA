// for loop

#include <iostream>
using namespace std;

int main() {
    
    // for (init;termination;inc/dec){}
    
    for(int i = 0; i<=10; i++){
        cout << i << " ";
    }
    cout << "" << endl;
    
    // find sum of the 1st 10 natural numbers
    
    int num = 10;
    int sum = 0;
    
    for (int i = 1; i<=num; i++){
        sum += i;
    }
    
    cout << "The sum is: " << sum << endl;
    
    // calculate the average
    int num1 = 10;
    int sum1 = 0;
    
    for (int i = 1; i<=num; i++){
        sum1 += i;
    }
    
    float avg = sum/num;
    
    cout << "The average is: " << avg;
    

    return 0;
}



// while loop
#include <iostream>
using namespace std;

int main() {
    
    // while(cond){}
    
    int i = 0;
    int num = 10;
    int sum = 0;
    
    while (i<=num){
        cout << i << " ";
        sum += i;
        i++;
    }
    
    int avg = sum/num;
    
    cout << "" << endl;
    cout << "The sum is: " << sum << endl;
    cout << "The avg is: " << avg << endl;
    
    
    // do while
    
    // do {} 
    // while(cond);
    
    

    return 0;
}

// break and continue

#include <iostream>
using namespace std;

int main() {
    
    for(int i = 0; i<=10; i++){
        if(i==5){
            break;
        }
        
        cout << i << " ";
    }
    
    cout << "" << endl;
    
    for(int i = 0; i<=10; i++){
        if(i==5){
            continue;
        }
        
        cout << i << " ";
    }
    

    return 0;
}