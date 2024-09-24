#include<iostream>
using namespace std;


class BankAccount{
    private:
    int balance=0;

    public:

    void deposit(int amount){
        if(amount>0) balance += amount;
    }

    int getBalance(){
        return balance;
    }
}


int main(){




    return 0;
}