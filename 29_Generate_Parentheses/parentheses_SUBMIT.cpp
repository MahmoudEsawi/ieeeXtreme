#include <bits/stdc++.h>
using namespace std;

void backtrack(string& current, int open, int close, int n) {
    if (current.length() == 2 * n) {
        cout << current << "\n";
        return;
    }
    
    if (open < n) {
        current += '(';
        backtrack(current, open + 1, close, n);
        current.pop_back();
    }
    
    if (close < open) {
        current += ')';
        backtrack(current, open, close + 1, n);
        current.pop_back();
    }
}

void generateParentheses(int N) {
    string current = "";
    backtrack(current, 0, 0, N);
}
