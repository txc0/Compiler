

///Write a program to determine weather the given input is a operator or not

#include<iostream>
#include<string>
using namespace std;

int main()
{
    char a = '+';
    char b = '-';
    char c = '*';
    char d = '/';
    char e = '%';
    char f = '=';

    string s,g;
    cout << "Enter valid expression : ";
    cin >> s;


    int ct=0;
    for(int i=0;i<=s.size();++i) {
        if(s[i] == a) {
            ct++;
            g = g + a;
        }
        else if(s[i] == b) {
            ct++;
            g += b;
        }
        else if(s[i] == c) {
           ct++;
            g += c;
        }
        else if(s[i] == d) {
            ct++;
            g += d;
        }
        else if(s[i] == e) {
            ct++;
            g += e;
        }
        else if(s[i] == f) {
           ct++;
            g+= f;
        }

    }
    cout << '\n';
    cout << "Total operators : " << ct << '\n';

    for(int i=0;i<ct;++i) {
        cout << "operator " << i+1 << ": ";
        cout << g[i] << '\n';
    }
}

