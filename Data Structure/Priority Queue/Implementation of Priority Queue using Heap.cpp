#include <bits/stdc++.h>

#define SIZE 100000

using namespace std;

typedef struct Priority_queue PQ;

struct Priority_queue
{
    int arr[SIZE], idx = 0;

    void heapify(int i)
    {
        int left = 2 * i + 1, right = 2 * i + 2, large = i;
        if((left < idx) && (arr[large] < arr[left])) large = left;
        if((right < idx) && (arr[large] < arr[right])) large = right;
        if(i != large)
        {
            swap(arr[i], arr[large]);
            heapify(large);
        }
    }
    void push(int data)
    {
        arr[idx] = data;
        int n = idx;
        while(idx)
        {
            int p = idx / 2;
            if(!(idx % 2)) p--;
            if(arr[p] < arr[idx]) swap(arr[p], arr[idx]);
            idx = p;
        }
        idx = n + 1;
    }
    int top()
    {
        return arr[0];
    }
    void pop()
    {
        if(idx) swap(arr[0], arr[idx - 1]);
        idx--;
        heapify(0);
    }

    void print()
    {
        for(int i = 0; i < idx; i++) cout<<arr[i]<<" ";
    }
};

int main()
{
    PQ pq;

    pq.push(1);
    pq.push(3);
    pq.push(5);
    pq.push(4);
    pq.push(6);
    pq.push(13);
    pq.push(10);

    pq.pop();
    pq.print();

    return 0;
}
