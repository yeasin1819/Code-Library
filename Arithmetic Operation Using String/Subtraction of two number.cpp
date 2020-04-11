#include <bits/stdc++.h>

using namespace std;

bool isSmaller(string num1, string num2)
{
    int n1 = num1.length(), n2 = num2.length();
    if(n1 > n2) return 0;
    if(n2 > n1) return 1;
    for(int i = 0; i < n1; i++)
        if(num2[i] > num1[i]) return 1;
    return 0;
}
string zero_remover(string num)
{
    int i;
    string ans;
    for(i = 0; i < num.length(); i++)
        if(num[i]-'0') break;
    for(int j = i; j < num.length(); j++)
        ans.push_back(num[j]);
    if(!(ans.length())) ans.push_back('0');
    return ans;
}
string make_equal(string num, int len1)
{
    reverse(num.begin(), num.end());
    for(int i = num.length(); i < len1; i++)
        num.push_back('0');
    reverse(num.begin(), num.end());
    return num;
}
string subtraction(string num1, string num2)
{
    string ans;
    int sign = 0;
    num1 = zero_remover(num1), num2 = zero_remover(num2);
    if(isSmaller(num1, num2)) swap(num1, num2), sign = 1;
    int carry = 0, len1 = num1.length(), len2 = num2.length();
    if(len1 > len2) num2 = make_equal(num2, len1);
    len1 = num1.length()-1, len2 = num2.length()-1;
    for( ; len1 >= 0; len1--, len2--)
    {
        int sub = (num1[len1]-'0') - ((num2[len2]-'0') + carry);
        if(sub < 0)
            sub += 10, carry = 1;
        else carry = 0;
        ans.push_back(sub + '0');
    }
    reverse(ans.begin(), ans.end());
    if(sign) cout<<"-";
    return zero_remover(ans);
}
int main()
{
    string num1, num2;
    while(cin>>num1, cin>>num2)
        cout<<subtraction(num1, num2)<<endl;
    return 0;
}
