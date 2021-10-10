#include <iostream>

using namespace std;

string dec_to_bin(int dec)
{
    if(dec == 0) return "0";
    if(dec == 1) return "1";
    char rem = dec % 2 + 48;
    return dec_to_bin(dec / 2) + rem;
}

int main()
{
    int dec = 8;

    cout<<dec_to_bin(dec)<<endl;

    return 0;
}
