#include<iostream>
using namespace std;


/* 
class Parent{ // base class
    public:
    int num;

};

// derived class
class Child : public Parent{
    public:
    int childNum;
};

int main(){

    Child child1;

    child1.num;

    // only child can access itself and parent, parent can't access child
    Parent parent1;
    parent1.



    return 0;
}

*/

// zombie shooter
// different types of zombies
// DRY -> do no repeat yourself
// KISS --> keep it simple stupid


class MasterZombie{
    protected: // only the child can access and not main
    string name;
    int height;
    int power;

};



class zombie1 : public MasterZombie{

    string description;
    void fly(){

    }
};

class combie2 : public MasterZombie{

    void spitFire(){

    }
};