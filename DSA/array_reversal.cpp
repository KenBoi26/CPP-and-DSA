#include <iostream>
using namespace std;

int main(){
    
    int arr[5] = {5,7,2,3,9};

    int i = 0;
    int j = 0;

    while (i<=j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    
    
    return 0;
}