#include <iostream>
#include <cmath>
#include <typeinfo>

using namespace std;


class Shape{
    private:
        double area;
        string form;

        friend class rectangle;
        friend class circle;
        friend class triangle;

    public:
        Shape(string form){
            this->area = 0.0;
        }

        virtual double getArea() = 0;
};


class rectangle : public Shape{

    public:
        rectangle(double b, double a) : Shape("rectangle"){
            this->area = a*b;
        }

        double getArea(){
            return this->area;
        }

};

class circle : public Shape{
    public:
        circle(double rad) : Shape("circle"){
            this->area = M_PI*rad;
        }

        double getArea(){
            return this->area;
        }

};

class triangle : public Shape{
    public:
        triangle(double b, double h) : Shape("triangle"){
            this->area = (b*h)/2;
        }

        double getArea(){
            return this->area;
        }
};

int main(){
    
}