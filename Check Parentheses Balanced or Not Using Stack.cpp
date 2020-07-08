#include <bits/stdc++.h>

using namespace std;

bool is_balanced(string str)
{
    stack <char> s;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[') s.push(str[i]);
        else if(s.empty()) return 0;
        else if((str[i] - s.top()) == 1) s.pop();
    }
    if(s.empty()) return 1;
    return 0;
}

int main()
{
    string input;
    cin>>input;
    if(is_balanced(input)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
