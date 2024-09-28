// QUestion 1
// You are using GCC
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    ofstream outfile("even.txt");
    if (!outfile) {
        cerr << "Cannot open the file." << endl;
        return 1;
    }

    for (int i = a; i <= b; ++i) {
        if (i % 2 == 0) {
            outfile << i << endl;
        }
    }
    outfile.close();

    ifstream infile("even.txt");
    if (!infile) {
        cerr << "Cannot open the file." << endl;
        return 1;
    }

    int number;
    while (infile >> number) {
        cout << number << endl;
    }
    infile.close();

    return 0;
}


// Question 2
// You are using GCC
#include <iostream>
#include <fstream>
using namespace std;

struct Data {
    int number;
    int n; 
};

int main() {
    Data data;
    cin >> data.n;

    if (data.n > 1000) {
        cout << "Exceeding Limit!" << endl;
        return 0;
    }

    ofstream outFile("num.txt");

    if (outFile.is_open()) {
        if (data.n % 2 == 1) {
            for (int i = 1; i <= data.n; ++i) {
                data.number = 3 * i;
                outFile << data.number << endl; 
                //Enter the missing code
            }
        } 
        
        else {
            for (int i = 1; i <= data.n; ++i) {
                data.number = 5 * i;
                outFile << data.number << endl;
                //Enter the missing code
            }
        }

        outFile.close();
    }

    ifstream inFile("num.txt");

    if (inFile.is_open()) {
        //Enter the missing code
        while(inFile >> data.number){
            cout << data.number << " ";
        }
        inFile.close();
    }
    return 0;
}