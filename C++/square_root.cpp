
#include <iostream>
#include <math.h>
using namespace std;

float root(int number){
    
    float ans = sqrt(number);
    
    return ans;
}

int main() {
    
    int number;
    cin >> number;
    
    cout << root(number) << endl;

    return 0;
}