#include <iostream>
using namespace std;

int main(){
    // implicit

    int int_num = 5;

    double double_num;

    double_num = int_num;

    cout << double_num << endl;
    
    
    // explicit

    int int_num = 5;

    double double_num;

    double_num = (double)int_num;

    cout << double_num << endl;

    // c++ way

    float float_num = 2.45;

    int int_num = static_cast<int>(float_num);

    cout << int_num << endl;

    // converting string to integer

    string a = "1234";

    stoi(a);

    cout << a << endl;
    cout << a << endl;
    
    
    return 0;
}