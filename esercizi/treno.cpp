/* 
Si crei una classe treno, la classe treno sarà caratterizzata dal numero di vagoni; tutti i vagoni possono contenere al massimo lo stesso numero di viaggiatori.
Creare un treno in cui il numero di vagoni e il numero massimo di viaggiatori per vagone siano scelti dall’utente e per 5 volte far chiedere all’utente se salgono 
o scendono viaggiatori e memorizzare il numero di viaggiatori presenti nel treno.
Dopo le 5 volte stampare il numero totale di viaggiatori e il numero medio di viaggiatori per vagone.
*/

#include <iostream>

using namespace std;

class treno{

    private :
        int vagoni;
        int viaggiatori;
        int viaggiatorepervagoni;

    public :
        treno(int nvt, int nvv, int nv){        //nvt = viaggiatori treno, nvv = viaggiatori vagoni, nv = vagoni
            this->vagoni = nv;
            this->viaggiatori = nvt;
            this->viaggiatorepervagoni = nvv;
        }

        treno(int nvt, int nvv) : treno(nvt, nvv, 0){

        }

        int sali(int i){
            viaggiatori = viaggiatori + i;
            if(viaggiatori>pmax()){
                int passTerra = viaggiatori - pmax();
                viaggiatori = pmax();
                return passTerra;
            } else {
                return 0;
            }
        }

        int scendi(int i){
            if(viaggiatori>i){
                viaggiatori-=i;
                return i;
            } else {
                i = viaggiatori;
                viaggiatori = 0;
                return i;
            }
        }

        int pmax(){
            return (viaggiatorepervagoni*vagoni);
        }

        int getVagoni(){
            return vagoni;
        }
        int getViaggiatori(){
            return viaggiatori;
        }
        int getVpV(){
            return viaggiatorepervagoni;
        }

        float viaggiatoriMedi(){
            return ((float)viaggiatori/vagoni);
        }

};


int main(){

    int nv,nmax;
    cin>>nv>>nmax;
    treno t(nv,nmax);
    for(int i=0;i<5;i++)
    {
        cout<<"salgono o scendono viaggiatori?"<<endl;
        cout<<"premi 1 se salgono, 2 se scendono"<<endl;
        int scelta;
        cin>>scelta;
        if(scelta==1)
        {
            cout<<"quanti salgono?"<<endl;
            int n;
            cin>>n;
            t.sali(n);
        }
        else
        {
            cout<<"quanti scendono?"<<endl;
            int n;
            cin>>n;
            t.scendi(n);
        }
    }
    cout<<"sul treno ci sono "<<t.getViaggiatori()<<endl;
    cout<<"in media per vagone ce ne sono "<<t.viaggiatoriMedi();
}