#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> matrix(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }
    
    // Alternative approach: try all possible row combinations
    int max_sum = 0;
    
    for (int mask = 0; mask < (1 << N); mask++) {
        vector<vector<int>> temp = matrix;
        
        // Apply row flips
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                for (int j = 0; j < M; j++) {
                    temp[i][j] = 1 - temp[i][j];
                }
            }
        }
        
        // For each column, decide whether to flip it
        for (int j = 0; j < M; j++) {
            int ones = 0;
            for (int i = 0; i < N; i++) {
                ones += temp[i][j];
            }
            if (ones < N - ones) {
                for (int i = 0; i < N; i++) {
                    temp[i][j] = 1 - temp[i][j];
                }
            }
        }
        
        // Calculate sum
        int sum = 0;
        for (int i = 0; i < N; i++) {
            int val = 0;
            for (int j = 0; j < M; j++) {
                val = val * 2 + temp[i][j];
            }
            sum += val;
        }
        
        max_sum = max(max_sum, sum);
    }
    
    cout << max_sum << endl;
    return 0;
}
