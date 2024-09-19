#include<iostream>
using namespace std;


class MyStack{
    int* arr;
    int size;
    int top;

    public:
        MyStack(){
            arr = new int[size];
            top = -1;
        }

        void push(int val){
            if(top == size-1){
                cout << "Stack Overflow" << endl;
                return;
            }

            top++;
            arr[top] = val;
        }
};

int main(){




    return 0;
}