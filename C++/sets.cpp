#include<iostream>
#include<set>
using namespace std;


int main(){

    set<int> set1 = {5,3,7,1,9,1};


    int num = 7;

    if(set1.count(num) == 1){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }

    for(auto i: set1){
        cout << i << " ";
    }

    set1.erase(7); // to delete element from set

    set1.clear(); // to delete all elements from set

    cout << set1.empty(); // to check if set is empty or not


    return 0;
}