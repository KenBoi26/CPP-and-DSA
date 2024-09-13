#include <iostream>
using namespace std;

int main() {

    int* var = new int;

    *var = 10;

    cout << *var << endl;

    return 0;
}