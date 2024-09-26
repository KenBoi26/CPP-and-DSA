#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string firstName;
    string lastName;
    int age;

public:
    
    Person(string fName, string lName, int a) 
        : firstName(fName), lastName(lName), age(a) {}

    
    string getFullName() {
        return firstName + " " + lastName;
    }

    
    void getDetails(string& fName, string& lName, int& a) {
        fName = firstName;
        lName = lastName;
        a = age;
    }
};

int main() {
    
    Person person("John", "Doe", 30);

    
    string fullName = person.getFullName();
    cout << "Full Name: " << fullName << endl;

    
    string fName, lName;
    int a;
    person.getDetails(fName, lName, a);
    cout << "First Name: " << fName << endl;
    cout << "Last Name: " << lName << endl;
    cout << "Age: " << a << endl;

    return 0;
}