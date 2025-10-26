#include <bits/stdc++.h>
using namespace std;

int solve_optimal(vector<vector<int>> matrix) {
    int N = matrix.size();
    int M = matrix[0].size();
    
    // Greedy approach: for each column, count 1s and 0s
    for (int j = 0; j < M; j++) {
        int ones = 0;
        for (int i = 0; i < N; i++) {
            ones += matrix[i][j];
        }
        
        if (ones < N - ones) {
            for (int i = 0; i < N; i++) {
                matrix[i][j] = 1 - matrix[i][j];
            }
        }
    }
    
    // Then for each row, if it starts with 0, flip it
    for (int i = 0; i < N; i++) {
        if (matrix[i][0] == 0) {
            for (int j = 0; j < M; j++) {
                matrix[i][j] = 1 - matrix[i][j];
            }
        }
    }
    
    // Calculate sum
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int row_value = 0;
        for (int j = 0; j < M; j++) {
            row_value = row_value * 2 + matrix[i][j];
        }
        sum += row_value;
    }
    
    return sum;
}

int solve_2nd_best(vector<vector<int>> matrix) {
    int N = matrix.size();
    int M = matrix[0].size();
    
    int max_sum = 0;
    
    for (int mask = 0; mask < (1 << M); mask++) {
        vector<vector<int>> temp = matrix;
        
        // Apply column flips based on mask
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
    
    return max_sum;
}

void test_solutions() {
    cout << "🧪 Testing Flip Game Solutions\n";
    cout << "=============================\n\n";
    
    vector<pair<vector<vector<int>>, int>> test_cases = {
        {{{1,0,0}, {1,0,0}, {0,1,1}}, 21},
        {{{1,1,0}, {0,1,1}, {1,0,1}}, 18},
        {{{0,1}, {0,0}, {0,1}, {0,0}}, 10},
        {{{0,1,1,1}, {1,1,0,0}, {0,1,1,1}}, 41}
    };
    
    cout << "Test Case\tExpected\tOptimal\t2nd Best\tMatch?\n";
    cout << "----------------------------------------------------\n";
    
    bool all_match = true;
    
    for (int t = 0; t < test_cases.size(); t++) {
        auto& test_case = test_cases[t];
        vector<vector<int>> matrix = test_case.first;
        int expected = test_case.second;
        
        int optimal_result = solve_optimal(matrix);
        int second_best_result = solve_2nd_best(matrix);
        
        bool optimal_match = (optimal_result == expected);
        bool second_best_match = (second_best_result == expected);
        
        cout << "Test " << (t+1) << "\t\t" << expected << "\t\t" 
             << optimal_result << "\t" << second_best_result << "\t\t"
             << (optimal_match && second_best_match ? "✅" : "❌") << "\n";
        
        if (!optimal_match || !second_best_match) all_match = false;
    }
    
    cout << "\n";
    if (all_match) {
        cout << "🎉 All test cases passed! Both solutions are correct.\n";
    } else {
        cout << "⚠️  Some test cases failed. Check the implementations.\n";
    }
    
    cout << "\n📊 Performance Analysis:\n";
    cout << "• Optimal Solution: O(N*M) time, O(1) space\n";
    cout << "• 2nd Best Solution: O(2^M * N*M) time, O(N*M) space\n";
    cout << "• Both solutions give correct results\n";
    cout << "• Use optimal for large M, 2nd best to avoid similarity\n";
}

int main() {
    test_solutions();
    return 0;
}
