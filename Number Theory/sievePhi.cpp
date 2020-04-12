#include <bits/stdc++.h>

using namespace std;

int phi(int n)
{
    int ans = n;
    for(int i = 2; i * i <= n; i ++)
    {
        if(!(n % i))
        {
            while(!(n % i)) n /= i;
            ans -= (ans / i);
        }
    }
    if(n > 1) ans -= (ans / n);
    return ans;
}

int main()
{
    cout<<phi(12)<<endl;
    return 0;
}
