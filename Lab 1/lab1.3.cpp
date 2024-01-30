#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    char a[n];
    for(int i=0;i<n;i++)
    {
      cin>>a[i];

    }
    cin>>m;
    char b[m];
      for(int i=0;i<m;i++)
    {
      cin>>b[i];

    }
    char x=' ';

    stack<char> st;
    for(int i=m-1; i>=0; i--)
    {
        st.push(b[i]);
    }
    st.push(x);

    for(int i=n-1; i>=0; i--)
    {
        st.push(a[i]);
    }
    cout<<"My name is ";
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }






}
