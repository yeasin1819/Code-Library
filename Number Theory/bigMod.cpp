#include <bits/stdc++.h>

using namespace std;

int bigMod(int p)
{
   if(p == 0) return 1 % 3;
   int ans = bigMod(p / 2);
   ans = (ans * ans) % 3;
   if(p % 2) ans = (ans * 2) % 3;
   return ans;
}

int main()
{
    cout<<bigMod(4);
    return 0;
}
