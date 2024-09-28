// Question 1
#include <iostream>
using namespace std;


class Vehicle{
    public:
    
    string regno, make, model;
    int year;
    
    Vehicle() : regno(""), make(""), model(""), year(0) {}
    Vehicle(string regno, string make, string model, int year) : regno(regno), make(make), model(model), year(year) {}
    
    void display(){
        cout << "Registration Number: " << this->regno << endl;
        cout << "Make: " << this->make << endl;
        cout << "Model: " << this->model << endl;
        cout << "Year of Manufacture: " << this->year << endl;
    }
    
};


int main(){
    
    Vehicle v1;
    cin >> v1.regno;
    cin >> v1.make;
    cin >> v1.model;
    cin >> v1.year;
    
    
    v1.display();
    return 0;
}


// You are using GCC
#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    float inches;

public:
    Distance() : feet(0), inches(0.0) {}

    Distance(const Distance& d) {
        // Type your code here
        feet = d.feet;
        inches = d.inches;
    }

    void setdist(int ft, float in) {
        feet = ft;
        inches = in;
    }

    Distance add(Distance d) {
        // Type your code here
        Distance temp;
        temp.feet = feet + d.feet;
        
        int inc = inches + d.inches;
        
        if(inc >= 12){
            temp.feet += 1;
            temp.inches = inc-12;
        }else{
            temp.inches = inc;
        }
        
        return temp;
        
        
    }

    void disp() {
        cout << feet << "\'" << inches << "\"";
    }
};


// Question 2
int main() {
    int feet1, feet2;
    float inches1, inches2;

    cin >> feet1 >> inches1;
    cin >> feet2 >> inches2;

    Distance d1;
    d1.setdist(feet1, inches1);

    Distance d2;
    d2.setdist(feet2, inches2);

    Distance d3 = d1.add(d2);
    d3.disp();

    return 0;
}



// Question 3
// You are using GCC
#include <iostream>
#include <iomanip>
using namespace std;

class Numbers {
public:
  Numbers(int num1, int num2, int num3) : m_num1(num1), m_num2(num2), m_num3(num3)/* Type your code here*/ { }

  void print() {
    cout << m_num1 << " " << m_num2 << " " << m_num3 << endl;
  }
  
  void printSum() {
    // Type your code here
    cout << m_num1 + m_num2 + m_num3 << endl;
  }
  
  void printGreatest() {
    int greatest = m_num1;
    // Type your code here
    
    if(m_num2 > greatest && m_num2 > m_num3){
        greatest = m_num2;
    }else if(m_num3 > greatest && m_num3 > m_num2){
        greatest = m_num3;
    }
    cout << greatest;
  }
  
private:
  int m_num1;
  int m_num2;
  int m_num3;
};

int main() {
    int num1, num2, num3;
    cin >> num1 >> num2 >> num3;
    Numbers n1(num1, num2, num3);
    n1.print();
    n1.printSum();
    n1.printGreatest();
    return 0;
}


// Question 4
// You are using GCC
#include <iostream>
#include <iomanip>
using namespace std;

class Clock {
public:
    Clock(/* Type your code here */int h, int m, int s ) : hour(h), minute(m), second(s)/* Type your code here */ {}

    void setTime(int h, int m, int s) {
        // Type your code here 
        hour = h;
        minute = m;
        second = s;
        
    }

    void printTime() {
        cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second << endl;
    }

private:
    int hour;
    int minute;
    int second;
};

int main() {
    int h, m, s;

    cin >> h >> m >> s;
    Clock myClock(h, m, s);

    myClock.printTime();

    return 0;
}


// Question 5
// You are using GCC
#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string name;
    int price;
    int stock;
    int totalRevenue;

public:
    // Type your code here
    Product(string name, int price, int stock) : name(name), price(price), stock(stock), totalRevenue(0) {}
    
    

    void recordSale(int quantity) {
        // Type your code here
        if(quantity <= stock){
            stock -= quantity;
            totalRevenue += quantity * price;
        }else{
            cout << "Not enough stock for this sale" << endl;
        }
    }

    ~Product() {
        cout << "Total revenue: " << totalRevenue << endl;
        cout << "Final stock quantity: " << stock << endl;
    }
};

int main() {
    string name;
    int price;
    int stock;

    cin >> name >> price >> stock;
    Product product(name, price, stock);

    int quantity;
    while (true) {
        cin >> quantity;
        if (quantity == 0) {
            break;
        }
        product.recordSale(quantity);
    }

    return 0;
}
