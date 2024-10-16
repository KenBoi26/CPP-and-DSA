// Question 1
#include <iostream>
using namespace std;

class Distance {
public:
    int feet;
    int inches;

    Distance(int f, int in) : feet(f), inches(in) {}

    Distance operator-() {
        int totalInches = (feet * 12 + inches) - 13;
        feet = totalInches / 12;
        inches = totalInches % 12;

        if (inches < 0) {
            inches += 12;
            feet -= 1;
        }

        return *this;
    }

    void display() {
        cout << feet << "'" << inches << endl;
    }
};

int main() {
    int feet, inches;
    cin >> feet >> inches;

    if (inches < 1 || inches > 12) {
        cout << "Invalid input" << endl;
        return 0;
    }

    Distance dist(feet, inches);
    dist = -dist;
    dist.display();

    return 0;
}


// Question 2
#include <iostream>
#include <iomanip>
using namespace std;

class WeatherData{
   public:
   float tempCelcius;
   
   WeatherData(float temp): tempCelcius(temp) {}
   
   WeatherData operator+(){
       float far = tempCelcius * 9/5 + 32;
       cout << fixed << setprecision(2) << far << endl;
   }
   
   WeatherData operator-(){
       float far = -(tempCelcius * 9/5) + 32;
       
       cout << fixed << setprecision(2) << far << endl;
   }
};



int main(){
    float temp;
    cin >> temp;
    WeatherData temps(temp);
    
    +temps;
    -temps;
    
    
    return 0;
}