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


#include <iostream>
#include <vector>
using namespace std;

void useItem(vector<string> inventory, int index){

    try{
        if(index < 0 || index >= inventory.size()){
            throw exception();
        }

        cout << "Using item: " << inventory[index] << endl;
    }

    catch(exception e){
        cout << "Exception: " << e.what() << endl;
    }
}
int main(){
    vector<string> inventory = {"Medicine", "Sword", "Health Drink"};

    useItem(inventory, 5);
}