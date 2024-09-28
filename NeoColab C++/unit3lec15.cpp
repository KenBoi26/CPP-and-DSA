#include <iostream>
#include <iomanip>
using namespace std;

class Complex {
public:
    float r, i;

    Complex() : r(0), i(0) {}

    
    Complex(float real, float imm) : r(real), i(imm) {}

    
    Complex sum(const Complex& c1, const Complex& c2) {
        return Complex(c1.r + c2.r, c1.i + c2.i);
    }

    
    void display(const Complex& c1, const Complex& c2) {
        Complex result = sum(c1, c2);
        cout << "Sum of two complex numbers is " << fixed << setprecision(1) << result.r << " + " << fixed << setprecision(1) << result.i << "i" << endl;
    }
};

int main() {
    Complex c1, c2;

    
    
    cin >> c1.r >> c1.i;

    cin >> c2.r >> c2.i;

    c1.display(c1, c2);

    return 0;
}


// You are using GCC
#include <iostream>
using namespace std;


class AddAmount{
    private:
    int def = 50;
    
    
    public:
    
    int num;
    
    AddAmount() : num(0) {}
    
    AddAmount(int number) : num(number) {}
    
    
    
    
    int print_amount(){
        
        cout << "Default amount: " << def << endl;
        cout << "Final amount: " << num + def << endl;
    }
};



int main(){
    
    AddAmount a1;
    cin >> a1.num;
    a1.print_amount();
    
    
    return 0;
}


// You are using GCC
#include <iostream>
using namespace std;



class Counter{
    public:
    int init, random;
    
    Counter() : init(0), random(0) {}
    
    Counter(int init, int random) : init(init), random(random) {}
    
    void display(){
        cout << this->init << endl;
        cout << this->init + this->random << endl;
    }
};




int main(){
    
    Counter c1;
    cin >> c1.init;
    cin >> c1.random;
    
    c1.display();
    
    
    return 0;
}