#include<iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r){
    int n1 = mid-l+1;
    int n2 = r-mid;

    int arr1[n1];
    int arr2[n2];

    for(int i=0; i<n1; i++){
        arr1[i] = arr[l+i];
    }

    for(int i=0; i<n2; i++){
        arr2[i] = arr[mid+1+i];
    }

    int i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(arr1[i] < arr2[j]){
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

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int mid = l + (r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

int main(){


    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = 6;

    mergeSort(arr, 0, n-1);

    for(int i=0; i<6; i++){
        cout << arr[i] << " ";
    }

    return 0;
}