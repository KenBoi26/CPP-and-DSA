#include<iostream>
using namespace std;


class Base{
    public:
    int x;

    protected:
    int y;

    private:
    int z;
};

class PublicDerived : public Base{
    // x is public
    // y is protected
    // z is not accessible
    void print(){
        cout << x << endl;
    }

};

class ProtectedDerived : protected Base{
    // x is protected
    // y is protected
    // z is not accessible
    
    
};

class PrivateDerived : private Base{
    // x is private
    // y is private
    // z is not accessible
    
    
};



int main(){

    PublicDerived pd1;
    // pd1.x;


    return 0;
}