#include <bits/stdc++.h>
using namespace std;


//Vector<string>vec;
//access perticular string use 2D array .    vec[i][i].
bool cmp(string s1, string s2)
{
    if (s1.length() < s2.length())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    string s, temp, com;
    char c;
    cout << "A ->";
    getline(cin, s);

    vector<string> v, ans;

    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] == '|')
        {
            v.push_back(temp);
            temp.clear();
        }
        else
        {
            temp += s[i];
        }
    }
    v.push_back(temp);
    sort(v.begin(), v.end(), cmp);

    int p = 0;
    int pos = 0;
    for (int i = 0; i < v[0].size(); i++)
    {
        c = v[0][i];
        int count = 1;
        for (int j = 1; j < v.size(); j++)
        {
            if (v[j][i] == c)
            {
                count++;
            }
            else
            {
                p = 1;
                break;
            }
            if (count == v.size())
            {
                com += c;
                pos++;
            }
        }
        if (p == 1)
        {
            break;
        }
    }
    for (int k = 0; k < v.size(); k++)
    {
        string temp1 = " ";
        for (int l = pos; l < v[k].size(); l++)
        {
            temp1 += v[k][l];
        }
        ans.push_back(temp1);
    }

    cout <<"A -> "<< com + "X" << endl;
    cout << "X -> ";
    for (int i = 0; i < ans.size()-1; i++)
    {
        if (ans[i].size() == 1)
        {
            continue;
        }
        else
        {
            cout << ans[i] << "|";
        }
    }
    cout<<ans[ans.size()-1]<<endl;
}


/*
A -> α β | α γ

to:

A -> α A'

A' -> β | γ*/
