#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> str;
    vector<char> start;
    vector<vector<string>> ans;

    int n;

    cout<<"***\t\t Note You Should Write First  Terminal Type Function First   \t\t*** \n\n";

    cout<<"***\t\t If Your Calling Non Terminal You write in Manner It Written First. \t\t*** \n\n";

    cout << "How many production :" << endl;
    cin>>n;
    fflush(stdin);

    cout<<"\n\n";
    string s, temp = "";

    cout<<"Enter Your Production One By One\n";
    while(n--){
        s="";

        fflush(stdin);                                   //cin.ignore(256, '\n');  //cin.ignore();
        //cout<<"Enter Your String :>\n";
        getline(cin,s);                                    //cin>>s;

        start.push_back(s[0]);
        for (int j = 3; j < s.size(); j++){
            if (s[j] != '|'){
                temp += s[j];
            }
            else{
                str.push_back(temp);
                temp.clear();
            }
        }
        str.push_back(temp);
        ans.push_back(str);
        str.clear();
        temp.clear();
    }

     vector<pair<string,vector<char>>>ansFinal;

     for (int i = 0; i < ans.size(); i++){                 // ans[i] = A-> ab cde ef

        cout << start[i] << " :";
        cout<<"{";

        int count=0;

        vector<char>vec;

        for (int j = 0; j < ans[i].size(); j++){
            if(ans[i][j][0] >= 'a' && ans[i][j][0] <= 'z'){
                 if(count>0) cout<<",";
                 cout<<ans[i][j][0];
                 vec.push_back(ans[i][j][0]);
                 count++;
            }else if(ans[i][j][0] >= 'A' && ans[i][j][0]<='Z'){

                 for(int k=0;k<ansFinal.size();k++){
                    if( ansFinal[k].first == string(1, ans[i][j][0]) ){                //if( ansFinal[k].first == to_string(ans[i][j][0]) ){
                        for(int l=0;l<ansFinal[k].second.size();l++){
                              if(count>0) cout<<",";
                              cout<< ansFinal[k].second[l];
                              count++;
                        }
                    }
                 }

            }
        }
        string startStr(1, start[i]);
        ansFinal.push_back({startStr, vec});   //ansFinal.push_back({start[i],vec});
        vec.clear();

        cout<<"}"<<endl;
    }

    return 0;
}


/*
How many production :
4


Enter Your Production One By One
A->ab|cd|ef
B->Ac|z
C->A|B
D->e
A :{a,c,e}
B :{a,c,e,z}
C :{a,c,e,z}
D :{e}

*/
