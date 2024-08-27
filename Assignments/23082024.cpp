// Question 1

#include <iostream>
using namespace std;

int main(){
    
    int n1;
    cin >> n1;

    int arr[n1];

    for(int i=0; i<n1; i++){
        cin >> arr[i];
    }

    for(int i=0; i<n1-1; i++){
        for(int j=0; j<n1-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    
    for(int i=0; i<n1; i++){
        cout << arr[i] << " ";
    }

    return 0;
}


// Question 2

#include <iostream>
using namespace std;

int main(){
    
    int n1;
    cin >> n1;

    int arr[n1];

    for(int i=0; i<n1; i++){
        cin >> arr[i];
    }

    for (int i = 1; i < n1; ++i) {
        int key = arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
    
    for(int i=0; i<n1; i++){
        cout << arr[i] << " ";
    }

    return 0;
}