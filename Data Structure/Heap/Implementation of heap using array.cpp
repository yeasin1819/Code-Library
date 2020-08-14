#include <bits/stdc++.h>

#define SIZE 100000

using namespace std;

typedef struct heap Heap;

struct heap
{
    int arr[SIZE], n;

    void input()
    {
        cin>>n;
        for(int i = 0; i < n; i++) cin>>arr[i];
    }
    void heapify(int i)
    {
        int left = 2 * i + 1, right = 2 * i + 2, large = i;
        if((left < n) && (arr[large] < arr[left])) large = left;
        if((right < n) && (arr[large] < arr[right])) large = right;
        if(i != large)
        {
            swap(arr[i], arr[large]);
            heapify(large);
        }
    }
    void max_heap()
    {
        for(int i = n / 2; i >= 0; i--) heapify(i);
        int k = n;
        while(--n) swap(arr[n], arr[0]), heapify(0);
        n = k;
    }
    void min_heap()
    {
        max_heap();
        for(int i = 0; i < n / 2; i++) swap(arr[i], arr[n - i - 1]);
    }
    void print()
    {
        for(int i = 0; i < n; i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
};

int main()
{
/* input: 5
   12 5 787 1 23
*/
    Heap h;

    h.input();
    h.max_heap();
    h.print();
    h.min_heap();
    h.print();

    return 0;
}
