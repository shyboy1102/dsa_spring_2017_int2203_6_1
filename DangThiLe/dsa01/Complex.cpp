#include <iostream>

using namespace std;

class Complex{
	private:
		int a,b;
		
	public:
		Complex operator+(Complex& c){
			Complex com;
			com.a = this->a + c.a;
			com.b = this->a + c.b;
			return com;
		}
		Complex operator-(Complex& c){
			Complex com;
			com.a = this->a - c.a;
			com.b = this->a - c.b;
			return com;
		}
		Complex operator*(Complex& c){
			Complex com;
			com.a = this->a * c.a - this->b * c.b;
			com.b = this->b * c.a + this->a * c.b;
			return com;
		}
};

int main(){
	
	return 0;
}

