#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
 
int main ()
{
    
   

   // mo mot file trong che do read.
   ifstream infile; 
   infile.open("DAYSO1.txt"); 
 
   cout << "\n===========================\n" ;
   cout << "Doc du lieu co trong file!" << endl; 
   
   string num1;
   getline(infile,num1);
   int n=atoi(num1.c_str());
   cout<<n<<endl;
   
   
   //int n=atoi(str.c_str());
   
   
   string str;
   
   vector<int> A;
   
   while(getline(infile,str))
   {
   		int num=atoi(str.c_str());
   		A.push_back(num);
   		cout<<num<<endl;
   }
   				//Tim max
			   int max=A[0];
			   for(int i=0;i<A.size();i++)
			   {
			   		if(A[i]>max)
			   		{
			   			max=A[i];
			   		}
			   		
			   }
			   cout<<"So lon nhat la : "<<max<<endl;
			   
			   //Tim hieu be nhat
			   int hieu=max-A[0];
			   for(int i=0;i<A.size();i++)
			   {
			   	if((max-A[i])<hieu&&max-A[i]!=0)
			   	
			   		hieu=max-A[i];
			   }
			   
			   cout<<"So lon thu hai la : "<<max-hieu<<endl;
			   
			   //Nhap so k
			   int  k;
			   
			   do{
			   	cout<<"Nhap so k : ";
			   	cin>>k;
			   	
			   	cout<<"So thu " << k<<" la :"<<A[k]<<endl;
			   	
			   }
			   while(k>A.size());
			   
			   
   // dong file da mo.
   infile.close();

   return 0;
}
