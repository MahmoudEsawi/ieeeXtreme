#include <bits/stdc++.h>
using namespace std;

int longestParenthesisedSubstring(const string& S) {
    int n = S.length();
    if (n == 0) return -1;
    
    vector<int> dp(n, 0);
    int maxLen = 0;
    
    for (int i = 1; i < n; i++) {
        if (S[i] == ')') {
            if (S[i-1] == '(') {
                dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
            } else if (i - dp[i-1] > 0 && S[i - dp[i-1] - 1] == '(') {
                dp[i] = dp[i-1] + 2 + (i - dp[i-1] >= 2 ? dp[i - dp[i-1] - 2] : 0);
            }
            maxLen = max(maxLen, dp[i]);
        }
    }
    
    return maxLen == 0 ? -1 : maxLen;
}

int main() {
    string S;
    cin >> S;
    cout << longestParenthesisedSubstring(S) << "\n";
    return 0;
}
