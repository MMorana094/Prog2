#include <iostream>

using namespace std;

class A{
    private:
        void private_fun(){
            cout << "sono la funzione privata di A" << endl;
        }
        virtual void private_fun2(){
            cout << "sono la funzione privata di A" << endl;
        }

    public:
        A(){
            cout << "costruttore A" << endl;
        }
        virtual void foo(){
            cout << "sono foo(A)" << endl;
        }
        virtual void print(){
            cout << "sono la classe A" << endl;
        }
        void call_private(){
            private_fun();
        }
        void call_private2(){
            private_fun2();
        }
};

class B : public A{

    public:
        B(){
            cout << "costruttore B" << endl;
        }

        void foo(){
            cout << "sono foo(B)" << endl;
        }

        void print(){
            cout << "sono la classe B" << endl;
        }

        void call_private(){
           
        }

        void call_private2(){
           
        }
};

int main(){

    A a;
    B b;

    a.print();
    b.print();

//CREIAMO DEI RIFERIMENTO DI A E B E LI DICHIARO DI CLASSE A
    A& ra = a;
    A& rb = b;

    ra.print();
    rb.print();
//CREIAMO DEI PUNTATORI DI A E B E GLI ASSEGNO I PUNTATORI DI A E B
    A* pa = &a;
    A* pb = &b;
    pa->print();
    pb->print();
    pa->foo();
    pb->foo();
//MODO SBAGLIATO NON DICHIARARE VIRTUAL LA FUNZIONE PRIVATE_FUN
    pa->call_private();
    pb->call_private();

    pa->call_private2();
    pb->call_private2();
    
}