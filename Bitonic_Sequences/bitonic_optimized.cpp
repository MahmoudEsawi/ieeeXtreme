#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int M;
    cin >> M;
    
    // dp[sum][last] = number of non-decreasing sequences with sum 'sum' ending with 'last'
    vector<vector<long long>> dp(M + 1, vector<long long>(M + 1, 0));
    
    // Base case: empty sequence has sum 0
    for (int i = 0; i <= M; i++) {
        dp[0][i] = 1;
    }
    
    // Fill DP table for non-decreasing sequences
    // dp[sum][last] = sum of dp[sum-last][prev] for all prev <= last
    for (int sum = 1; sum <= M; sum++) {
        for (int last = 1; last <= sum; last++) {
            // For each possible previous element (prev <= last)
            for (int prev = 1; prev <= last; prev++) {
                if (sum - last >= 0) {
                    dp[sum][last] = (dp[sum][last] + dp[sum - last][prev]) % MOD;
                }
            }
        }
    }
    
    // Precompute prefix sums for optimization
    // prefix[sum][last] = sum of dp[sum][1] + dp[sum][2] + ... + dp[sum][last]
    vector<vector<long long>> prefix(M + 1, vector<long long>(M + 1, 0));
    for (int sum = 0; sum <= M; sum++) {
        for (int last = 1; last <= M; last++) {
            prefix[sum][last] = (prefix[sum][last - 1] + dp[sum][last]) % MOD;
        }
    }
    
    // Calculate bitonic sequences
    vector<long long> bitonic(M + 1, 0);
    
    for (int n = 1; n <= M; n++) {
        // For each possible peak value
        for (int peak = 1; peak <= n; peak++) {
            // Remaining sum after placing the peak
            int remaining = n - peak;
            
            // Number of ways to form increasing part ending at peak
            // This is the same as number of non-decreasing sequences with sum 'remaining' 
            // ending with any value <= peak
            long long increasing_ways = prefix[remaining][peak];
            
            // Number of ways to form decreasing part starting from peak
            // Due to symmetry, this equals the increasing part
            long long decreasing_ways = increasing_ways;
            
            // Total ways for this peak = increasing_ways * decreasing_ways
            bitonic[n] = (bitonic[n] + (increasing_ways * decreasing_ways) % MOD) % MOD;
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
