// Question 1: You are given a binary array. Your task is to find the maximum number of consecutive ones in array.
// Input :- arr :[1,1,0,1,1,1]
// Output: 3

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int max=0;

    for(int i=0; i<n; i++){
        int count=0;
        if(arr[i] == 1){
            count++;
            for(int j=i+1; j<n; j++){
                if(arr[j] == 1){
                    count++;
                } else {
                    break;
                }
            }
        }
        if(count > max){
            max = count;
        }
    }

    cout << max << endl;
}