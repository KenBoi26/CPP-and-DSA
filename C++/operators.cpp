#include <iostream>
using namespace std;

int main(){
    // Arithmetic operators

    int a = 5;
    int b = 10;

    int ans = a+b;

    cout << ans << endl;

    // Relational Operators

    int a = 5;
    int b = 10;

    bool ans = (a == b);
    cout << ans << endl;

    bool ans = (a != b);
    cout << ans << endl;

    bool ans = (a >= b);
    cout << ans << endl;

    bool ans = (a <= b);
    cout << ans << endl;

    bool ans = (a > b);
    cout << ans << endl;

    bool ans = (a < b);
    cout << ans << endl;


    // Logical Operators

    int a = 5;
    int b = 10;

    bool ans = (a > 1) && (b < 20);

    cout << ans << endl;

    // binary operators
    int a = 12;
    int b = 25;

    int ans = a | b;

    cout << ans << endl;

    return 0;

}