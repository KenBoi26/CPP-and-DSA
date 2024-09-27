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
