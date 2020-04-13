#include <iostream>
#include <bits/stdc++.h>

using namespace std;

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
string sum(string num1, string num2)
{
    string ans;
    int len1 = num1.length() - 1, len2 = num2.length() - 1;
    if(len2 > len1) swap(num1, num2), swap(len1, len2);
    int sum, carry = 0;
    for(int i = len2; i>=0; i--, len1--)
    {
        sum = (num1[len1] - '0') + (num2[i] - '0') + carry;
        ans.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    for(int j = len1; j >= 0; j--)
    {
        sum = (num1[j] - '0') + carry;
        ans.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    if(carry) ans.push_back(carry + '0');
    reverse(ans.begin(), ans.end());
    ans = zero_remover(ans);
    return ans;
}
int main()
{
    string a, b;
    cin>>a>>b;
    cout<<sum(a, b)<<endl;
    return 0;
}
