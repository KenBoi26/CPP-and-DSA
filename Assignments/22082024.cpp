// Question 1

#include <iostream>
using namespace std;

int main(){
    
    int n1;
    cout << "Enter the size of the array: ";
    cin >> n1;


    cout << "Enter the array: ";
    int arr1[n1];
    for(int i=0; i<n1; i++){
        cin >> arr1[i];
    }

    int sum = 0;
    for(int i=0; i<n1; i++){
        sum += arr1[i];
    }

    cout << "Sum of the array: " << sum;
    
    return 0;
}


// Question 2

#include <iostream>
using namespace std;

int main(){
    
    int n1;
    cout << "Enter the size of the array: ";
    cin >> n1;


    cout << "Enter the array: ";
    int arr1[n1];
    for(int i=0; i<n1; i++){
        cin >> arr1[i];
    }

    int sum_odd = 0;
    int sum_even = 0;
    for(int i=0; i<n1; i++){
        if(arr1[i]%2==0){
            sum_even += arr1[i];
        }else{
            sum_odd += arr1[i];
        }
    }

    cout << "Sum of odd numbers: " << sum_odd << endl;
    cout << "Sum of even numbers: " << sum_even;
    
    return 0;
}

// Question 3

#include <iostream>
using namespace std;

int main(){
    
    int n1;
    cout << "Enter the size of the array: ";
    cin >> n1;


    cout << "Enter the array: ";
    int arr1[n1];
    for(int i=0; i<n1; i++){
        cin >> arr1[i];
    }

    int odd_count = 0;
    int even_count = 0;
    for(int i=0; i<n1; i++){
        if(arr1[i]%2==0){
            even_count += 1;
        }else{
            odd_count += 1;
        }
    }

    cout << "Number of odd numbers: " << odd_count << endl;
    cout << "Number of even numbers: " << even_count;
    
    return 0;
}