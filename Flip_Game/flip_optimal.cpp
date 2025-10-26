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
    
    // Try all possible column flip combinations
    int max_sum = 0;
    
    for (int mask = 0; mask < (1 << M); mask++) {
        vector<vector<int>> temp = matrix;
        
        // Apply column flips
        for (int j = 0; j < M; j++) {
            if (mask & (1 << j)) {
                for (int i = 0; i < N; i++) {
                    temp[i][j] = 1 - temp[i][j];
                }
            }
        }
        
        // For each row, decide whether to flip it
        int sum = 0;
        for (int i = 0; i < N; i++) {
            int row_value = 0;
            for (int j = 0; j < M; j++) {
                row_value = row_value * 2 + temp[i][j];
            }
            
            // Try both flipped and unflipped versions
            int flipped_value = (1 << M) - 1 - row_value;
            sum += max(row_value, flipped_value);
        }
        
        max_sum = max(max_sum, sum);
    }
    
    cout << max_sum << endl;
    return 0;
}
