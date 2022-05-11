#include <iostream>
#include <climits>

#ifndef PERSONA_H
#define PERSONA_H

using namespace std;

class persona {
    private :
        string nome;
        string cognome;
        short eta;
        string email;
        int* temperatura;

    public :

        persona(){
            nome = "Pippo";
            cognome = "Rossi";
            eta = 25;
            email = "qualcosa@gmail.com";
            temperatura = new int[1000];
        }
        persona(string n, string c, short e, string em){
            this->nome = n;
            this->cognome = c;
            this->eta = e;
            this->email = em;
            temperatura = new int[1000];
        }

        /* persona(const persona& p){
            nome = p.nome;
            cognome = p.cognome;
            eta = p.eta;
            email = p.email;
            temperatura = new int[1000];
        }
 */
        void print (){
            cout << "mi chiamo " << nome << " " << cognome << " ed ho " << eta << " anni, la mia email è " << email;
        }

};
class studente : public persona{

    private :
        string matricola;

    public : 
        studente(string n, string c, int e, string em, string mat) : persona(n, c, e,em){
            this->matricola = mat;
        }

        void print(){
            persona::print();
            cout << ", la mia matricola è " << matricola << endl;
        }

};
#endif

int main(){
    persona pers1;
    pers1.print();
    cout << endl;
    persona pers2("Mirko", "Morana", 27, "m.morana094@gmail.com");
    pers2.print();
    cout << endl;
    persona pers3 = pers2;
    pers3.print();
    cout << endl;
    cout << &pers2 << " " << &pers3 << endl;
    studente s3("ciao", "qualcosa", 12, "qualcosa@dmi.unict.it", "1000024598");
    s3.print();
    cout << endl;

    
}