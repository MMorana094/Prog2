/*
scrivere una classe template che prenda due tipi di dato generici e li utilizzi come tipi di dato per due attributi della classe stessa
scrivere i metodi set, get, print ed il costruttore
*/
#include <iostream>

using namespace std;

template<typename T1, typename T2>
class A{
        private:
            T1 a;
            T2 b;
        public:
            A(T1 _a , T2 _b) : a(_a), b(_b){
                
            }

            void seta(T1 x){
                this->a = x;
            }

            void setb(T2 x){
                this->b = x;
            }

            T1 geta(){
                return a;
            }

            T2 getb(){
                return b;
            }

            void print(){
                cout << "a = " << a << ", b = " << b << endl;
            }

    };

int main(){
    A<int, double> a(2, 5.2);

    a.print();

    a.seta(10);
    a.setb(15);

    a.print();

    cout << "a = " << a.geta() << endl;
    cout << "b = " << a.getb() << endl;


   
    
}