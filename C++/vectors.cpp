#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> vec1 = {1,2,3,4,5};

    vec1.push_back(10);
    
    // view item at an index
    cout << vec1[0] << endl;
    vec1.at(1);

    for(int i : vec1){
        cout << i << " ";
    }



    return 0;
}