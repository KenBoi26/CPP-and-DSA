// Question 1

#include <iostream>
using namespace std;

bool found(int arr[],int target, int size){
    for(int i = 0; i < size; i++){
        if(arr[i] == target){
            return true;
        }
    }
    return false;
}


int main(){
    int arr[] = {1,2,3,4,5,6};
    int num;

    cout << "Target: ";
    cin >> num;

    if(found(arr, num,6)){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}