#include<iostream>
using namespace std;

// operator overloading
// compile time polymorphism

class Counter{
    private:
    int value;

    public:
    Counter(int val){
        value = val;
    }

    // ++ -> increments value by 1

    void operator ++(){
        value += 50;
    }
    void operator ++(int){
        value += 50;
    }

    void print(){
        cout << "The counter value is: " << value << endl;
    }
};


int main(){

    Counter c1(5);
    c1.print();

    ++c1;
    c1.print();
    c1++;
    c1.print();


    return 0;
}