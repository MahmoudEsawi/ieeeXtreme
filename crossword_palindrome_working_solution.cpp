#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<char>> grid(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }
    
    // Process horizontal words
    for (int i = 0; i < N; i++) {
        vector<int> word_positions;
        vector<int> word_digits;
        
        for (int j = 0; j < M; j++) {
            if (grid[i][j] != '.') {
                word_positions.push_back(j);
                word_digits.push_back(grid[i][j] - '0');
            } else {
                if (word_positions.size() > 1) {
                    // Process this word to make it palindrome
                    int n = word_positions.size();
                    for (int k = 0; k < n / 2; k++) {
                        int left = word_digits[k];
                        int right = word_digits[n - 1 - k];
                        int optimal = (left + right) / 2;
                        
                        grid[i][word_positions[k]] = '0' + optimal;
                        grid[i][word_positions[n - 1 - k]] = '0' + optimal;
                    }
                }
                word_positions.clear();
                word_digits.clear();
            }
        }
        
        if (word_positions.size() > 1) {
            // Process this word to make it palindrome
            int n = word_positions.size();
            for (int k = 0; k < n / 2; k++) {
                int left = word_digits[k];
                int right = word_digits[n - 1 - k];
                int optimal = (left + right) / 2;
                
                grid[i][word_positions[k]] = '0' + optimal;
                grid[i][word_positions[n - 1 - k]] = '0' + optimal;
            }
        }
    }
    
    // Process vertical words
    for (int j = 0; j < M; j++) {
        vector<int> word_positions;
        vector<int> word_digits;
        
        for (int i = 0; i < N; i++) {
            if (grid[i][j] != '.') {
                word_positions.push_back(i);
                word_digits.push_back(grid[i][j] - '0');
            } else {
                if (word_positions.size() > 1) {
                    // Process this word to make it palindrome
                    int n = word_positions.size();
                    for (int k = 0; k < n / 2; k++) {
                        int left = word_digits[k];
                        int right = word_digits[n - 1 - k];
                        int optimal = (left + right) / 2;
                        
                        grid[word_positions[k]][j] = '0' + optimal;
                        grid[word_positions[n - 1 - k]][j] = '0' + optimal;
                    }
                }
                word_positions.clear();
                word_digits.clear();
            }
        }
        
        if (word_positions.size() > 1) {
            // Process this word to make it palindrome
            int n = word_positions.size();
            for (int k = 0; k < n / 2; k++) {
                int left = word_digits[k];
                int right = word_digits[n - 1 - k];
                int optimal = (left + right) / 2;
                
                grid[word_positions[k]][j] = '0' + optimal;
                grid[word_positions[n - 1 - k]][j] = '0' + optimal;
            }
        }
    }
    
    // Output the result
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}
