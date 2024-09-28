// Question 1
// You are using GCC
#include <iostream>
#include <fstream>
using namespace std;


int setup(int integer, float fl, string str){
    ofstream file("test.txt");
    if(!file){
        cout << "Cannot open the file.";
        return 1;
    }else{
        file << integer << " " << fl << endl;
        file << str;
        file.close();
        return 0;
    }
}


int main(){
    int integer;
    float fl;
    string str;
    
    cin >> integer >> fl >> str;
    
    if(setup(integer, fl, str) != 0){
        cout << "Unable to setup.";
        return 0;
    }
    
    ifstream file("test.txt");
    int readint;
    float readfloat;
    string readstr;
    
    file >> readint;
    file >> readfloat;
    file.ignore();
    file >> readstr;
    
    file.close();
    
    cout << readint << " " << readfloat << endl;
    cout << readstr;
    
    return 0;
    
    cout << "setup()";
    
}


// Question 2

// You are using GCC
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int integer;
    float fl;
    string str;
    
    cin >> integer >> fl >> str;
    
    ofstream file("test.txt");
    if(!file){
        cout << "Error";
        return 0;
    }else{
        file << integer << " " << fl << " " << str;
        file.close();
    }
    
    ifstream rfile("test.txt");
    if(!rfile){
        cout << "Error";
        return 0;
    }else{
        rfile >> integer;
        rfile >> fl;
        rfile >> str;
    }
    
    float res = fl + integer;
    
    cout << integer << " " << fl << endl;
    cout << str << endl;
    cout << "Sum of integer and float: " << res;
    
    rfile.close();
    
    return 0;
    
    
    
}

// Question 3

// You are using GCC
#include <iostream>
#include <fstream>
using namespace std;

int setup(int N) {
    ofstream file("numbers.txt");
    if (!file) {
        cerr << "Error" << endl;
        return 1;
    }
    for (int i = 1; i <= N; ++i) {
        file << i << " ";
    }
    file.close();
    return 0;
}

int main() {
    int N;
    cin >> N;

    if (setup(N) != 0) {
        cout << "Error" << endl;
        return 1;
    }

    ifstream file("numbers.txt");
    if (!file) {
        cerr << "Error" << endl;
        return 1;
    }

    int number;
    while (file >> number) {
        cout << number << " ";
    }
    file.close();
    cout << endl;

    return 0;
}


// Question 4
// You are using GCC
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    int sum = n1 + n2;

    ofstream file("sum.txt");
    if (!file) {
        cerr << "Error" << endl;
        return 1;
    }

    file << sum;
    file.close();

    cout << "Sum successfully written to the file 'sum.txt'." << endl;
    cout << "Sum: " << sum << endl;

    return 0;
}



// Question 5
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
