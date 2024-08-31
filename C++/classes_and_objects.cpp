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
};



int main(){   
    
    Car car1;
    car1.color = "Black";

    cout << "Colour of car 1 is: " << car1.color << endl;

    Student student_1;
    student_1.age=18;
    student_1.name="abc";
    student_1.roll=1;
    cout << "Name of student 1 is: " << student_1.name << endl;
    cout << "Age of student 1 is: " << student_1.age << endl;
    cout << "Roll of student 1 is: " << student_1.roll << endl;

    
    Student student_2;

    student_2.age=19;
    student_2.name="def";
    student_2.roll=2;
    cout << "Name of student 2 is: " << student_2.name << endl;
    cout << "Age of student 2 is: " << student_2.age << endl;
    cout << "Roll of student 2 is: " << student_2.roll << endl;
    


    Student student_3;
    student_3.age=20;
    student_3.name="ghi";
    student_3.roll=3;

    cout << "Name of student 3 is: " << student_3.name << endl;
    cout << "Age of student 3 is: " << student_3.age << endl;
    cout << "Roll of student 3 is: " << student_3.roll << endl;


    return 0;
}