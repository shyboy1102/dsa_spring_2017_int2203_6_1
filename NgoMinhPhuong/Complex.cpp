#include<bits/stdc++.h>

using namespace std;




class Complex{
	
	
	public:
		
		Complex(float _a, float _b){
			
			this->a = _a;
			this->b= _b;
			
		}
		
		Complex();
		
		void setA(float tmp){
		
			this->a = tmp;
			
		}
		
		void setB(float tmp){
		
			this->b = tmp;
			
		}
		
		Complex operator+(const Complex& cmp){
		
			Complex x;
			x.a = this->a + cmp.a;
			x.b = this->b + cmp.b;
			return x;
		
		}
		
		Complex operator-(const Complex& cmp){
		
			Complex x;
			x.a = this->a - cmp.a;
			x.b = this->b - cmp.b;
			return x;
		
		}
		Complex operator*(const Complex& cmp){
		
			Complex x;
			x.a = this->a*cmp.a - this->b*cmp.b ;
			x.b = this->a*cmp.b + this->b*cmp.a;
			return x;
		
		}
		
	private:
		float a;
		float b;		
};

int main (){ 
	return 0;
}
