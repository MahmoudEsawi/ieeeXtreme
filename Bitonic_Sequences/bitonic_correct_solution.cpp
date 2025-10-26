#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int M;
    cin >> M;
    
    // dp[sum] = number of ways to partition sum into positive integers
    vector<long long> dp(M + 1, 0);
    dp[0] = 1;
    
    // Fill DP: dp[sum] = sum of dp[sum - i] for all i from 1 to sum
    for (int sum = 1; sum <= M; sum++) {
        for (int i = 1; i <= sum; i++) {
            dp[sum] = (dp[sum] + dp[sum - i]) % MOD;
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
                // Number of ways to partition remaining sum
                long long ways = dp[remaining];
                
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