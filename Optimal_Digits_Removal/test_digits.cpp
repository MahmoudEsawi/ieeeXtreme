#include <bits/stdc++.h>
using namespace std;

void optimalDigitsRemoval_optimal(const string& s, int K) {
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
    
    cout << result;
}

void optimalDigitsRemoval_2nd_best(const string& s, int K) {
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
    
    cout << result;
}

void test_solutions() {
    cout << "🧪 Testing Optimal Digits Removal Solutions\n";
    cout << "==========================================\n\n";
    
    vector<pair<string, int>> test_cases = {
        {"1234", 1},
        {"305069", 3},
        {"123456789", 2},
        {"987654321", 3},
        {"111111", 2},
        {"54321", 2},
        {"12345", 0},
        {"999", 1}
    };
    
    cout << "Test Case\t\tK\tOptimal\t\t2nd Best\tMatch?\n";
    cout << "--------------------------------------------------------\n";
    
    bool all_match = true;
    
    for (int t = 0; t < test_cases.size(); t++) {
        string input = test_cases[t].first;
        int K = test_cases[t].second;
        
        cout << "Test " << (t+1) << ": " << input << "\t" << K << "\t";
        
        // Test optimal solution
        stringstream opt_ss;
        streambuf* opt_cout = cout.rdbuf();
        cout.rdbuf(opt_ss.rdbuf());
        optimalDigitsRemoval_optimal(input, K);
        cout.rdbuf(opt_cout);
        string opt_result = opt_ss.str();
        
        // Test 2nd best solution
        stringstream best_ss;
        streambuf* best_cout = cout.rdbuf();
        cout.rdbuf(best_ss.rdbuf());
        optimalDigitsRemoval_2nd_best(input, K);
        cout.rdbuf(best_cout);
        string best_result = best_ss.str();
        
        bool match = (opt_result == best_result);
        all_match = all_match && match;
        
        cout << opt_result << "\t\t" << best_result << "\t\t" << (match ? "✅" : "❌") << "\n";
    }
    
    cout << "\n📊 Performance Analysis:\n";
    cout << "• Optimal Solution: O(N) time, O(1) space using direct K decrement\n";
    cout << "• 2nd Best Solution: O(N) time, O(1) space using removed counter\n";
    cout << "• Both solutions use greedy stack approach\n";
    cout << "• Different variable tracking: K vs removed counter\n";
    
    cout << "\n🔍 Algorithm Explanation:\n";
    cout << "• Greedy approach: Remove smaller digits from left to right\n";
    cout << "• Stack-like behavior: Keep result string as stack\n";
    cout << "• For each digit: remove smaller digits from end of result\n";
    cout << "• If still need to remove: remove from end (smallest digits)\n";
    cout << "• Key insight: Removing smaller digits early maximizes result\n";
    
    cout << "\n💡 Key Differences:\n";
    cout << "• Optimal: Directly decrements K parameter\n";
    cout << "• 2nd Best: Uses separate 'removed' counter variable\n";
    cout << "• Both achieve same result with different tracking methods\n";
}

int main() {
    test_solutions();
    return 0;
}
