#include<iostream>
using namespace std;

void printNum(int n){ // tail recursion

    // base case
    if(n==0) return;

    cout << n << " ";

    // recursive relation
    printNum(n-1);
}

int power(int n){

    if (n==0) return 1;

    return 2 * power(n-1);
}


int main(){


    printNum(5);

    cout << power(10);

    return 0;
}