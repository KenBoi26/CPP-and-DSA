#include <iostream>
using namespace std;

int selection_sort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        int min = i;
        for(int j=i+1; j<size; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr[i],arr[min]);
    }

    for(int i=0; i<5; i++){
        cout << arr[i];
    }

    return -1;
}

int main(){
    int arr[5] = {5,7,2,3,9};

    selection_sort(arr,5);

    return 0;
}