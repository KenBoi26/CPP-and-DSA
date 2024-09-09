#include<iostream>
using namespace std;

/*
- Each variable uses space on computer's memory to store it's value
- Where we use the term allocate, we indicate that the variable has been given a space on the computer's memory.
- Deallocation means space has been recalaimed by computer and the variable cannt be accessed now.

- Memory allocation in cpp is done by two methods.
    One of them is Static Memory Allocation which is also called Compile time allocation.
    And the other is known as Dynamic memory allocation which is also known as Run Time Allocation

    - Static Memory Allocation:
    
    In static memory allcocation, size and location where variable will be stored is fixed during compile time.

    main(){
        int x;
        char ch;
        int arr[100];
    }

    - In this, compiler calculates how much memoery these variable(c,ch,arr) will need and fix a location where these variables will be created.
    - location of where variables will be stored is saved, but actual physical memory is not allocated at compile time.

    - Actual physical memory is allocated at runtime.

    - Static memory allocation is slightly faster than dynamic.
    - Allocation and deallocation of memory is done by the compiler itself

    - Dynamic Memory Allocation:
    - DMA, allows you to define memory requirement during execution  of the program.
    -DMA uses a special type of memory called as heap memory.
    - here, new keyboard is used to allocate memory and delete keyword is used to deallocate

    

*/

int main(){




    return 0;
}