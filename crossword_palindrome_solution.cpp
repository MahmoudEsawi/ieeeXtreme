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
    
    // Find all words and their constraints
    vector<vector<pair<int, int>>> horizontal_words;
    vector<vector<pair<int, int>>> vertical_words;
    
    // Find horizontal words
    for (int i = 0; i < N; i++) {
        vector<pair<int, int>> current_word;
        for (int j = 0; j < M; j++) {
            if (grid[i][j] != '.') {
                current_word.push_back({i, j});
            } else {
                if (current_word.size() > 1) {
                    horizontal_words.push_back(current_word);
                }
                current_word.clear();
            }
        }
        if (current_word.size() > 1) {
            horizontal_words.push_back(current_word);
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
                    vertical_words.push_back(current_word);
                }
                current_word.clear();
            }
        }
        if (current_word.size() > 1) {
            vertical_words.push_back(current_word);
        }
    }
    
    // Process horizontal words
    for (auto& word : horizontal_words) {
        int n = word.size();
        for (int k = 0; k < n / 2; k++) {
            int i1 = word[k].first, j1 = word[k].second;
            int i2 = word[n - 1 - k].first, j2 = word[n - 1 - k].second;
            
            int digit1 = grid[i1][j1] - '0';
            int digit2 = grid[i2][j2] - '0';
            int optimal = (digit1 + digit2) / 2;
            
            grid[i1][j1] = '0' + optimal;
            grid[i2][j2] = '0' + optimal;
        }
    }
    
    // Process vertical words
    for (auto& word : vertical_words) {
        int n = word.size();
        for (int k = 0; k < n / 2; k++) {
            int i1 = word[k].first, j1 = word[k].second;
            int i2 = word[n - 1 - k].first, j2 = word[n - 1 - k].second;
            
            int digit1 = grid[i1][j1] - '0';
            int digit2 = grid[i2][j2] - '0';
            int optimal = (digit1 + digit2) / 2;
            
            grid[i1][j1] = '0' + optimal;
            grid[i2][j2] = '0' + optimal;
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