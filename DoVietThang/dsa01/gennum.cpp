#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>

using namespace std;

int main()
{
	srand(time(NULL));
	int n = rand();
	//int n2 = rand() % 10000;

    ofstream f;
    f.open("DAYSO1.txt");
    //f.open("DAYSO2.txt");
    f << n << endl;
    for(int i = 0; i < n; i++){
        int a = rand();
        f << a << endl;
    }

    f.close();
	cout << "Xong";
	return 0;
}
