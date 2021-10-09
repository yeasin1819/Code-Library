#include <bits/stdc++.h>

using namespace std;


string rev_string(string str, int len)
{
    if(len == -1) return "";
    return str[len] + rev_string(str, len - 1);
}
string rev_string(string str)
{
    if(str == "") return str;
    return rev_string(str.substr(1)) + str[0];
}

int main()
{
    string str = "Hello world";

    string temp = rev_string(str, str.length() - 1);
    cout<<temp<<endl;

    temp = rev_string(str);
    cout<<temp<<endl;

    return 0;
}
