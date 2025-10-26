#include <bits/stdc++.h>
using namespace std;

vector<int> fibonacciSum(int n) {
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
