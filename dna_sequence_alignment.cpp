#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    string a, b;
    int match, mismatch, gap;
    
    cin >> n >> a >> m >> b >> match >> mismatch >> gap;
    
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MIN));
    dp[0][0] = 0;
    
    for (int i = 1; i <= n; i++) {
        dp[i][0] = (long long)i * i * gap;
    }
    for (int j = 1; j <= m; j++) {
        dp[0][j] = (long long)j * j * gap;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            long long match_mismatch = dp[i-1][j-1] + (a[i-1] == b[j-1] ? match : mismatch);
            
            long long gap_a = LLONG_MIN;
            for (int k = 1; k <= i; k++) {
                if (dp[i-k][j] != LLONG_MIN) {
                    gap_a = max(gap_a, dp[i-k][j] + (long long)k * k * gap);
                }
            }
            
            long long gap_b = LLONG_MIN;
            for (int k = 1; k <= j; k++) {
                if (dp[i][j-k] != LLONG_MIN) {
                    gap_b = max(gap_b, dp[i][j-k] + (long long)k * k * gap);
                }
            }
            
            dp[i][j] = max({match_mismatch, gap_a, gap_b});
        }
    }
    
    cout << dp[n][m] << endl;
    
    return 0;
}
