#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL));
    ofstream file("DAYSO1.txt");
    int n = rand();
    file << n << endl;
    int i=0;
    while( i < n){
        int num = rand();
        file << num << endl;
        i++;
    }
    file.close();
    return 0;
}
