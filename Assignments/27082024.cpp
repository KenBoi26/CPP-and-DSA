// Question 1

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int* p = &n;

    cout << n << endl;
    cout << *p;

    return 0;
}