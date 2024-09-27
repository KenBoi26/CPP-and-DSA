// Question 1
// Write a program that defines a Student class and uses the this pointer in a member function to display the student's details.

#include <iostream>
using namespace std;

class Student {
    string name;
    int age;
    int rollno;

public:
    Student(){
        cin >> name;
        cin >> age;
        cin >> rollno;
    }

    void display() {
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
        cout << "Roll no: " << this->rollno << endl;
    }
};

int main() {
    Student s1;
    s1.display();

    return 0;
}
