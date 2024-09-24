#include<iostream>
using namespace std;


class Rectangle{
    private: // access modifiers
    int length;
    int breadth;

    public: // access modifiers

    // setters for length
    void setLength(int l){
        length = l;
    }

    // getter for length
    int getLength(){
        return length;
    }


    // setter for breadth
    void setBreadth(int b){
        breadth = b;
    }

    // getter for breadth
    int getBreadth(){
        return breadth;
    }



    /*
    int getArea(){
        return length * breadth;
    }
    */
};


int main(){

    Rectangle r1;
    r1.setLength(10);

    cout << "Length: " << r1.getLength();
    cout << "Breadth: " << r1.getBreadth();


    return 0;
}