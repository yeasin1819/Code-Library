#include <bits/stdc++.h>

using namespace std;

int queen[20], column[20], diagonal1[20],diagonal2[20];

void nQueen(int row, int n) {
  
    if(row > n) {
        
        for(int i = 1; i <= n; i++) {
            cout<<i<<" "<<queen[i]<<", ";//row , column
        }
        cout<<endl;
        return;
    }
  
    for(int col = 1; col <= n; col++) {
        if(column[col] || diagonal1[row + col] || diagonal2[n + col - row])
            continue;
        queen[row] = col;
        column[col] = diagonal1[row+col] = diagonal2[n + col - row] = 1;
        nQueen(row + 1, n);
        column[col] = diagonal1[row+col] = diagonal2[n + col - row] = 0;
    }
}

int main() {

    nQueen(1, 8);
    return 0;
}