// Ques 1. Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// Input: nums = [2,2,1]
// Output: 1


#include <iostream>
using namespace std;

int main(){
    
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i != j && arr[i] == arr[j]){
                break;
            }
            if(j == n-1){
                cout << arr[i] << endl;
                return 0;
            }
        }
    }

    
    return 0;
}