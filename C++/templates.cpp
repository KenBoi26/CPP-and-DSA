// Class Templates
//  A class template is a class that can be used with different data types.


#include<iostream>
using namespace std;

template <class T>
class Calculate{
    private:
    int x,y;

    public:
    Calculate(T num1, T num2){
        x = num1;
        y = num2;
    }

    void add(){
        cout << x+y << endl;
    }
};

/*
class CalculateDecimals{
    private:
    double x,y;

    public:
    CalculateDecimals(double num1, double num2){
        x = num1;
        y = num2;
    }

    void add(){
        cout << x+y;
    }
};
*/

int main(){


    Calculate<int> obj1(5,7);
    obj1.add();

    Calculate<double> objDouble(2.2, 5.8);
    objDouble.add();

    Calculate<string> objStr("Hello ", "World");
    objStr.add();

    return 0;
}


// Function Templates
// blueprint for creating functions that operates in different data types
