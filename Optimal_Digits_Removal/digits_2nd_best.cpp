#include <bits/stdc++.h>
using namespace std;

void optimalDigitsRemoval(const string& s, int K) {
    string result;
    int n = s.length();
    int removed = 0;
    
    for (int i = 0; i < n; i++) {
        while (result.size() > 0 && result.back() < s[i] && removed < K) {
            result.pop_back();
            removed++;
        }
        result.push_back(s[i]);
    }
    
    while (removed < K) {
        result.pop_back();
        removed++;
    }
    
    cout << result << "\n";
}

int main() {
    int N, K;
    cin >> N >> K;
    string input;
    cin >> input;
    optimalDigitsRemoval(input, K);
    return 0;
}
