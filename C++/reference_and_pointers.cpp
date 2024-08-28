#include <iostream>
using namespace std;

int main(){
    int a=5;

    int *ptr = &a;

    cout << a <<endl;
    cout << &a << endl;
    cout << ptr << endl;

    *ptr = *ptr + 1;
    cout << *ptr << endl;

    ptr = ptr + 1;
    cout << ptr << endl;

    return 0;
}

// whenever creating a pointer point it somewhere.


// Types of pointers:
/*
1. Null pointer --> a pointer that does not point to anything
int *ptr = NULL;

2. Dangling Pointer --> a pointer that points to a memory location that has been deallocated

3. Void Pointer --> a pointer that does not have any data type

4. Wild Pointers --> a pointer that has not been initialized
*/

#include <iostream>
using namespace std;

int main(){
    int arr[10] = {5,7,3,2,9};

    cout << arr << endl; // address of the first element

    cout << arr[0] << endl; // element at 0

    cout << *arr << endl;

    cout << *arr + 1 << endl;

    cout << *(arr) + 1 << endl;

    cout << (arr + 1) << endl;
}