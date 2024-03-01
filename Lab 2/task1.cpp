

///Write a program to determine the given input numeric or not

#include<iostream>
#include<string>
using namespace std;

int main()
{
    char x = 'a';
    char y = 'z';
    char X = 'A';
    char Y = 'Z';

    int a = (int) x;
    int z = (int) y;
    int A = (int) X;
    int Z = (int) Y;

    string s;
    cout << "Enter Input : ";
    cin >> s;


    bool t = false;
    for(int i=0;i<s.size();i++) {
        if((s[i] >= a && s[i] <= z) || (s[i] >=A && s[i] <=Z)) {
            t = true;
        }
    }

    cout << '\n';
    if(t == true) {
        cout << s << " is not Numeric Constant"<<endl;
    } else {
        cout << s << " is Numeric Constant"<<endl;
    }
}
