// STL --> Standard Template Library

// STL has 3 majot components
// 1. Containers
    // store and organise data in a specific manner
    // sequence containers -> Array, Vecotrs, Queue, Dequeu, List
    // associative conatiners -> Set, Multiset, Map, Multimap
    // unordered associative containers -> Unordered set, Unordered multiset, Unordered map, Unordered multimap

// 2. Iterators
    // pointers that point to the elements of the containers  


// 3. Algorithms
    // Sorting, searching, copy, count, swap, etc.


#include<iostream>
#include<array>
using namespace std;


int main(){

    // normal array
    int arr1[5] = {1,2,3,4,5};

    // STL array
    array<int, 5> arr2 = {1,2,3,4,5};

    cout << arr2.size();




    return 0;
}
