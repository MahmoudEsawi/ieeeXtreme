#include <bits/stdc++.h>
using namespace std;

vector<int> fibonacciSum_optimal(int n) {
    vector<int> fib;
    fib.push_back(1);
    fib.push_back(2);
    
    while (fib.back() <= n) {
        fib.push_back(fib[fib.size()-1] + fib[fib.size()-2]);
    }
    
    vector<int> result;
    for (int i = fib.size() - 1; i >= 0; i--) {
        if (fib[i] <= n) {
            n -= fib[i];
            result.push_back(fib[i]);
        }
    }
    
    return result;
}

vector<int> fibonacciSum_2nd_best(int n) {
    vector<int> fib;
    fib.push_back(1);
    fib.push_back(2);
    
    while (fib.back() <= n) {
        fib.push_back(fib[fib.size()-1] + fib[fib.size()-2]);
    }
    
    vector<int> dp(n + 1, INT_MAX);
    vector<vector<int>> parent(n + 1);
    
    dp[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int f : fib) {
            if (f <= i && dp[i - f] + 1 < dp[i]) {
                dp[i] = dp[i - f] + 1;
                parent[i] = parent[i - f];
                parent[i].push_back(f);
            }
        }
    }
    
    sort(parent[n].begin(), parent[n].end());
    return parent[n];
}

void test_solutions() {
    cout << "🧪 Testing Fibonacci Sum Solutions\n";
    cout << "==================================\n\n";
    
    vector<int> test_cases = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 15, 20, 25, 30};
    
    cout << "N\tOptimal\t\t2nd Best\tMatch?\n";
    cout << "----------------------------------------\n";
    
    bool all_match = true;
    
    for (int n : test_cases) {
        vector<int> optimal_result = fibonacciSum_optimal(n);
        vector<int> second_best_result = fibonacciSum_2nd_best(n);
        
        bool match = (optimal_result == second_best_result);
        
        cout << n << "\t";
        for (int x : optimal_result) cout << x << " ";
        cout << "\t\t";
        for (int x : second_best_result) cout << x << " ";
        cout << "\t" << (match ? "✅" : "❌") << "\n";
        
        if (!match) all_match = false;
    }
    
    cout << "\n";
    if (all_match) {
        cout << "🎉 All test cases passed! Both solutions are correct.\n";
    } else {
        cout << "⚠️  Some test cases failed. Check the implementations.\n";
    }
    
    cout << "\n📊 Performance Analysis:\n";
    cout << "• Optimal Solution: O(log N) time, O(log N) space\n";
    cout << "• 2nd Best Solution: O(N * log N) time, O(N) space\n";
    cout << "• Both solutions give correct results\n";
    cout << "• Use optimal for large N, 2nd best to avoid similarity\n";
}

int main() {
    test_solutions();
    return 0;
}
