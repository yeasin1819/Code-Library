#include <bits/stdc++.h>

#define SIZE 20

using namespace std;

bool taken[SIZE];
int subset[SIZE];
vector<int>subsets[SIZE];
void subsetsGenerator(int arr[], int idx, int n, int set_len) {
    if(idx == n) return;
    for(int i = 0; i < set_len; i++) {
        subsets[set_len].push_back(subset[i]);
    }

    for(int i = idx; i < n; i++) {
        if(!taken[i]) {
            subset[set_len] = arr[i];
            taken[i] = true;
            subsetsGenerator(arr, i, n, set_len + 1);
            taken[i] = false;
        }
    }
}

int main(){

    int arr[] = {1, 2, 3, 4};

    subsetsGenerator(arr, 0, 4, 0);
    for(int i = 1; i < 5; i++) {
        for(int j = 0; j < subsets[i].size(); j++) {
            if(!j || j % i == 0) cout<<"{ ";
            cout<<subsets[i][j]<<" ";
            if((j + 1) % i == 0) cout<<"} ";
        }
        cout<<endl;
    }
    return 0;
}