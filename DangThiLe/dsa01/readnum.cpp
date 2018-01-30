#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int main()  {
	int i=0, x, a[1000];
	int temp;
	int k;
    std::ifstream fileInput("DAYSO1.txt");
	while (!fileInput.eof()){
			int n;
			fileInput >> n;
			std::cout << n << "\n ";
			a[i] = n;
			i++;
	}
	x = a[0];
	for (i = 1; i < x ; i++){ 
	    for (int j = i + 1; j < x; j++) 
	    { 
		    if (a[i] < a[j]){ 
		        temp = a[i]; 
		        a[i] = a[j]; 
		        a[j] = temp; 
		    }
	    }     
	}
	
	cout << "So nguyen lon nhat cua day: " << a[1] <<"\n";
	cout << "So nguyen lon thu hai cua day: " << a[2] << "\n";
	
	cin >> k;
	cout << "So nguyen lon thu " << k << " cua day: " << a[k];
	
    return 0;
}
