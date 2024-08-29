#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    for (int i = n-1; i >= 1; i--){
        for (int j = 0; j < i - 1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int arr[10] = {5,7,3,2,9};

    bubbleSort(arr,5);

    for (int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}