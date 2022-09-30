#ifndef SORTING_H
#define SORTING_H
#include <cmath>
#include <iostream>

using namespace std;

void print(int vet[], int n){
    
    for(int i=0; i<n; i++){
        cout << vet[i] << "\t";
    }
    cout << endl;
}

//Importante il passsaggio per riferimento
void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

//Algoritmi di ricerca
//---------------------

//Ricerca sequenziale(lineare)		Complessità 0(n) Lineare
void search(int vet[], int n, int key){
    
    cout << "\nRicerca lineare" << endl;

    int iter = 0;
    for(int i=0; i<n; i++)
    {
        iter++;
        if(vet[i] == key)
        {
            cout << "Trovata alla " << iter << "° iterazione" << endl;
            return;
        }
    }

    cout << "Chiave non trovata! " << endl;
}

//Ricerca binaria(dicotomica)		Complessità 0(log n) logatirmica
void dicotomica(int vet[], int n, int key){

    cout << "\nRicerca binaria" << endl;
    int iter = 0;

    int start = 0;
    int end = n;
    int middle = start+(end-start)/2;

    bool found = false;

    while(!found && start != end)
    {
        middle = start+(end-start)/2;

        iter++;
        if(vet[middle] == key){
            found = true;
            }

        if(key < vet[middle]){
            end = middle;
            }

        if(key > vet[middle]){
            start = middle;
            }

    }
    
    if(!found){
        cout << "Chiave non trovata! " << endl;
    }else{
        cout << "Trovata alla " << iter << "° iterazione" << endl;
        }
}

//Versione ricorsiva		        Complessità 0(log n) logatirmica
void dicotomica_r(int vet[], int n, int key, int iter, int start, int end){

    int middle = start+(end-start)/2;
    iter++;

    if(vet[middle] == key){
        cout << "Trovata alla " << iter << "° iterazione" << endl;
        return;
    }

    if(start == end && vet[middle] != key){
       cout << "Chiave non trovata! " << endl;
       }

    if(key < vet[middle]){
        dicotomica_r(vet, n, key, iter, start, middle);
        }

    if(key > vet[middle]){
        dicotomica_r(vet, n, key, iter, middle, end);
        }

}

void dicotomica_r(int vet[], int n, int key){
    cout << "\nRicerca binaria con ricorsione: " << endl;
    int iter = 0;
    int start = 0;
    int end = n;
    return dicotomica_r(vet, n, key, iter, start, end);
}


//Algoritmi di riordinamento
//---------------------

//Selection sort                    Complessità O(n)^2 in qualunque caso
void selection_sort(int vet[], int n){

    for(int i=0; i<n; i++){
        int idx=i;
        for(int j=i+1; j<n; j++){
            if(vet[j] < vet[idx]){
                idx = j;
                }
        }
        swap(vet[i], vet[idx]);
    }
}

//Insertion sort                    Complessità O(n)^2 nel caso medio e peggiore
void insertion_sort(int vet[], int n){

    int temp;
    for(int i=1; i<n; i++){
        temp = vet[i];
        int j;
        for(j=i-1; j>0; j--){
            if(temp < vet[j]){
                vet[j] = vet[j-1];
            }else{ 
                break;
                }
        }
        vet[j] = temp;
    }
}
/*Possiamo migliorare l’insertion sort utilizzando la ricerca binaria*/

//Bubble sort                       Complessità O(n)^2 in qualunque caso
void bubble_sort(int vet[], int n){
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(vet[j] < vet[i]){
                swap(vet[j], vet[i]);
                } 
        }
    }

}
//Algoritmi di riordinamento RICORSIVI
//---------------------

//Merge sort                        Complessità totale : O(n log n) in ogni caso

//Procedura Merge per la combinazione
void merge(int vet[], int start, int middle, int end){
    int i = start;
	int j = middle +1;
	int k = start;
	int aux[end+1];

    while(i <= middle && j <= end){
        if(vet[i] <= vet[j]){
            aux[k++] = vet[i++];
        }else{
            aux[k++] = vet[j++];
            }
    }

    while(i <= middle){
        aux[k++] = vet[i++];
        }

    while(j <= end){
        aux[k++] = vet[j++];
        }

    for(k = start; k <= end; k++){
		vet[k] = aux[k];
        }
}

//Algoritmo di suddivisione
void merge_sort(int vet[], int start, int end){
	
    if(start < end){
        int middle = floor((start+end)/2);
        merge_sort(vet, start, middle);
        merge_sort(vet, middle+1, end);
        merge(vet, start, middle, end);
    }
}

void merge_sort(int vet[], int n){
    merge_sort(vet, 0, n-1);
}


//Quick sort                        COmplessità totale : 0(n log n) in ogni caso
int Part(int vet[], int start, int end){

    int pivot = vet[end]; //scelgo l'ultimo elemento come pivot
    int i = start-1;  //Indice del minimo corrente all'interno della lista

    for(int j=start; j<end; j++){
		if(vet[j] <= pivot){
			i++;
			swap(vet[i], vet[j]);
		}
	}
	swap(vet[i+1], vet[end]);

	return i+1;
}

void quick_sort(int vet[], int start, int end){

    if(start < end){
		int pivot = Part(vet, start, end);
		quick_sort(vet, start, pivot-1);
		quick_sort(vet, pivot+1, end);
	}

}

void quick_sort(int vet[],int n){
	quick_sort(vet, 0, n-1);
}
#endif