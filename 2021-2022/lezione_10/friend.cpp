#include <iostream>

using namespace std;

class A{

    private:
        int n = 10;

        friend void set(A& a, int val){
        a.n = val;
    }

    public:
        void set_n(int v){
            n = v;
        }

        void print(){
            cout << n << endl;
        }

        friend ostream& operator<<(ostream& os, A& obj){
            os << obj.n << endl;
            return os;
        }
};

int main(){
    A a;
    a.set_n(20);
    a.print();
    set(a, 15);
    a.print();
    cout << a;

}