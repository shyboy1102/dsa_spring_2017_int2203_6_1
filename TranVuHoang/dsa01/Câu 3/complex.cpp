#include <iostream>
#include <stdio.h>

using namespace std;

class Complex
{
	private:
		double a;
		double b;

	public:
	void nhapSo()
	{
		cout << "Moi ban nhap phan thuc: ";      cin >> a;

		cout << "Moi ban nhap phan ao:";         cin >> b;
	}

	void inSo()
	{
		cout << a << "+" << b << "i";
	}
		Complex operator+(Complex u2)
		{
			Complex u;
			u.a = a + u2.a;
			u.b = this->b + u2.b;
			return u;
		}
		Complex operator-(Complex u2)
		{
			Complex u;
			u.a = a - u2.a;
			u.b = this->b - u2.b;
			return u;
		}
		Complex operator*(Complex u2)
		{
			Complex u;
			u.a = a * u2.a;
			u.b= this->b * u2.b;
			return u;
		}
};
int main()
{
	Complex u1, u2;
	cout << " Moi ban nhap so thu nhat: "; u1.nhapSo();
	cout << " Moi ban nhap so thu hai : "; u2.nhapSo();

	Complex a, b,c;
	a = u1 + u2; a.inSo();
	b = u1 - u2; b.inSo();
	c = u1 * u2; c.inSo();
	return 0;
}
