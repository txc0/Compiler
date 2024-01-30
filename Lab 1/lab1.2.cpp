#include<iostream>
using namespace std;
int main()
{
    int x[]= {34,56,65,43,34};
    int n= 5;
    int mn=x[0], mx=x[0];

   for(int i=0; i<n;i++)
   {
       if(x[i]<=mn)
        mn=x[i];
   }
     for(int i=0; i<n;i++)
   {
       if(x[i]>mx)
        mx=x[i];
   }
   cout<<"minimum value is "<<mn<<endl;
   cout<<"maximum value is "<<mx<<endl;




}
