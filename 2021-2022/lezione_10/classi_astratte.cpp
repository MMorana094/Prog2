#include <iostream>

using namespace std;

class Base{
    public:
        int n= 0;
};

class Der1 : virtual public Base{

};

class Der2 : virtual public Base{

};

class Der3 : public Base{

};

class Multipla : Der1, Der2, Der3{
    public:
        Multipla(){
            Der1::n = 1;
            Der2::n = 2;
            Der3::n = 3;

            cout << Der1::n << Der2::n << Der3::n << endl;
        }
};

class A{
    A(){
        cout << "costruttore di A" << endl;
    }
    virtual void print() = 0;
};

int main(){
    Multipla a;
}