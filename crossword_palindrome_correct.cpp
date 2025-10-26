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
    
    // We need to process all words and find the optimal values
    // that satisfy all constraints simultaneously
    
    // First, let's find all words and their constraints
    vector<vector<pair<int, int>>> words;
    
    // Find horizontal words
    for (int i = 0; i < N; i++) {
        vector<pair<int, int>> current_word;
        for (int j = 0; j < M; j++) {
            if (grid[i][j] != '.') {
                current_word.push_back({i, j});
            } else {
                if (current_word.size() > 1) {
                    words.push_back(current_word);
                }
                current_word.clear();
            }
        }
        if (current_word.size() > 1) {
            words.push_back(current_word);
        }
    }
    
    // Find vertical words
    for (int j = 0; j < M; j++) {
        vector<pair<int, int>> current_word;
        for (int i = 0; i < N; i++) {
            if (grid[i][j] != '.') {
                current_word.push_back({i, j});
            } else {
                if (current_word.size() > 1) {
                    words.push_back(current_word);
                }
                current_word.clear();
            }
        }
        if (current_word.size() > 1) {
            words.push_back(current_word);
        }
    }
    
    // Now process each word to make it a palindrome
    // We'll use an iterative approach to handle overlapping constraints
    bool changed = true;
    while (changed) {
        changed = false;
        
        for (auto& word : words) {
            int n = word.size();
            for (int k = 0; k < n / 2; k++) {
                int i1 = word[k].first, j1 = word[k].second;
                int i2 = word[n - 1 - k].first, j2 = word[n - 1 - k].second;
                
                int digit1 = grid[i1][j1] - '0';
                int digit2 = grid[i2][j2] - '0';
                int optimal = (digit1 + digit2) / 2;
                
                if (grid[i1][j1] != '0' + optimal || grid[i2][j2] != '0' + optimal) {
                    grid[i1][j1] = '0' + optimal;
                    grid[i2][j2] = '0' + optimal;
                    changed = true;
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