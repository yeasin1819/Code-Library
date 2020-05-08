#include <bits/stdc++.h>

#define SIZE 1000001

using namespace std;

vector <int>primes;
bool marked[SIZE];

void sieve()
{
    for(int i = 3; i * i < SIZE; i += 2)
    {
        if(!marked[i])
            for(int j = i * i; j < SIZE; j += 2 * i)
                marked[j] = true;
    }
    primes.push_back(2);
    for(int i = 3; i < SIZE; i += 2)
        if(!marked[i]) primes.push_back(i);
}
int NOD(int n)
{
    int nod = 1, r = sqrt(n) + 1, cnt;
    for(int i = 0; i < primes.size() && primes[i] <= r; i++)
    {
        if(!(n % primes[i]))
        {
            cnt = 1;
            while(!(n % primes[i])) cnt++, n /= primes[i];
        }
        r = sqrt(n) + 1;
        nod *= cnt;
    }
    if(n > 1) nod *= 2;
    return nod;
}
int main()
{
    sieve();
    cout<<NOD(12)<<endl;
    return 0;
}

