#include <bits/stdc++.h>

using namespace std;

int getMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 0; i < n; i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int arr[], int n, int pos) {
    int output[n], count[10] = {0};
    //count occurences
    for(int i = 0; i < n; i++) {
        count[(arr[i] / pos) % 10]++;
    }
    //prefix sum to find element position in output[]
    for(int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    //build output array
    for(int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / pos) % 10] - 1] = arr[i];
        count[(arr[i] / pos) % 10]--;
    }
    //Copy Output[] to arr[]
    for(int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    for(int pos = 1; max / pos > 0; pos *= 10) {
        countingSort(arr, n, pos);
    }
}

int main() {

    freopen("D:\\c++\\cp\\input.txt", "r", stdin);
    //freopen("D:\\c++\\cp\\output.txt", "w", stdout);

    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++) cin>>arr[i];

    radixSort(arr, n);

    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}