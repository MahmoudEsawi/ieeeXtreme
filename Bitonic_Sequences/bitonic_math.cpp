#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int M;
    cin >> M;
    
    vector<vector<long long>> dp(M + 1, vector<long long>(M + 1, 0));
    
    for (int i = 0; i <= M; i++) {
        dp[i][0] = 1;
    }
    
    for (int sum = 1; sum <= M; sum++) {
        for (int last = 1; last <= sum; last++) {
            for (int prev = 1; prev <= last; prev++) {
                dp[sum][last] = (dp[sum][last] + dp[sum - last][prev]) % MOD;
            }
        }
    }
    
    vector<long long> bitonic(M + 1, 0);
    
    for (int n = 1; n <= M; n++) {
        for (int peak = 1; peak <= n; peak++) {
            long long left = 0;
            long long right = 0;
            
            for (int last = 1; last <= peak; last++) {
                left = (left + dp[n - peak][last]) % MOD;
            }
            
            for (int last = 1; last <= peak; last++) {
                right = (right + dp[n - peak][last]) % MOD;
            }
            
            bitonic[n] = (bitonic[n] + (left * right) % MOD) % MOD;
        }
    }
    
    for (int i = 1; i <= M; i++) {
        cout << bitonic[i];
        if (i < M) cout << " ";
    }
    cout << "\n";
    
    return 0;
}



