#include <bits/stdc++.h>
using namespace std;

vector<int> fibonacciSum(int n) {
    // Based on Zeckendorf's theorem - greedy approach
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
