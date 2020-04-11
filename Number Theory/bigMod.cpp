#include <iostream>

using namespace std;

int bigMod(int a, int b, int M)
{
    if(b == 0) return 1 % M;
    int x  = bigMod(a, b / 2, M);
    x = (x * x) % M;
    if(b % 2) x = (x * a) % M;
    return x;
}
int main()
{
    cout<<bigMod(2, 4, 3)<<endl;
    return 0;
}
