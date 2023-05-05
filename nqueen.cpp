#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool isSafe(int** a, int x, int y,  int n) {
    
    for(int i=0;i<x;i++) {
        if(a[i][y] == 1) {
            return false;
        }
    }

    int i = x, j = y;
    while(i >= 0 && j >= 0) {
        if(a[i][j] == 1) {
            return false;
        }
        i--;
        j--;
    }

    i = x, j = y;
    while(i >= 0 && j < n) {
        if(a[i][j] == 1) {
            return false;
        }
        i--;
        j++;
    }

    return true;
}

bool nQueen(int** a, int x, int n) {

    if(x >= n) {
        return true;
    }

    for(int i=0;i < n;i++) {
        if(isSafe(a, x, i, n)) {
            a[x][i] = 1;

            if(nQueen(a,x+1, n)) {
                return true;
            }

            a[x][i] = 0;      // Backtracking 
        }
    }
    return false;

}

int32_t main() {
    int n;
    cin >> n;

    int** a = new int*[n];
    for(int i=0;i<n;i++) {
        a[i] = new int[n];
        for(int j=0;j<n;j++) {
            a[i][j] = 0;
        }
    }

    if(nQueen(a, 0, n)) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout << a[i][j] << " ";
            } cout << endl;
        }
    }

    return 0;
}