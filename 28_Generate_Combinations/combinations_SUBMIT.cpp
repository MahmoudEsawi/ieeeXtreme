#include <bits/stdc++.h>
using namespace std;

void backtrack(int start, int n, int k, vector<int>& current) {
    if (current.size() == k) {
        for (int i = 0; i < k; ++i) {
            cout << current[i];
            if (i < k - 1) cout << " ";
        }
        cout << "\n";
        return;
    }
    
    for (int i = start; i <= n; ++i) {
        current.push_back(i);
        backtrack(i + 1, n, k, current);
        current.pop_back();
    }
}

void generateCombinations(int N, int K) {
    vector<int> current;
    backtrack(1, N, K, current);
}
