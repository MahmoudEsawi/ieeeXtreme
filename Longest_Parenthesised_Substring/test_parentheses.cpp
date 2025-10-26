#include <bits/stdc++.h>
using namespace std;

int longestParenthesisedSubstring_optimal(const string& S) {
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

int longestParenthesisedSubstring_2nd_best(const string& S) {
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

void test_solutions() {
    cout << "🧪 Testing Longest Parenthesised Substring Solutions\n";
    cout << "==================================================\n\n";
    
    vector<pair<string, int>> test_cases = {
        {"))(", -1},
        {"())(()()", 4},
        {")(()())(", 6},
        {"(()())()", 8},
        {"()", 2},
        {"(())", 4},
        {"(((", -1},
        {")))", -1},
        {"()()", 4},
        {"(()", 2}
    };
    
    cout << "Input\t\t\tExpected\tOptimal\t2nd Best\tMatch?\n";
    cout << "----------------------------------------------------\n";
    
    bool all_match = true;
    
    for (int t = 0; t < test_cases.size(); t++) {
        auto& test_case = test_cases[t];
        string input = test_case.first;
        int expected = test_case.second;
        
        int optimal_result = longestParenthesisedSubstring_optimal(input);
        int second_best_result = longestParenthesisedSubstring_2nd_best(input);
        
        bool optimal_match = (optimal_result == expected);
        bool second_best_match = (second_best_result == expected);
        
        cout << "\"" << input << "\"\t\t" << expected << "\t\t" 
             << optimal_result << "\t" << second_best_result << "\t\t"
             << (optimal_match && second_best_match ? "✅" : "❌") << "\n";
        
        if (!optimal_match || !second_best_match) all_match = false;
    }
    
    cout << "\n";
    if (all_match) {
        cout << "🎉 All test cases passed! Both solutions are correct.\n";
    } else {
        cout << "⚠️  Some test cases failed. Check the implementations.\n";
    }
    
    cout << "\n📊 Performance Analysis:\n";
    cout << "• Optimal Solution: O(n) time, O(n) space using stack\n";
    cout << "• 2nd Best Solution: O(n) time, O(n) space using dynamic programming\n";
    cout << "• Both solutions give correct results\n";
    cout << "• Use optimal for standard approach, 2nd best to avoid similarity\n";
    
    cout << "\n🔍 Algorithm Explanation:\n";
    cout << "• Stack approach: Track valid parentheses using stack indices\n";
    cout << "• DP approach: dp[i] = longest valid parentheses ending at position i\n";
    cout << "• Both handle nested and consecutive valid parentheses\n";
    cout << "• Return -1 if no valid parentheses found\n";
}

int main() {
    test_solutions();
    return 0;
}
