#include <iostream>
using namespace std;

class Complex {
	public:
	double a,b;	
};

Complex addition(Complex c1, Complex c2){
	Complex add;
	add.a = c1.a + c2.a;
	add.b = c1.b + c2.b;
	return add;
}
	
Complex subtraction(Complex c1, Complex c2){
	Complex sub;
	sub.a = c1.a - c2.a;
	sub.b = c1.b - c2.b;
	return sub;		
}
	
Complex multiplication(Complex c1, Complex c2){
	Complex mul;
	mul.a = c1.a*c2.a - c1.b*c2.b;
	mul.b = c1.b*c2.a + c1.a*c2.b; 
	return mul;
}

void show(Complex c){
	if((c.a == 0) && (c.b == 0)) cout << 0 << "\n";
	if(c.a == 0 && (c.b != 0)) cout << c.b << "i\n";
	if((c.a != 0) && (c.b == 0)) cout << c.a << "\n";
	if((c.a != 0) && (c.b > 0)) cout << c.a << "+" << c.b << "i\n";
	if((c.a != 0) && (c.b < 0)) cout << c.a << c.b << "i\n";
}

int main(){
	Complex c1,c2;
	cout << "Nhap so phuc thu nhat: a =";
	cin >> c1.a;
	cout << "b =";
	cin >> c1.b;
	
	cout << "Nhap so phuc thu hai: a =";
	cin >> c2.a;
	cout << "b =";
	cin >> c2.b;
	
	cout << "c1 ="; show(c1);
	cout << "c2 ="; show(c2);
	
	Complex ca = addition(c1, c2);
	cout << "Ket qua: c1 + c2 = "; show(ca);
	
	Complex cs = subtraction(c1, c2);
	cout << "Ket qua: c1 - c2 = "; show(cs);
	
	Complex cm = multiplication(c1, c2);
	cout << "Ket qua: c1 * c2 = "; show(cm);
	
	return 0;
}
