#include <iostream>

using namespace std;

class Y {};

class A{
    int data;           //private di default
    class B{ };         //classe B private annidata
    enum { a = 100 };   //enumeratore privato costante
    friend class X;     //classe friend scritta per una futura dichiarazione

    friend Y;           //dichiarazione di classe friend semplice

};

class X : A::B{         //A::B accessibile alle friend
    A::B mx;            //accessibile dai membri friend
    class Y{
        A::B my;        //accessibile dalla classe friend annidata B
    };
    int v[A::a];        // accessibile da membri di friend

};

int main(){
    return 0;
}