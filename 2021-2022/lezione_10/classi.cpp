#include <iostream>

using namespace std;

class Base{
    protected:
        int n = 10;
};

class Derivata1 : protected Base{

};

class Derivata2 : protected Base{
    public:
        Base::n;
};

class A{
    public:
        A(){
            cout << "costruttore A" << endl;
        }

        void print(){
            cout << "sono la classe A" << endl;
        }

        void foo(){
            cout << "foo(A)" << endl;
        }
};

class B{
    public:
        B(){
            cout << "costruttore B" << endl;
        }

        void foo(){
            cout << "foo(B)" << endl;
        }
};

class C : public A, public B{
    public:
        C(){
            cout << "costruttore C" << endl;
        }
};

int main(){
    Derivata1 d1;
    Derivata2 d2;

    cout << d2.n << endl << endl;
    //inizio ereditarietà multipla
    C c;

    c.A::foo();
    c.B::foo();
    
}