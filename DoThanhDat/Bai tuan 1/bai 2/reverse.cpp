#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
using namespace std;

int main(){

    //ofstream file("DAYSO2.txt");
    ifstream ifile("DAYSO2.txt");
    ofstream ofile("KETQUA1.txt");
    int n;
    vector<int> num;
    while(!ifile.eof()){
        ifile >> n;
        num.push_back(n);
    }

    for(int i=num.size()-1; i >= 0; i--){
        ofile << num[i] << endl;
    }
    ofile.close();
    ifile.close();

    return 0;
}
