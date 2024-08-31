#include <iostream>
using namespace std;

class Car{
    public: // if not this then by default private
    string color;
    string name;
    int year;

};

class Student{
    public:
    string name;
    int roll;
    int age;

    Student(){
        cout << "\nThis is the default constructor.\n";
    }

    Student(string n, int r, int a){
        name = n;
        roll = r;
        age = a;

    }

    // copy constructor
    Student(Student &s1){
        name = s1.name;
        roll = s1.roll;
        age = s1.age;
    }


    // destructor
    ~Student(){
        cout << "Destructor called." << endl;
    }
};



int main(){   
    
    Car car1;
    car1.color = "Black";

    cout << "Colour of car 1 is: " << car1.color << endl;

    Student student_1;
    student_1.age=18;
    student_1.name="abc";
    student_1.roll=1;
    cout << "Name: " << student_1.name << endl;
    cout << "Age: " << student_1.age << endl;
    cout << "Roll: " << student_1.roll << endl;

    
    Student student_2;

    student_2.age=19;
    student_2.name="def";
    student_2.roll=2;
    cout << "Name: " << student_2.name << endl;
    cout << "Age: " << student_2.age << endl;
    cout << "Roll: " << student_2.roll << endl;
    


    Student student_3;
    student_3.age=20;
    student_3.name="ghi";
    student_3.roll=3;

    cout << "Name: " << student_3.name << endl;
    cout << "Age: " << student_3.age << endl;
    cout << "Roll: " << student_3.roll << endl;


    Student student_4("Kenneth",51,18);
    cout << "Name: " << student_4.name << endl;
    cout << "Age: " << student_4.age << endl;
    cout << "Roll: " << student_4.roll << endl;

    Student student_5(student_4);

    return 0;
}






#include<iostream>
using namespace std;

class Room{
    public:
    int length;
    int breadth;
    int height;

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

    cout << "The area is: " << room1.area() << endl;

    cout << "The volume is: " << room1.volume() << endl;

    return 0;
}