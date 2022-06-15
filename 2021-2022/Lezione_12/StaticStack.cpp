#include <iostream>

using namespace std;

template <typename T>
class StaticStack{
    private:
        T* arr;
        T top;
        int size;
        int MaxSize;

    public:

        virtual ostream& put(ostream& os){
            os << "Static Stack: Max Size=" << MaxSize << endl;
            for(int i=-1; i<MaxSize-1; i++){
                os << arr[i] << " ";
            }
            os << endl;
            return os;
        }
        StaticStack(int MaxSize){
            this->MaxSize = MaxSize;
            this->size = 0;
            this->top = -1;
            arr = new T[MaxSize];
        }

        T getTop(){
            if(isEmpty()){
                return NULL;
            }
            return arr[top--];
        }

        void PUSH(T val){
            if(top == MaxSize-1){
                return;
            }
            arr[top++] = val;
        }

        T POP(){
            if(isEmpty()){
                return -1;
            }
            return arr[top--];
        }

        bool isEmpty(){
            return top == -1;
        }

};

template<typename T>
ostream& operator<<(ostream& os, StaticStack<T>& obj){
    return obj.put(os);
}

int main(){
    StaticStack<int> STS(10);

    STS.PUSH(5);
    STS.PUSH(6);
    STS.PUSH(3);
    STS.PUSH(1);
    STS.PUSH(4);
    STS.PUSH(2);
    STS.PUSH(9);
    STS.PUSH(8);
    STS.PUSH(10);
    STS.PUSH(7);

    cout << STS << endl;
}