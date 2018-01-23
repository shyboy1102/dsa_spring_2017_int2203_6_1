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
   outfile.open("KETQUA2.txt",ios::trunc); 
 	
 	int  k;
   cout << "\n===========================\n" ;
   cout << "Nhap so k " << endl; 
   
   cin>>k;
   
   
   string str;
   
   vector<int> A;
   
   while(getline(infile,str))
   {
   		int num=atoi(str.c_str());
   		A.push_back(num);
   		
   }
   
   
   for(int i=k+1;i<A.size();i++)
   {
   		outfile << A[i] << endl;
   }
   
   for(int i=0;i<k;i++)
   {
   		outfile << A[i] << endl;
   }
   
   
   outfile.close();
   // dong file da mo.
   infile.close();

   return 0;
}
