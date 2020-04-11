#include <bits/stdc++.h>

#define SIZE 46341
#define li long long int

using namespace std;

bool marked[SIZE];
vector <li> p;// prime number

void sieve()
{
    for(int i = 3; i * i < SIZE; i += 2)
        if(!marked[i])
            for(int j = i * i; j < SIZE; j += 2 * i)
                marked[j] = true;
    p.push_back(2);
    for(int i = 3; i < SIZE; i += 2)
        if(!marked[i]) p.push_back(i);
}
void segment_sieve(li a, li b)
{
    bool prime[b - a + 1] = {false};
    for(li i = 0; (p[i]*p[i]<=b && i<p.size()); i++)
    {
        li temp = (a / p[i]) * p[i];
        if(temp < a) temp += p[i];
        for(li j = temp; j <= b; j += p[i])
            prime[j - a] = true;
        if(temp == p[i]) prime[temp - a] = false;
    }
    for(int i = 0; i < b - a + 1; i ++)
        if(!prime[i] && (i + a) > 1) cout<<i+a<<endl;
}
int main()
{
    sieve();
    segment_sieve(1, 100);
    return 0;
}
