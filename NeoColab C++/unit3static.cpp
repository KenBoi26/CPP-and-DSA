// Question 1
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


// Question 2

// You are using GCC
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


// Question 3
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
        feet = d.feet;
        inches = d.inches;
    }

    void setdist(int ft, float in) {
        feet = ft;
        inches = in;
    }

    Distance add(Distance d) {
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


// Question 4
// You are using GCC
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int numbers[N];
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }
    ofstream file("sample.dat");
    if (!file) {
        cerr << "Cannot open the file." << endl;
        return 1;
    }
    for (int i = 0; i < N; ++i) {
        file << numbers[i] << " ";
    }
    file.close();

    int maxVal = numbers[0];
    int minVal = numbers[0];
    for (int i = 1; i < N; ++i) {
        if (numbers[i] > maxVal) {
            maxVal = numbers[i];
        }
        if (numbers[i] < minVal) {
            minVal = numbers[i];
        }
    }

    cout << maxVal << " " << minVal << endl;

    return 0;
}

// Question 5
// You are using GCC
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 1 || n > 100) {
        cout << "Invalid entry" << endl;
        return 0;
    }

    int numbers[n];
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    ofstream outFile("numbers.dat", ios::binary);
    if (!outFile) {
        cerr << "Cannot open the file." << endl;
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        outFile.write(reinterpret_cast<char*>(&numbers[i]), sizeof(numbers[i]));
    }
    outFile.close();

    ifstream inFile("numbers.dat", ios::binary);
    if (!inFile) {
        cerr << "Cannot open the file." << endl;
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        inFile.read(reinterpret_cast<char*>(&numbers[i]), sizeof(numbers[i]));
        cout << numbers[i] << " ";
    }
    inFile.close();
    cout << endl;

    return 0;
}
