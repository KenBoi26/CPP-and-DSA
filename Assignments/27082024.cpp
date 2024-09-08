// Question 1

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int* p = &n;

    cout << n << endl;
    cout << *p;

    return 0;
}


// Question 2

#include <iostream>
using namespace std;


int main(){
    int arr[] = {1,2,3,4,5};
    int *p = arr;

    for(int i=0; i<5; i++){
        cout << *(p + i) << endl;
    }

    return 0;
}


// Question 3

#include <iostream>
using namespace std;

int main(){
    int num;
    cin >> num;

    int *p1 = &num;
    int **p2 = &p1;

    cout << num << endl;
    cout << *p1 << endl;
    cout << **p2;
}