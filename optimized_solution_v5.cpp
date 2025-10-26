#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int M;
    cin >> M;
    
    // Precompute partition numbers with constraints
    // P[s][k] = number of ways to partition s using parts <= k
    vector<vector<int>> P(M + 1, vector<int>(M + 1, 0));
    
    // Base cases
    for (int k = 0; k <= M; ++k) {
        P[0][k] = 1; // One way to partition 0
    }
    
    // Fill the partition table - O(M^2)
    for (int s = 1; s <= M; ++s) {
        for (int k = 1; k <= M; ++k) {
            P[s][k] = P[s][k - 1]; // Don't use k
            if (s >= k) {
                P[s][k] = (P[s][k] + P[s - k][k]) % MOD; // Use at least one k
            }
        }
    }
    
    // Compute the final answer using a more efficient approach
    vector<long long> result(M + 1, 0);
    
    // For each possible peak value
    for (int peak = 1; peak <= M; ++peak) {
        // For each possible left sum (excluding peak)
        for (int left_sum = 0; left_sum <= M - peak; ++left_sum) {
            // For each possible right sum
            for (int right_sum = 0; right_sum <= M - peak - left_sum; ++right_sum) {
                int N = left_sum + right_sum + peak;
                if (N > M) continue;
                
                // Use precomputed partition numbers with constraints
                long long ways_left = P[left_sum][peak];
                long long ways_right = (peak > 1) ? P[right_sum][peak - 1] : (right_sum == 0 ? 1 : 0);
                
                long long contribution = (ways_left * ways_right) % MOD;
                result[N] = (result[N] + contribution) % MOD;
            }
        }
    }
    
    // Output results
    for (int N = 1; N <= M; ++N) {
        cout << result[N] << "\n";
    }
    
    return 0;
}
