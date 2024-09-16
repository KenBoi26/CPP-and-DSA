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


int main(){

    // write to file
    fstream file("test1.txt", ios::out);

    if(file){
        file << "testing with line 1" << endl;
        file.close();
    }else{
        cout << "Error in opening file" << endl;
        return -1;
    }


    // read from file

    string line;
    file.open("test1.txt", ios::in);

    if(file){
        while(!file.eof()){
            getline(file, line);
            cout << "Read : " << line << endl;
        }
    }else{
        cout << "Error in opening file" << endl;
        return -1;
    }


    // append
    file.open("test1.txt", ios::app);

        if(file){
            file << "testing with line 2" << endl;
            file.close();
        }else{
            cout << "Error i opening file" << endl;
            return -1;
        }
}



int main(){
    char name[50] = "Hello";
    int age = 10;

    ofstream file("binary", ios::binary);

    file.write(name, sizeof(name));
    file.write(reinterpret_cast<char*> (&age), sizeof(age));

    char name2[50];

    ifstream file2("binary", ios::binary);
    file2.read(name2, sizeof(name2));

    cout << "Name: " << name2;
    file.close();
}