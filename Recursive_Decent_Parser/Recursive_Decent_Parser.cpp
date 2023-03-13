#include<bits/stdc++.h>
using namespace std ;

bool F(string s);
void E(string s);
void E_(string s);
void T(string s);
void T_(string s);
int i=0;
string ans="";


bool F(string s)
{
   if(s[i]=='i' && s[i+1]=='d')
   {
         i+=2;
         ans= ans + "id";
         return true;

   }
   else
   {
     if(s[i]=='(' &&  s[i+2]==')')
     {
         ans+="(" ;
         i+=2;
        E(s);
        ans+=")" ;
        return true;
     }
   }
}
void T_(string s)
{
    if(s[i]=='*')
    {
        i++;
        ans+="*";
        F(s);
        T_(s);
    }
    else
    {
        return;
    }
}

void T(string s)
{
   F(s);
   T_(s);
   return ;
}
void E_(string s)
{
    if(s[i]=='+')
    {
        i++;
        ans+="+";
        T(s);
        E_(s);
        return;
    }
    else
    {
        return;
    }
}

void E(string s)
{
    T(s);
    E_(s);
    return;
}


int main()
{
    string s;
    s="id+id*id";
   
    E(s);
    if(s==ans)
    {
    cout<<"your string successfully scanned"<<endl;
    }
    else
    {
        cout<<"Sorry,your string not successfully run"<<endl;
    }

}