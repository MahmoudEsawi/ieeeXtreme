#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int M;
    cin >> M;
    
    // dp[sum][last] = number of strictly increasing sequences with sum 'sum' ending with 'last'
    vector<vector<long long>> dp(M + 1, vector<long long>(M + 1, 0));
    
    // Base case: empty sequence
    for (int i = 0; i <= M; i++) {
        dp[0][i] = 1;
    }
    
    // Fill DP: dp[sum][last] = sum of dp[sum-last][prev] for prev < last
    for (int sum = 1; sum <= M; sum++) {
        for (int last = 1; last <= sum; last++) {
            for (int prev = 1; prev < last; prev++) {
                if (sum - last >= 0) {
                    dp[sum][last] = (dp[sum][last] + dp[sum - last][prev]) % MOD;
                }
            }
        }
    }
    
    // Precompute prefix sums for O(1) lookup
    vector<vector<long long>> prefix(M + 1, vector<long long>(M + 1, 0));
    for (int sum = 0; sum <= M; sum++) {
        for (int last = 1; last <= M; last++) {
            prefix[sum][last] = (prefix[sum][last - 1] + dp[sum][last]) % MOD;
        }
    }
    
    // Calculate bitonic sequences
    vector<long long> bitonic(M + 1, 0);
    
    for (int n = 1; n <= M; n++) {
        // Case 1: Peak is the only element
        bitonic[n] = 1;
        
        // Case 2: Peak with elements on both sides
        for (int peak = 1; peak <= n; peak++) {
            int remaining = n - peak;
            
            if (remaining > 0) {
                // Number of strictly increasing sequences with sum 'remaining' ending with value < peak
                long long ways = prefix[remaining][peak - 1];
                
                // Both increasing and decreasing parts have same count due to symmetry
                bitonic[n] = (bitonic[n] + (ways * ways) % MOD) % MOD;
            }
        }
    }
    
    // Output results
    for (int i = 1; i <= M; i++) {
        cout << bitonic[i];
        if (i < M) cout << " ";
    }
    cout << "\n";
    
    return 0;
}