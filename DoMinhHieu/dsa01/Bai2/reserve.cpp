#include <fstream>
#include <iostream>
#include<stdlib.h>
#include <ctime>
#include<vector>
using namespace std;
 
int main ()
{
 // mo mot file trong che do read.
   ifstream infile; 
   infile.open("DAYSO2.txt");
    ofstream outfile;
   outfile.open("KETQUA1.txt",ios::trunc); 
 
   cout << "\n===========================\n" ;
   cout << "Ghi du lieu da duoc ghi nguoc lai!" << endl; 
   
   
   
   
   string str;
   
   vector<int> A;
   
   while(getline(infile,str))
   {
   		int num=atoi(str.c_str());
   		A.push_back(num);
   		
   }
   
   
   for(int i=A.size()-1;i>=0;i--)
   {
   		outfile << A[i] << endl;
   }
   
   outfile.close();
   // dong file da mo.
   infile.close();

   return 0;
}
