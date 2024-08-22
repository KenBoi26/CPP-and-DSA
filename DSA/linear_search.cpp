#include <iostream>
using namespace std;


int linear_search(int arr[], int key, int range){
    for(int i=0; i<range; i++){
        if(arr[i] == key){
            cout << "Key found at index: " << i << endl;
            return 0;
        }
    }
    cout << "Key not found" << endl;
    return -1;
}


int main(){
    int arr[5] = {3,5,7,2,1};
    int key;

    cin >> key;
    
    linear_search(arr,key,5);
}