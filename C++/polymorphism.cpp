// Polymorphism -> many morphism -> many forms

#include<iostream>
using namespace std;

// Compule time polymorphism
    // 1. Function overloading

    void add(int num1, int num2){
        cout << "Sum of two int: " << num1+num2 << endl;
    }

    void add(int num1, int num2, int num3){
        cout << "Sum of three int: " << num1+num2+num3 << endl;
    }

    void add(double num1, double num2){
        cout << "Sum of two doubles: " << num1+num2 << endl;
    }



int main(){

    int a = 3;
    int b = 10;
    string c = "Hello";
    string d = " World";

    cout << a+b << endl;
    cout << c+d << endl;

    add(4,5);
    add(1,2,3);
    add(1.1,2.2);





    return 0;
}