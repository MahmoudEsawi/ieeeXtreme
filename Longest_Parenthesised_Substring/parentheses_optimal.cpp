#include <bits/stdc++.h>
using namespace std;

int longestParenthesisedSubstring(const string& S) {
    int n = S.length();
    if (n == 0) return -1;
    
    stack<int> st;
    st.push(-1);
    int maxLen = 0;
    
    for (int i = 0; i < n; i++) {
        if (S[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i);
            } else {
                maxLen = max(maxLen, i - st.top());
            }
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
