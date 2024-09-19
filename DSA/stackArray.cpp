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

        void pop(){
            if(top == -1){
                cout << "Stack Underflow" << endl;
                return;
            }

            top--;
        }

        bool empty(){
            
        }
};

int main(){




    return 0;
}