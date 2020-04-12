#include <bits/stdc++.h>

#define SIZE 5000001

using namespace std;

long long int ans[SIZE];
bool marked[SIZE];

void phi()
{
    for(int i = 1; i < SIZE; i++) ans[i] = i;
    for(int i = 2; i < SIZE; i++)
    {
        if(!marked[i])
        {
            for(int j = i; j < SIZE; j += i)
            {
                ans[j] -= (ans[j] / i);
                marked[j] = true;
            }
        }
    }
}
int main()
{
    phi();
    cout<<ans[12]<<endl;
}

