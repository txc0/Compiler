

///	Write a program to determine whether the Given Input is Comment line(s) or Not.

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cout << "Enter a valid input : ";
    cin>>s;

    cout << '\n';

    bool t = true;
    for(int i=0;i<s.size();++i) {
        if(s[i] == '/' && s[i+1] == '*') {
            t = false;
        }
    }

    if(t==true) {
            cout << "Single Comment line\n";
    } else {

        cout << "Multiple lines"<<endl;
        cout <<" Comment"<<endl;
    }
}
