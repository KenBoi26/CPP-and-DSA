static
// Question 1
// You are using GCC
#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    Number(int v) : value(v) {}

    Number operator-() {
        return Number(-value);
    }

    int getValue() {
        return value;
    }
};

int main() {
    int X, Y;
    cin >> X >> Y;

    Number num1(X);
    Number num2(Y);

    Number negatedNum1 = -num1;
    Number negatedNum2 = -num2;

    int addition = negatedNum1.getValue() + negatedNum2.getValue();
    int subtraction = negatedNum1.getValue() - negatedNum2.getValue();

    cout << addition << " " << subtraction << endl;

    return 0;
}

// Question 2
// You are using GCC
#include <iostream>
#include <iomanip>
using namespace std;

class Acceleration {
public:
    double value;

    Acceleration(double v) : value(v) {}

    double operator*(double tim) const {
        return value * tim;
    }
};

int main() {
    double initial_velocity, acceleration, tim;
    cin >> initial_velocity >> acceleration >> tim;

    Acceleration acc(acceleration);

    double final_velocity = initial_velocity + (acc * tim);

    cout << fixed << setprecision(1) << final_velocity << " m/s" << endl;

    return 0;
}


// Question 3
// You are using GCC
#include <iostream>
#include <iomanip>
using namespace std;

class Circle {
private:
    double radius;

protected:
    Circle(double r) : radius(r) {}

    double getRadius() const {
        return radius;
    }
};

class Cylinder : private Circle {
private:
    double height;

public:
    Cylinder(double r, double h) : Circle(r), height(h) {}

    double volume() const {
        double radius = getRadius();
        return 3.14 * radius * radius * height;
    }
};

int main() {
    double radius, height;
    cin >> radius >> height;

    Cylinder cyl(radius, height);

    double volume = cyl.volume();

    cout << fixed << setprecision(2) << volume << endl;
    return 0;
}


// Question 4
// You are using GCC
#include <iostream>
#include <iomanip>

class CarPrice {
protected:
    double price;

public:
    CarPrice(double p) : price(p) {}
};

class LoanInterestRate {
protected:
    double interestRate;

public:
    LoanInterestRate(double rate) : interestRate(rate) {}
};

class CarLoan : public CarPrice, public LoanInterestRate {
    int years;

public:
    CarLoan(double p, double rate, int y) : CarPrice(p), LoanInterestRate(rate), years(y) {}

    double calculateTotalInterest() {
        return price * interestRate * years;
    }

    void displayTotalInterest() {
        std::cout << "Total interest paid: Rs." 
                  << std::fixed << std::setprecision(2) 
                  << calculateTotalInterest() << std::endl;
    }
};

int main() {
    double carPrice, interestRate;
    int loanYears;

    std::cin >> carPrice >> interestRate >> loanYears;

    CarLoan loan(carPrice, interestRate, loanYears);
    loan.displayTotalInterest();

    return 0;
}


// Question 5
// You are using GCC
#include <iostream>
#include <iomanip>
using namespace std;

class Vehicle {
public:
    int fuelConsumption;
    int horsepower;


    
    Vehicle(int fuel, int hp) : fuelConsumption(fuel), horsepower(hp) {}

    double efficiencyRatio() const {
        return static_cast<double>(horsepower) / fuelConsumption;
    }
};

class Electric : virtual public Vehicle {
public:
    Electric(int fuel, int hp) : Vehicle(fuel, hp) {}
};

class Gasoline : virtual public Vehicle {
public:
    Gasoline(int fuel, int hp) : Vehicle(fuel, hp) {}
};

class Hybrid : public Electric, public Gasoline {
public:
    
    Hybrid(int fuel, int hp) : Vehicle(fuel, hp), Electric(fuel, hp), Gasoline(fuel, hp) {}

    std::string labelEfficiency() const {
        double ratio = efficiencyRatio();
        if (ratio < 5.0) {
            return "Low Efficiency";
        } else if (ratio <= 10.0) {
            return "Moderate Efficiency";
        } else {
            return "High Efficiency";
        }
    }
};

int main() {
    
    int fuel, power;
    cin >> fuel >> power;

    Hybrid hybrid(fuel, power);

    double ratio = hybrid.efficiencyRatio();
    cout << fixed << setprecision(2) << ratio << endl;

    cout << hybrid.labelEfficiency() << endl;

    return 0;
}