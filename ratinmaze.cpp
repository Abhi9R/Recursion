#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

bool isSafe(int** a, int x, int y, int n) {
    if(x < n && y < n && a[x][y] == 1) {
        return true;
    }
    return false;
}

bool ratInMaze(int** a, int x, int y, int n, int** solArr) {

    if(x == n-1 && y == n-1) {
        solArr[x][y] = 1;
        return true;
    }

    if(isSafe(a, x, y, n)) {
        solArr[x][y] = 1;
        if(ratInMaze(a,x+1,y,n,solArr)) {
            return true;
        }

        if(ratInMaze(a, x, y+1, n, solArr)) {
            return true;
        }

        solArr[x][y] = 0;       //Backtracking
        return false;
    }

    return false;
}

int32_t main() {
    int n;
    cin >> n;

    int** a = new int*[n];
    for(int i=0;i<n;i++) {
        a[i] = new int[n];
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> a[i][j];
        }
    }

    int** solArr = new int*[n];
    for(int i=0;i<n;i++) {
        solArr[i] = new int[n];
        for(int j=0;j<n;j++) {
            solArr[i][j] = 0;
        }
    }
    
    cout << endl;
    if(ratInMaze(a,0,0,n,solArr)) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout << solArr[i][j] << " ";
            } cout << endl;
        }
    }

    return 0;
}

/*
1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1
*/