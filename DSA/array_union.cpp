#include <iostream>

using namespace std;

void unionArrays(int arr1[], int n1, int arr2[], int n2, int arr3[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        } else if (arr2[j] < arr1[i]) {
            arr3[k++] = arr2[j++];
        } else {
            i++;
            j++;
        }
    }

    while (i < n1) {
        arr3[k++] = arr1[i++];
    }

    while (j < n2) {
        arr3[k++] = arr2[j++];
    }
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {2, 4, 6, 8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[n1 + n2];

    unionArrays(arr1, n1, arr2, n2, arr3);

    cout << "Merged array: ";
    for (int i : arr3) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}