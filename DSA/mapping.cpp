// like dictionary in Python

#include<iostream>
#include<map>
using namespace std;


int main(){

    map<int, string> students1 = {
        {1, "Alice"},
        {2, "Bob"},
        {3, "Charlie"},
        {4, "David"},
        {5, "Eve"}
    }


    map<int, string> students2;
    students2[1] = "Alice";
    students2[2] = "Bob";
    students2[3] = "Charlie";
    students2[4] = "David";
    
    students2.insert(make_pair(5, "Eve"));

    map<int, string>::iterator iter;

    for(iter = students2.begin(); iter != students2.end(); iter++){
        cout << iter->first << " -> " << iter->second << endl;
    }

    cout << students2.size() << endl;
    // students2.clear();
    students2.erase(2);
    cout << students2.size() << endl;


    return 0;
}