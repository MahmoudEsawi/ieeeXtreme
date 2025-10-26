#include <bits/stdc++.h>
using namespace std;

void optimalDigitsRemoval(const string& s, int K) {
    string result;
    int n = s.length();
    
    for (int i = 0; i < n; i++) {
        while (!result.empty() && result.back() < s[i] && K > 0) {
            result.pop_back();
            K--;
        }
        result.push_back(s[i]);
    }
    
    while (K > 0) {
        result.pop_back();
        K--;
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
