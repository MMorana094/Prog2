#include <iostream>

using namespace std;

template <typename T>
class Studente{

    private:
        T* classe;
        int head = -1, tail = -1;
        int Size;
        int nElem = 0;
        string nome;
        string cognome;
        int eta;
        int media;

    public:
        Studente(int Size) : Size(Size){
            this->classe = new T[Size];
        }

        Studente() : Studente(10);{

        }

        bool isFull(){
            if(((head - (tail+1)) % length) == 0){
                cout << "Class Full" << endl;
                return;
            }
        }

        bool isEmpty(){
            return 0;
        }

        void enqueue(T val){
            if(isFull()){
                return;
            }
            if(isEmpty()){
                head = 0;
            }

            

        }

};