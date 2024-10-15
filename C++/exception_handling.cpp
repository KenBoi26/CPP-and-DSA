#include<iostream>
using namespace std;


int main(){

    double numerator, denominator;

    cout << "Enter numerator: ";
    cin >> numerator;

    cout << "Enter denominator: ";
    cin >> denominator;

    

    try{
        if(denominator == 0){
            throw "Division by zero is not allowed";
        }
            cout << "Statement 1" << endl;

            double ans = numerator / denominator;
            cout << "Answer is: " << ans << endl;

            cout << "Statement 2" << endl;
    }
    catch(const char* msg){
        cerr << msg << endl;
    }

    cout << "Statement 3" << endl;


    return 0;
}