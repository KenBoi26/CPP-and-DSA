#include<iostream>
using namespace std;

class Vehicle{
    public:
    string make;
    int year;
    float fuel;

    Vehicle(string m, int y, float f) : make(m), year(y), fuel(f) {}

    void refuel(float amount){
        fuel += amount;
    }

    void display(){
        cout << "Make: " << make << endl;
        cout << "Year: " << year << endl;
        cout << "Fuel: " << fuel << endl;
    }

};


class Car : public Vehicle{
    public:
    int doors;

    Car(string m, int y, float f, int d) : Vehicle(m, y, f), doors(d) {}

    void display(){
        Vehicle::display();
        cout << "Doors: " << doors << endl;
    }

    void openDoors(){
        cout << "Doors are opened." << endl;
    }
};


class Bike : public Vehicle{
    public:
    bool hasCarrier;

    Bike(string m, int y, float f, bool c) : Vehicle(m, y, f), hasCarrier(c) {}

    void display(){
        Vehicle::display();
        cout << "Carrier: " << hasCarrier << endl;
    }

    void kickStart(){
        cout << "Bike kick-started." << endl;
    }
};


int main(){

    
    Car myCar("Toyota", 2020, 50.0, 4);
    Bike myBike("Honda", 2021, 15.0, true);

    myCar.refuel(10.0);
    myBike.refuel(5.0);

    cout << "Car details:" << endl;
    myCar.display();
    myCar.openDoors();

    cout << endl;
    cout << "Bike details:" << endl;
    myBike.display();
    myBike.kickStart();



    return 0;
}