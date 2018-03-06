#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
using namespace std;

int main(){
    ifstream ifile("DAYSO2.txt");
    ofstream ofile("KETQUA2.txt");
    int n;
    vector<int> num;
    while(!ifile.eof()){
        ifile >> n;
        num.push_back(n);
    }

    int k;
    cout << "k=";
    cin >> k;
    for(int i=k; i < num.size(); i++){
        ofile << num[i] << endl;
    }
    for(int i=0; i < k; i++)
        ofile << num[i] << endl;

    ofile.close();
    ifile.close();

    return 0;
}
