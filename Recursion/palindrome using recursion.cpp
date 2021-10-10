#include <iostream>

using namespace std;

bool palindrome(string str)
{
    int len = str.length();
    if(!len || len == 1) return true;
    if(str[0] != str[len-1]) return false;
    palindrome(str.substr(1, len-1));
}

int main()
{
    if(palindrome("kaya")) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
