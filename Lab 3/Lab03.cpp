#include<bits/stdc++.h>
#include<fstream>
using namespace std;

struct Keys {
    string a[100];
}key;


bool isvalidIdentifier(string s)
{
    bool b = true  ;

    int eSpace = 32;
    int eSlash = 47;

    int eColon = 58;
    int eSign = 64;

    int eOne = 48;
    int eNine = 57;

    int eParanthesis = 91;
    int eUpperSymbol = 94;
    int eComma = 96;
    int eCurly = 123;
    int eCurlyH = 126;


     for(int i=0;i<100;++i) {
         if(key.a[i]== s) {
            b = false;
            cout <<"Variable cannot be a keyword -> " << s << endl;
            cout << '\n';
        }
        }

    int n = s.size();

    if(s[0] == '0' ||s[0] == '1' ||s[0] == '2' ||s[0] == '3' ||s[0] == '4' ||s[0] == '5' ||s[0] == '6' ||s[0] == '7' ||s[0] == '8' ||s[0] == '9')
    {
        b = false;
        cout<<"Error because of number at Index 0"<<endl;

    }


     else
    {
        for(int i = 0; i<s.size(); i++)
        {
            if((s[i]>= eSpace && s[i]<=eSlash) || (s[i]>= eColon && s[i]<=eSign) || (s[i]>= eOne && s[i]<=eNine)|| (s[i]>= eParanthesis && s[i]<= eUpperSymbol) || (s[i]>= eCurly && s[i]<=eCurlyH) )
            {
                b = false;

                cout<<"Error at index : "<< i<<"  Error Symbol is : "<< s[i]<<endl;
            }
        }
    }


    return b;
}




int main()
{
    string s;
    cout<<"Enter a valid variable name"<<endl;
    cin>>s;

      freopen("Keywords.txt","r",stdin);
    int n;
    cin >> n;
    for(int i=0;i<n;++i) {
       cin >> key.a[i];
    }

    if(isvalidIdentifier(s))
    {
        cout<<"Valid input"<<endl;
    }
    else{
        cout<<"Sorry! Invalid Input"<<endl;
        cout<<"Code Error"<<endl;
    }


}







/*#include<bits/stdc++.h>
#include<fstream>
using namespace std;

bool isvalidIdentifier(string s)
{
    bool b = true  ;

    int eSpace = 32;
    int eSlash = 47;

    int eColon = 58;
    int eSign = 64;

    int eOne = 48;
    int eNine = 57;

    int eParanthesis = 91;
    int eUpperSymbol = 94;
    int eComma = 96;
    int eCurly = 123;
    int eCurlyH = 126;
    //string line;



    int n = s.size();

    if(s[0] == '0' ||s[0] == '1' ||s[0] == '2' ||s[0] == '3' ||s[0] == '4' ||s[0] == '5' ||s[0] == '6' ||s[0] == '7' ||s[0] == '8' ||s[0] == '9')
    {
        b = false;
        cout<<"Error because of number at Index 0"<<endl;

    }


     else
    {
        for(int i = 0; i<s.size(); i++)
        {
            if((s[i]>= eSpace && s[i]<=eSlash) || (s[i]>= eColon && s[i]<=eSign) || (s[i]>= eOne && s[i]<=eNine)|| (s[i]>= eParanthesis && s[i]<= eUpperSymbol) || (s[i]>= eCurly && s[i]<=eCurlyH) )
            {
                b = false;

                cout<<"Error at index : "<< i<<"  Error Symbol is : "<< s[i]<<endl;
            }
        }
    }


    return b;
}
bool keywords(string s)
{
    string line;
    fstream keys;
    bool a = true;

        string k;
        keys.open("Keywords.txt" ,ios:: in);
        if(keys.is_open())
        {

            while(getline(keys,line))
            {
               line;
            }
            keys.close();
        }

        keys>> k;

         if(s!=line)
    {
        cout<< s << " is a keyword"<<endl;
        cout<< "Error"<<endl;
        a = false;
    }
    return a;




}

int main()
{
    string s;
    cin>>s;
    if(isvalidIdentifier(s) && keywords(s))
    {
        cout<<"Valid input"<<endl;
    }
    else{
        cout<<"Invalid Input"<<endl;
    }
     //cout<<isvalidIdentifier(s);







}

