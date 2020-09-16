#include <bits/stdc++.h>

#define SIZE 10000

using namespace std;

int p[SIZE];

int Find(int x)
{
    if(p[x] == x) return x;
    return p[x] = Find(p[x]);
}

void Union(int a, int b)
{
    p[Find(b)] = Find(a);
}
int main()
{
    for(int i = 0; i < SIZE; i++) p[i] = i;

    Union(1, 2);
    Union(3, 4);
    cout<<Find(1)<<endl;
    cout<<Find(2)<<endl;
    cout<<Find(3)<<endl;
    cout<<Find(4)<<endl;
    Union(2, 3);
    cout<<Find(1)<<endl;
    cout<<Find(2)<<endl;
    cout<<Find(3)<<endl;
    cout<<Find(4)<<endl;

    return 0;
}
