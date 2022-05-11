#include <iostream>

using namespace std;

template <typename T>
class MyArray{

private :
    T *arr;
    int lung;
public :

    MyArray(int n) {
        this->lung = n;
        this->arr = new T[lung];
    }
    
    void printArray(){
        for(int i=0; i<lung; i++){
            cout << arr[i] << " ";
        }
        cout  << endl;
    }

    T at(int i){
        return arr[i%lung];
    }

    void at(int i, T j){
        arr[i] = j;
    }
    int size(){
        return lung;
    }
    T* getPointer(){
        return arr;
    }
    void copy(MyArray<T> *dst){
        for(int i=0; i<lung; i++){
            dst->at(i, this->arr[i]);
        }
    }

};

int main(){
    MyArray<int> ma(10);
    ma.printArray();
    cout << endl;
    ma.at(0, 10);
    ma.at(1, 10);
    ma.printArray();
    cout << endl;
    MyArray<int> ma2(10);

    ma.printArray();
    cout << endl;
    ma.copy(&ma2);
    ma2.printArray();
}