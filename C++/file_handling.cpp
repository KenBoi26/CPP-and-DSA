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


int main(){

    // telling that we will be appending in the file
    ofstream file("test.txt", ios::app);

    if(!file){
        cout << "Error" << endl;
        return -1;
    }

    file << "A" << endl;
    file << "B" << endl;
    file << "C" << endl;

    file.close();
}