#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string fileName;
    cout << "Enter the file name: ";
    cin >> fileName;

    string firstName, lastName;
    int age;
    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your last name: ";
    cin >> lastName;
    cout << "Enter your age: ";
    cin >> age;

    ofstream file(fileName);
    if (file.is_open()) {
        file << "First Name: " << firstName << endl;
        file << "Last Name: " << lastName << endl;
        file << "Age: " << age << endl;
        file.close();
        cout << "Details written to file successfully!" << endl;
    } else {
        cout << "Unable to open file." << endl;
    }

    ifstream readFile(fileName);
    if (readFile.is_open()) {
        string line;
        while (getline(readFile, line)) {
            cout << line << endl;
        }
        readFile.close();
    } else {
        cout << "Unable to open file." << endl;
    }

    return 0;
}


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("details.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file." << endl;
    }

    return 0;
}