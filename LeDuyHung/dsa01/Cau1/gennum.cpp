#include<cstdlib>
#include<ctime>
#include<fstream>
#include<iostream>
using namespace std;

int main() {
    ofstream outfile;
    outfile.open("DAYSO1.txt");
    int i;
    cout << "Writing..." << endl;
    srand(time(NULL));
    int n = rand();
    outfile << n << endl;
    for(i=0;i<n;i++) {
        outfile << rand() << endl;
    }
    outfile.close();
    cout << "Done!" << endl;
    return 0;
}
