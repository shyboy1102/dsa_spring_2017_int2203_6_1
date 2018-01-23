#include <fstream>
#include <iostream>
#include<stdlib.h>
#include <ctime>
using namespace std;
 
int main ()
{
	srand(time(0));
  	int randNum=1;
  	randNum=rand();
	
   // mo mot file trong che do write.
   ofstream outfile;
   outfile.open("DAYSO1.txt",ios::trunc);
	
	
   cout << "Ghi du lieu toi file!" << endl;
   
   

   // ghi du lieu da nhap vao trong file.
   outfile << randNum << endl;

	for(int i=0;i<randNum;i++)
	{
		int j=rand();
		outfile << j << endl;
	}
   

   // dong file da mo.
   outfile.close();

  
   return 0;
}
