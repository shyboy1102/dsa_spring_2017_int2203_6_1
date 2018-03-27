#include<iostream>

using namespace std;

int main(){
    int n = 8;
    //tao mang 2 chieu 8x8 lam vi du
    int a[8][8] =
    {
        {1,1,1,0,0,0,0,0},
        {1,1,0,0,0,0,0,0},
        {1,1,1,1,1,0,0,0},
        {1,1,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0,0},
        {1,1,1,1,0,0,0,0}
    };

    int i,j,x;
    x = -1;
    j = 0;
    for (i = 0; i < n; i++){
        if (a[i][j] == 1) x = i;
        while (a[i][j+1] == 1 && j < n) j++;
        if (j == n) break;
    }
    cout << "Hang co nhieu so 1 nhat:  " << x+1 << endl;
    return 0;
}
