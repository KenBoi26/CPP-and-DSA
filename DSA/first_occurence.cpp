#include <iostream>
using namespace std;

int firstOcc(int arr[], int size, int key){
    int s = 0;
    int e = size - 1;
    int mid = (s+e)/2;

    int ans = -1;

    while(s<=e){
        if(arr[mid] == key){
            ans = mid;
            e = mid-1;
        }else if(key > arr[mid]){
            s = mid + 1;
        }else{
            e = mid-1;
        }
        mid = (s+e)/2;

        return ans;
    }
}

int lastOcc(int arr[], int size, int key){
    int s = 0;
    int e = size - 1;
    int mid = (s+e)/2;

    int ans = -1;

    while(s<=e){
        if(arr[mid] == key){
            ans = mid;
            s = mid+1;
        }else if(key > arr[mid]){
            s = mid + 1;
        }else{
            e = mid-1;
        }
        mid = (s+e)/2;

        return ans;
    }
}

int totalOcc(int arr[], int size, int key){
    // Hint: last occurence - first occurence
}

int main(){
    int arr[7] = {1,2,3,3,3,3,5};
    int key;
    
    cin >> key;
    cout << firstOcc(arr, 7, key) << endl;

    return 0;

}