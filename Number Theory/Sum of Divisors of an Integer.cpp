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
int SOD(int n)
{
    int sum = 1, t_sum, r = sqrt(n) + 1, p;
    for(int i = 0; i < primes.size() && primes[i] <= r; i++)
    {
        t_sum = 1;
        if(!(n % primes[i]))
        {
            t_sum = 1, p = 1;
            while(!(n % primes[i]))
            {
                p *= primes[i];
                t_sum += p;
                n /= primes[i];
            }
        }
        sum *= t_sum;
        r = sqrt(n) + 1;
    }
    if(n > 1) sum *= (n + 1);
    return sum;
}
int main()
{
    sieve();
    cout<<SOD(12)<<endl;
    return 0;
}
