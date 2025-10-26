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
    
    // We need to find values that satisfy all palindrome constraints
    // and minimize the sum of final values
    
    // For each cell, we'll try all possible values 0-9
    // and pick the one that gives minimum sum while satisfying all constraints
    
    // This is a constraint satisfaction problem
    // We'll use an iterative approach
    
    bool changed = true;
    int iterations = 0;
    const int MAX_ITERATIONS = 100;
    
    while (changed && iterations < MAX_ITERATIONS) {
        changed = false;
        iterations++;
        
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
                            
                            if (grid[i][word_positions[k]] != '0' + optimal || 
                                grid[i][word_positions[n - 1 - k]] != '0' + optimal) {
                                grid[i][word_positions[k]] = '0' + optimal;
                                grid[i][word_positions[n - 1 - k]] = '0' + optimal;
                                changed = true;
                            }
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
                    
                    if (grid[i][word_positions[k]] != '0' + optimal || 
                        grid[i][word_positions[n - 1 - k]] != '0' + optimal) {
                        grid[i][word_positions[k]] = '0' + optimal;
                        grid[i][word_positions[n - 1 - k]] = '0' + optimal;
                        changed = true;
                    }
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
                            
                            if (grid[word_positions[k]][j] != '0' + optimal || 
                                grid[word_positions[n - 1 - k]][j] != '0' + optimal) {
                                grid[word_positions[k]][j] = '0' + optimal;
                                grid[word_positions[n - 1 - k]][j] = '0' + optimal;
                                changed = true;
                            }
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
                    
                    if (grid[word_positions[k]][j] != '0' + optimal || 
                        grid[word_positions[n - 1 - k]][j] != '0' + optimal) {
                        grid[word_positions[k]][j] = '0' + optimal;
                        grid[word_positions[n - 1 - k]][j] = '0' + optimal;
                        changed = true;
                    }
                }
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