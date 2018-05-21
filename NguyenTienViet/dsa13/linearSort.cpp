#include<iostream>
using namespace std;

int Max(int ar[], int n)
{
    int max = ar[0];
    for (int i = 1; i < n; i++)
        if (ar[i] > max)
            max = ar[i];
    return max;
}

void print(int ar[], int n)
{
    for (int i = 0; i < n; i++)
        cout << ar[i] << " ";
        cout << endl;
}

void countSort(int ar[], int n, int numDigit)
{
    int tamp[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[ (ar[i]/numDigit)%10 ]++;
    print(count,10);

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    print(count,10);
    for (i = n - 1; i >= 0; i--)
    {
        tamp[count[ (ar[i]/numDigit)%10 ] - 1] = ar[i];
        count[ (ar[i]/numDigit)%10 ]--;
    }

    for (i = 0; i < n; i++)
        ar[i] = tamp[i];
}


void radixSort(int ar[], int n)
{
    int m = Max(ar, n);

    for (int numDigit = 1; m/numDigit > 0; numDigit *= 10){
        countSort(ar, n, numDigit);
        print(ar, n);
    }

}




int main()
{
    int ar[] = {170, 45, 75, 90, 802, 24, 2, 66, 520};
    int n = sizeof(ar)/sizeof(ar[0]);
    radixSort(ar, n);
    print(ar, n);
    return 0;
}

