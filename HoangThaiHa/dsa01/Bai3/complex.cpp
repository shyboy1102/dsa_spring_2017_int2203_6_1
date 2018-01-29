#include <iostream>
using namespace std;
class complex
{
public:
    double a;
    double b;
    void nhap() {
        cout << "\n Nhap phan thuc :"; 
		cin >> a;
        cout << "\n Nhap phan ao :"; 
		cin >> b;
    }
    void xuat() {
        cout << a << "+" << b << "i" << endl;
    }
    complex cong(complex u2) {
        complex u;
        u.a = a + u2.a;
        u.b = this->b + u2.b;
        return u;
    }
    complex tru(complex u2) {
        complex u;
        u.a = a - u2.a;
        u.b = this->b - u2.b;
        return u;
    }
    complex nhan(complex u2) {
        complex u;
        u.a = this->a * u2.a - this->b * u2.b;
        u.b = this->b * u2.a + this->a * u2.b;
        return u;
    }

};
int main() {
    complex utong, uhieu, utich, u1, u2;
    cout << "Nhap so phuc thu nhat "; 
	u1.nhap();
    cout << "\nNhap so phuc thu thu 2 "; 
	u2.nhap();
    cout << "Tong :";
    utong = u1.cong(u2); 
	utong.xuat();
    cout << "Hieu :";
    uhieu = u1.tru(u2); 
	uhieu.xuat();
	cout << "Tich :";
    utich = u1.nhan(u2); 
	utich.xuat();
	return 0;
}
