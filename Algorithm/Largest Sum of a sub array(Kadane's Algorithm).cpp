#include <bits/stdc++.h>

using namespace std;

int kadanes(int arr[], int n)
{
    int mx = arr[0], currentMx = arr[0], startIdx = 0, endIdx = 0, tempIdx = 0;

    for(int i = 1; i < n; i++)
    {
        if(arr[i] >= currentMx + arr[i])
        {
            tempIdx = i;
            currentMx = arr[i];
        }
        else currentMx = currentMx + arr[i];
        if(currentMx > mx)
        {
            endIdx = i;
            startIdx = tempIdx;
            mx = currentMx;
        }
    }
    //Print the sub array
   // for(int i = startIdx; i <= endIdx; i++) cout<<arr[i]<<" ";
    //cout<<endl;

    return mx;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, ans;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++) cin>>arr[i];
    ans = kadanes(arr, n);

    return 0;
}
