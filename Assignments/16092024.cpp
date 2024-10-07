// Ques 1: You are given an array of integer and target integer now you have to tell it posible to select two elements from an array such that their sum is equal to target. If it is possible then print YES otherwise print NO. Sample testcase arr :[2,7,11,15], target = 9 output : YES . Write code that work in O(n^2) complexity and O(n*logn) complexity. Take all the required input from user.

#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> arr, int target){
    int n = arr.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] + arr[j] == target){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int tar;
    cin >> tar;
    if(isPossible(arr, tar)){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}