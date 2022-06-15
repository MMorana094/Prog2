#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include "Rectangle.h"

using namespace std;

template<typename T>
class Shape{
    
    private :
        string shape;
        int N;
        template<typename U>
        friend class rectangle;

    public :
        Shape(int N, string shape) : shape(shape), N(N){
            
        }

        virtual void setShape() = 0;

};

#endif