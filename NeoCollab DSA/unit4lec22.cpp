// Question 1
#include <iostream>
using namespace std;


int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}


int lcm_of_three(int a, int b, int c) {
    int lcm_ab = lcm(a, b);
    return lcm(lcm_ab, c);
}

int main() {
    int num1, num2, num3;
    cin >> num1 >> num2 >> num3;

    cout << lcm_of_three(num1, num2, num3) << endl;
    return 0;
}

// Question 2
#include <iostream>
using namespace std;

int towerOfHanoi(int n) {
    if (n == 1)
        return 1;
    return 2 * towerOfHanoi(n - 1) + 1;
}

int main() {
    int n;
    cin >> n;

    int moves = towerOfHanoi(n);
    cout << moves;

    return 0;
}