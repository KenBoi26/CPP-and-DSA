// Ques 1: Write a C++ code that take 2D array and key from user. Now you have to check that key exist inside the array or not if it exits print YES otherwise NO.

#include<iostream>
using namespace std;


bool keyExists(int arr2[10][10], int key, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr2[i][j] == key){
                return true;
            }
        }
    }

    return false;
}



int main(){

    int n,m;
    cin >> n >> m;
    int arr2[10][10];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr2[i][j];
        }
    }

    int key;
    cin >> key;

    if(keyExists(arr2, key, n, m)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }


    return 0;
}