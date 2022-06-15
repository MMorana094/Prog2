#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>

using namespace std;

template<typename T>
class vertice{
    private :
        template<typename U>
        friend class grafo;
        T key;
    public :
        vertice(T key) : key(key){

        }
        vertice() : vertice(nullptr){

        }

    bool operator==(vertice<T>& V){
        return this->key == V.key;
    }

    friend ostream& operator <<(ostream& os, vertice<T>& obj){
        os << obj.key << endl;
    return os;
    }
};

template<typename T>
class grafo{
    private :  
        vertice<T>** Arr;
        bool** Matrice;
        int max_Size = 0;
        int nVertici = 0;

    public :
        grafo(int maxSize){
            max_Size = maxSize;
            Arr = new vertice<T>*[max_Size];
            Matrice = new bool*[max_Size];
            for(int i=0; i<max_Size; i++){
                Matrice[i] = new bool[max_Size];
                for(int j=0; j<max_Size; j++){
                    Matrice[i][j] = false;
                }
            }
        }

        void addVertice(T key){
            if(this->nVertici == this->max_Size){
                cerr << "Grafico Pieno" << endl;
                return;
            }

            Arr[nVertici++] = new vertice<T>(key);
        }

        void addEdge(T key1, T key2){
            int i = this->Search(key1);
            int j = this->Search(key2);
            if( i != -1 && j != -1){
                Matrice[i][j] = true;
                Matrice[j][i] = true;
            } else {
                if(i == -1){
                    cerr << "non esistono Vertici con la chiave : " << key1 << endl;
                } else if(j == -1){
                    cerr << "non esistono Vertici con la chiave : " << key2 << endl;
                }
            }
        }

        int* Search(T key){                          //si può restituire vertice<T> o un intero
            if(this->nVertici == 0){
                return nullptr;
            }
            for(int i=0; i<this->nVertici; i++){
                if(Arr[i]->key == key){
                    return *Arr[i];
                }
            }
            return nullptr;
        }

        friend ostream& operator <<(ostream& os, grafo<T>& obj){
            for(int i=0; i<obj.nVertici; i++){
                os << vertice[i];
            }
            os << endl;
        return os;
    }

};
#endif