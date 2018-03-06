#include<ctime>
#include<fstream>
#include <vector>
#include<iostream>
using namespace std;

int main() {
    ifstream infile;
    infile.open("DAYSO2.txt");
    ofstream outfile;
    outfile.open("KETQUA2.txt");
    int n, k, i, a;
    vector<int> list;
    cout << "Reading..." << endl;
    while(infile >> a) {
		list.push_back(a);
    }
    n = list.size();
    while(k<=0||k>n) {
        cout << "Nhap vao k: ";
        cin >> k;
    }
    cout << "Writing..." << endl;
    for(i=k;i<n;i++) {
        outfile << list[i] << endl;
    }
    for(i=0;i<k;i++) {
        outfile << list[i] << endl;
    }
    infile.close();
    outfile.close();
    cout << "Done!" << endl;
    return 0;
}
