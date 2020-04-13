#include <bits/stdc++.h>

using namespace std;

int sign(string num)
{
    if(num[0] == '-') return 1;
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
string multiplication(string num1, string num2)
{
    int sn = 0;
    if(sign(num1)) num1[0] = '0', sn++;
    if(sign(num2)) num2[0] = '0', sn++;
    int len1= num1.length(), len2 = num2.length(), k, carry;
    if(len2 > len1) swap(num1, num2), swap(len1, len2);
    string ans, mul;
    for(int i = 0; i < len1 + len2; i++) ans.push_back('0');
    for(int i = len2-1; i >= 0; i--)
    {
        k = len2 - (i + 1), carry = 0;
        for(int j = len1-1; j >= 0; j--)
        {
            int m = (num2[i]-'0') * (num1[j]-'0') + carry + (ans[k]-'0');
            if(m > 9) carry = m / 10, m = m % 10;
            else carry = 0;
            ans[k] = m + '0', k++;
        }
        if(carry) ans[k] = carry + '0', k++;
    }
    for(int i = k-1; i >= 0; i--) mul.push_back(ans[i]);
    mul = zero_remover(mul);
    if(sn == 1 && mul != "0") cout<<"-";
    return mul;
}
int main()
{
    string num1, num2;
    while(cin>>num1>>num2)
    {
        cout<<multiplication(num1, num2)<<endl;
    }
    return 0;
}
