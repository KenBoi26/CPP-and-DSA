#include <iostream>
using namespace std;

int main() {
    int a = 9; // takes 4 bytes
    float b = 4.5; // takes 4 bytes
    double c = 2.25; // takes 8 bytes
    char d = 'j'; // takes 1 byte
    bool e = true; // takes 1 byte
    
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(c) << endl;
    cout << sizeof(d) << endl;
    cout << sizeof(e) << endl;

    return 0;
}