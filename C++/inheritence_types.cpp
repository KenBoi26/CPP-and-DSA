// types of inheritence

/*
Single Inheritence:
class Base{

};







// Multiple Inheritence

class A{
    public:
    int numA = 10;

    void print(){
        cout << numA;
    }
};

class B : public A{
    public:
    int numB = 20;

    void print1(){
        cout << numB;
    }
};

class C : public B{
    public:
    int numC = 30;

    void print2(){
        cout << numC;
    }
};


#include<iostream>
using namespace std;


int main(){


    A a1;
    a1.print();

    B b1;
    b1.print1();

    C c1;
    c1.print2();




    return 0;
}

*/


// Multiple Inheritence

class A{
    public:
    int numA = 10;

    void print(){
        cout << numA;
    }

};

class B{
    public:
    int numB = 20;

    void print(int a){
        cout << numB;
    }
};

class C : public A, public B{

};

#include<iostream>
using namespace std;


int main(){

    C c1;
    c1.print();


    return 0;
}