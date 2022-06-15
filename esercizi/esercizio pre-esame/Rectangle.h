#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Shape.h"

using namespace std;

template<typename T>
class Rectangle : public Shape{

    private :
        int Base;
        string shape;
        int Altezza;
        double Area;
    
    public :

        void setShape(string Shape){
            this->shape = Shape;
        }

};

#endif