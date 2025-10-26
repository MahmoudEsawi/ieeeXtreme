#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

struct Word {
    vector<pair<int, int>> positions;
    vector<int> original_digits;
    bool is_horizontal;
    
    Word(vector<pair<int, int>> pos, vector<int> digits, bool horizontal) 
        : positions(pos), original_digits(digits), is_horizontal(horizontal) {}
};

void processWord(Word& word, vector<vector<char>>& grid) {
    int n = word.positions.size();
    if (n <= 1) return; // Single character is already a palindrome
    
    // For each pair of positions (i, n-1-i), find optimal digit
    for (int i = 0; i < n / 2; i++) {
        int j = n - 1 - i;
        
        int digit1 = word.original_digits[i];
        int digit2 = word.original_digits[j];
        
        // Find optimal digit that minimizes |digit1 - optimal| + |digit2 - optimal|
        // This is the median of the two digits
        int optimal = (digit1 + digit2) / 2;
        
        // Update both positions in the grid
        grid[word.positions[i].first][word.positions[i].second] = '0' + optimal;
        grid[word.positions[j].first][word.positions[j].second] = '0' + optimal;
    }
    
    // Handle middle character for odd-length words
    if (n % 2 == 1) {
        int mid = n / 2;
        // Middle character stays the same (already optimal)
    }
}

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
    
    vector<Word> words;
    
    // Find horizontal words
    for (int i = 0; i < N; i++) {
        vector<pair<int, int>> current_word;
        vector<int> current_digits;
        
        for (int j = 0; j < M; j++) {
            if (grid[i][j] != '.') {
                current_word.push_back({i, j});
                current_digits.push_back(grid[i][j] - '0');
            } else {
                if (current_word.size() > 1) {
                    words.push_back(Word(current_word, current_digits, true));
                }
                current_word.clear();
                current_digits.clear();
            }
        }
        
        if (current_word.size() > 1) {
            words.push_back(Word(current_word, current_digits, true));
        }
    }
    
    // Find vertical words
    for (int j = 0; j < M; j++) {
        vector<pair<int, int>> current_word;
        vector<int> current_digits;
        
        for (int i = 0; i < N; i++) {
            if (grid[i][j] != '.') {
                current_word.push_back({i, j});
                current_digits.push_back(grid[i][j] - '0');
            } else {
                if (current_word.size() > 1) {
                    words.push_back(Word(current_word, current_digits, false));
                }
                current_word.clear();
                current_digits.clear();
            }
        }
        
        if (current_word.size() > 1) {
            words.push_back(Word(current_word, current_digits, false));
        }
    }
    
    // Process all words to make them palindromes
    for (auto& word : words) {
        processWord(word, grid);
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
