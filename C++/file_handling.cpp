#include<iostream>
#include<fstream>
using namespace std;

// ifstream --> to read from a file
// ofstream --> to write to a file

int main(){
    
    // if(file.is_open())

    // if(file.fail())

    ifstream file("test.txt");

    if(!file) cout << "Error" << endl;

    string line;

    while(!file.eof()){
        getline(file, line);
        cout << line << endl;
    }

    file.close();

    return 0;
}