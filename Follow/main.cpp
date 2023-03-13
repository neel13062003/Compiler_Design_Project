#include <bits/stdc++.h>
using namespace std;
int main(){

    cout<<"*********      Find Follow       ********\n\n\n";

    int n;
    cout<<"Enter Number of Total Production\n";
    cin>>n;
    fflush(stdin);

    cout<<"Enter Your String one by one\n";

    string s;

    vector<char>first;
    vector<string>second;

    vector<vector<string>>vec;

    int x=n;
    while(n--){
        s="";

        fflush(stdin);
        //cout<<"Enter Your String one by one\n";
        getline(cin,s);

        first.push_back(s[0]);
        string temp="";
        for(int i=3;i<s.size();i++){
            if(s[i]!='|' || s[i]!='/'){
                temp+=s[i];
            }else{
                second.push_back(temp);
                temp.clear();
            }
        }
        second.push_back(temp);
        vec.push_back(second);
        second.clear();
    }

    //Logic



    //Printing Output Format.
    for(int i=0;i<x;i++){
        cout<<first[i]<<"=";
        for(int j=0;j<vec[i].size();j++){
            cout<<"{"<<vec[i][j] << "}";
        }
        cout<<endl;
    }

    return 0;
}
