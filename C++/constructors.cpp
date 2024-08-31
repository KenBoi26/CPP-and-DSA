#include<iostream>
using namespace std;



class Room{
    public:
    int length;
    int breadth;
    int height;

    Room(){
        cout << "From constructor method" << endl;
    }

    Room(int l, int b, int h){
        cout << "This" << endl;
        length = l;
        breadth = b;
        height = h;
    }

    int area(){
        return length * breadth;
    }

    int volume(){
        return length * breadth * height;
    }

};




int main(){

    Room room1;
    room1.length = 10;
    room1.breadth = 5;
    room1.height = 3;

    Room room2(4,5,8);

    cout << room2.area();

    return 0;
}