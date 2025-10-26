#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> b(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Original position
            if (a[i][j] == 1) b[i][j] = 1;
            
            // 90 degree rotation: (i,j) -> (j, n-1-i)
            if (a[j][n - 1 - i] == 1) b[i][j] = 1;
            
            // 180 degree rotation: (i,j) -> (n-1-i, n-1-j)
            if (a[n - 1 - i][n - 1 - j] == 1) b[i][j] = 1;
            
            // 270 degree rotation: (i,j) -> (n-1-j, i)
            if (a[n - 1 - j][i] == 1) b[i][j] = 1;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << b[i][j];
            if (j < n - 1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
