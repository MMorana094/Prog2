#include <iostream>
#include <cstdlib>
#include <typeinfo>

using namespace std;


class OperazioneAritmetica{
    private:
        double opSinistro;
        double opDestro;
    
    public:
        OperazioneAritmetica(double Sx, double Dx){
            this->opSinistro = Sx;
            this->opDestro = Dx;
        }

        double getSx(){
            return opSinistro;
        }

        double getDx(){
            return opDestro;
        }

        virtual double eseguiCalcolo() = 0;
};

class Addizione : public OperazioneAritmetica{
    public:
        Addizione(double Sx, double Dx) : OperazioneAritmetica(Sx, Dx){

        }

        double eseguiCalcolo(){
            return OperazioneAritmetica::getSx() + OperazioneAritmetica::getDx();
        }
};

int main(){

    double a = rand()%10+1;
    double b = rand()%10+1;

    OperazioneAritmetica calc;

    calc(a, b);


}