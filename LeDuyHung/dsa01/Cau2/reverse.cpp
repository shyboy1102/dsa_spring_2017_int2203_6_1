#include<ctime>
#include<fstream>
#include <vector>
#include<iostream>
using namespace std;

int main() {
    ifstream infile;
    infile.open("DAYSO2.txt");
    ofstream outfile;
    outfile.open("KETQUA1.txt");
    int i, n;
    vector<int> list;
    cout << "Reading..." << endl;
    while(infile >> n) {
		list.push_back(n);
    }
    cout << "Writing..." << endl;
    for(i=list.size()-1;i>=0;i--) {
        outfile << list[i] << endl;
    }
    infile.close();
    outfile.close();
    cout << "Done!" << endl;
    return 0;
}

