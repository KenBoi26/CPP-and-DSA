/*
#include <iostream>
using namespace std;

int main(){
    int arr[5] = {1,2,3};

    for(int i : arr){
        cout << i << " ";
    }
}
*/

#include <iostream>
using namespace std;

int getMin(int arr[], int size){
    int min = INT_MAX;

    for(int i=0; i< size; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }

    return min;
}

int main(){
    int arr[5] = {5,7,2,3,9};

    int min = getMin(arr, 5);

    cout << "Minimum: " << min << endl;
}