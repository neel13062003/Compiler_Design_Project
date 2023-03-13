#include <bits/stdc++.h>
using namespace std;

bool istrue(char s)
{
    if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isnumber(char s)
{
    if ((s >= '0' && s <= '9'))
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
    string s;
    cout << "Enter Your String : " << endl;
    getline(cin, s);
    int state = 0;
    int x = s.size();
    int i = 0, p = 0;
    cout << x << endl;
    while (true)
    {
        switch (state)
        {

        case 0:
        {
            if (s[i] == '<')
                state = 1;
            else if (s[i] == '>')
                state = 2;
            else if (s[i] == '=')
                state = 3;
            else if (isnumber(s[i]))
            {
                state = 9;
            }
            else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            {
                state = 4;
            }
            else if (isspace(s[i]))
            {
                // else if(s[i]==' '){
                state = 5;
            }
            else if (s[i] == '*')
            {
                state = 10;
            }
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                state = 6;
            }
            else if (s[i] == '(' || s[i] == ')' || s[i] == '{' || s[i] == '}' || s[i] == ',' || s[i] == '[' || s[i] == ']' || s[i] == ';')
            {
                state = 7;
            }
            else if (s[i] == ':')
            {
                state = 8;
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                state = 9;
            }
            else
            {
                state = 1000000000;
            }
            break;
        }

        case 1:
        {
            if (s[i] == '<')
            {
                i++;
                if (s[i] == '=')
                {
                    string var2 = "<=";
                    i++;
                    cout << "Less than or equal to: " << var2 << endl;
                    state = 0;
                }
                else
                {
                    // i++;
                    cout << "Less than: " << s[i - 1] << endl;
                    state = 0;
                }
                if (i == x)
                {
                    p = 1;
                }
            }
            break;
        }

        case 2:
        {
            if (s[i] == '>')
            {
                i++;
                string var = "";
                if (s[i] == '=')
                {
                    i++;
                    var = ">=";
                    cout << "Greater than or equal to: " << var << endl;
                    state = 0;
                }
                else
                {
                    // i++;
                    cout << "Greater than: " << s[i - 1] << endl;
                    state = 0;
                }
                if (i == x)
                {
                    p = 1;
                }
            }
            break;
        }

        case 3:
        {
            if (s[i] == '=')
            {
                i++;
                cout << "Equal to (Mathematical operator): " << s[i - 1] << endl;
                state = 0;
            }
            if (i == x)
            {
                p = 1;
            }
            break;
        }

        case 4:
        {
            string temp = "";
            // while(isalpha(s[i])){
            while (istrue(s[i]) == true)
            {
                temp = temp + s[i];
                i++;
                if (i == x)
                {
                    p = 1;
                    break;
                }
            }
            if (temp == "if" || temp == "then" || temp == "else" || temp == "for" || temp == "while" || temp == "do" || temp == "exit" || temp == "case" || temp == "switch")
            {
                cout << temp << " is a keyword " << endl;
            }
            else
            {
                cout << "Identifier is: " << temp << endl;
            }
            state = 0;
            if (i == x)
            {
                p = 1;
            }
            temp.clear();
            break;
        }

        case 5:
        {
            i++;
            cout << "This is (Space) " << endl;
            if (i == x)
            {
                p = 1;
                break;
            }
            state = 0;
            break;
        }

        case 6:
        {
            if (s[i] == '+' || s[i] == '*' || s[i] == '/' || s[i] == '-')
            {
                i++;
                if (s[i] == '=')
                {
                    i++;
                    cout << "This is relational operator: " << s << endl;
                    state = 0;
                }
                else
                {
                    // i++;
                    cout << "This is Mathematical operator: " << s[i - 1] << endl;
                    state = 0;
                }
                if (i == x)
                {
                    p = 1;
                }
            }
            break;
        }

        case 7:
        {
            cout << "This is punctuation : " << s[i] << endl;
            i++;
            if (i == x)
            {
                p = 1;
            }
            state = 0; // this is very very important.
            break;
        }
        case 9:
        {

            string temp = "";
            // while(isalpha(s[i])){
            while (isnumber(s[i]) == true)
            {
                temp = temp + s[i];
                i++;
                if (i == x)
                {
                    p = 1;
                    break;
                }
            }
            cout << "This is number :" << temp << endl;

            state = 0;
            if (i == x)
            {
                p = 1;
            }
            temp.clear();
            break;
        }
        case 10:
            if (s[i] == '*')
            {
                i++;
                if (s[i] == '*')
                {
                    i++;
                    if (s[i] == '*')
                    {
                        i++;
                        cout << "this is comment" << endl;
                        p = 1;
                        break;
                    }
                    else
                    {
                        cout << "This is Mathematical operator:" << s[i - 1] << endl;
                        cout << "This is Mathematical operator:" << s[i - 1] << endl;
                        state = 0;
                        break;
                    }
                }
                else
                {
                    cout << "This is Mathematical operator: " << s[i - 1] << endl;
                    state = 0;
                    break;
                }
            }

        default:
        {
            cout << " My Compiler Return Error: " << endl;
            p = 1;
            break;
        }
        }
        if (p == 1)
        {
            break;
        }
    }

    return 0;
}
