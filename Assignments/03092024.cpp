//  Question 1
#include <iostream>
using namespace std;

class Car{
    public:
    string brand_name;
    string model;
    string engine;
    int seats;
    
    void displayInfo(){
        cout << this->brand_name << endl;
        cout << this->model << endl;
        cout << this->engine << endl;
        cout << this->seats << endl;
    }
    
};

int main() {
    Car c1;
    cin >> c1.brand_name;
    cin >> c1.model;
    cin >> c1.engine;
    cin >> c1.seats;
    
    
    cout << "Car 1s info is: " << endl;
    c1.displayInfo();

    return 0;
}



// Question 2

#include <iostream>
using namespace std;

class Rectangle {
    int length;
    int breadth;

public:
    Rectangle(int l, int b) : length(l), breadth(b) {}

    Rectangle(const Rectangle& t) {
        length = t.length;
        breadth = t.breadth;
    }

    void display() {
        cout << "Length: " << length << endl;
        cout << "Breadth: " << breadth << endl;
        cout << "Area: " << length * breadth << endl;
    }
};

int main() {
    Rectangle r1(10, 10);
    Rectangle r2 = r1;
    
    cout << "Rectangle 1's info is: " << endl;
    r1.display();
    cout << "Rectangle 2's info is: " << endl;
    r2.display();

    return 0;
}
