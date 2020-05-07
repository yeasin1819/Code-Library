#include <bits/stdc++.h>

using namespace std;

vector<int> string_to_int(string str)
{
    vector<int> res;
    int num = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != ' ')
        {
            while((str[i] != ' ') && str[i] != '\0')
            {
                num = num * 10 + str[i] - '0';
                i++;
            }
            res.push_back(num);
            num = 0;
            i--;
        }
    }
    return res;
}

int main()
{
    string input;
    getline(cin, input);
    vector <int> num = string_to_int(input);
    for(int i = 0; i < num.size(); i++) cout<<num[i]<<" ";
    return 0;
}
