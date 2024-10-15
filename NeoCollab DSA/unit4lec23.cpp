// Question 1

// You are using GCC
#include <iostream>
using namespace std;

const int MAX_ARRAY_LENGTH = 100;
void merge_descending(char arr[], int left, int mid, int right) {
    //Type your code here
    int n1 = mid-left+1;
    int n2 = right-mid;
    
    int arr1[n1];
    int arr2[n2];
    
    for(int i=0; i<n1; i++){
        arr1[i] = arr[left+i];
    }
    
    for(int i=0; i<n2; i++){
        arr2[i] = arr[mid+i+1];
    }
    
    int i=0, j=0, k=left;
    while(i<n1 && j<n2){
        if(arr1[i] > arr2[j]){
            arr[k++] = arr1[i++];
        }else{
            arr[k++] = arr2[j++];
        }
    }
    
    while(i<n1){
        arr[k++] = arr1[i++];
    }
    
    while(j<n2){
        arr[k++] = arr2[j++];
    }
}

void mergeSortDescending(char arr[], int left, int right) {
    //Type your code here
    if(left < right){
        int mid = left + (right - left)/2;
        mergeSortDescending(arr, left, mid);
        mergeSortDescending(arr, mid+1, right);
        merge_descending(arr, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;

    char arr[MAX_ARRAY_LENGTH];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSortDescending(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}


// Question 2
// You are using GCC
#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int arr1[n1], arr2[n2];

    for (int i = 0; i < n1; i++) {
        arr1[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        arr2[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            arr[k++] = arr1[i++];
        } else {
            arr[k++] = arr2[j++];
        }
    }

    while (i < n1) {
        arr[k++] = arr1[i++];
    }
    while (j < n2) {
        arr[k++] = arr2[j++];
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

bool isValidInput(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0 && arr[i] != 1) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    if (n < 1 || n > 20) {
        cout << "Invalid input" << endl;
        return 0;
    }
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (!isValidInput(arr, n)) {
        cout << "Invalid input" << endl;
        return 0;
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

