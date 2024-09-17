#include<iostream>
#include<vector>
using namespace std;

void merge(vector < int > & arr, int s, int mid, int e){
    vector <int> temp;

    int i = s;
    int j = mid + 1;

    while(i <= mid && j <= e){
        if(arr[i] < arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= e){
        temp.push_back(arr[j]);
        j++;
    }

    for(int i=s; i<=e; i++){
        arr[i] = temp[i-s];
    }


}


void mergeSortMethod(vector < int > & arr, int s, int e) {
    if (s >= e) {
        return;
    }

    int mid = (s + e) / 2;

    mergeSortMethod(arr, s, mid);
    mergeSortMethod(arr, mid + 1, e);

    merge(arr, s, (s+e)/2,e);
}


void mergeSort(vector < int > & arr, int n) {
    mergeSortMethod(arr, 0, n-1);
}

int main(){




    return 0;
}