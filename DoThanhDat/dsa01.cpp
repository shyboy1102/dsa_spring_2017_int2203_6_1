#include <iostream>
using namespace std;
//Dinh nghia lop Complex
class complex{
    double real;
    double image;

    public:
        complex(){
            this->real = real;
            this->image = image;
        }

        complex(double x, double y){
            real = x;
            image = y;
        }
        void setReal(double thuc){
            real = thuc;
        }
        void setImage(double ao){
            image = ao;
        }

        void getBt(){
            if(image > 0)
                cout << real << '+' << image << "*j" <<endl;
            else
                cout << real << image << "*j" << endl;
        }
    //Nap chong toan tu.
        complex operator+(complex& c1){
            complex c;
            c.real = this->real + c1.real;
            c.image = c1.image + this->image;
            return c;
        }
        complex operator-(complex& c1){
            complex c;
            c.real = this->real - c1.real;
            c.image = this->image - c1.image;
            return c;
        }
        complex operator*(complex& c1){
            complex c;
            c.real = this->real*c1.real - this->image*c1.image;
            c.image = this->image*c1.real + c1.image*this->real;
            return c;
        }
};

int main(){
    complex c1;
    complex c2;
    complex c3;
    complex c4;

    c1.setReal(3.7);
    c2.setReal(4.0);
    c1.setImage(6.0);
    c2.setImage(-7.0);

    c3 = c1 + c2;
    c4 = c1 * c2;

    c3.getBt();
    c4.getBt();

}
