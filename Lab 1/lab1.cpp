#include<iostream>
using namespace std;
int main()
{
    int x[]= {34,56,65,43,34};
    int n= 5;
    double sum = 0;
    for(int i; i<n;i++)
    {

        sum+= x[i];

    }
    sum = sum/n;
    cout<<sum;

}
