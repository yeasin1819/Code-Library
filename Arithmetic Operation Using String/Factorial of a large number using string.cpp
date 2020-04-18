#include <bits/stdc++.h>

using namespace std;

string string_to_int(int num)
{
    string res;
    while(num)
    {
        res.push_back((num % 10) + '0');
        num /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}
string multiplication(string num1, string num2)
{
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
    return mul;
}
string fact(int n)
{
    string res = "1", num = string_to_int(n);
    for(int i = 1; i <= n; i++)
        res = multiplication(res, string_to_int(i));
    return res;
}
int main()
{
    int n, t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<fact(n)<<endl;
    }
    return 0;
}
