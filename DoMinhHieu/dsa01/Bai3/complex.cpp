#include<iostream>
using namespace std;
class Complex{
	private:
		double a;
		double b;
	public:
		void setComplex(double a,double b)
		{
			this->a=a;
			this->b=b;
		}
		
		
		
		void showInfo()
		{
			cout<<this->a<<"+"<<this->b<<"i"<<endl;
		}
		 Complex operator+(const Complex& c1)
      {
         Complex c;
         c.a=this->a+c1.a;
         c.b=this->b+c1.b;
         return c;
      }
      
      Complex operator-(const Complex& c1)
      {
         Complex c;
         c.a=this->a-c1.a;
         c.b=this->b-c1.b;
         return c;
      }
      
      Complex operator*(const Complex& c1)
      {
         Complex c;
         c.a=this->a*c1.b-this->b*c1.b;
         c.b=this->b*c1.a+this->a*c1.b;
         return c;
      }
		
};

int main()
{
	Complex c1;
	Complex c2;
	
	c1.setComplex(5,6);
	c2.setComplex(8,-6);
	
	cout<<"Tong la: ";
	Complex c3=c1+c2;
	c3.showInfo();
	
	cout<<"Hieu la :";
	Complex c4=c1-c2;
	c4.showInfo();
	
	cout<<"Tich la : ";
	Complex c5=c1*c2;
	c5.showInfo();
	
	return 0;
}
