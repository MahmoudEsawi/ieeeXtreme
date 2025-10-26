#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, m, x, y;
    cin >> n >> m >> x >> y;
    
    // We want to evolve k pokemon
    // We sell (n - k) pokemon
    // Total candy: m + (n - k) * y
    // Need: k * x
    // So: m + (n - k) * y >= k * x
    // m + n*y - k*y >= k*x
    // m + n*y >= k*x + k*y
    // m + n*y >= k*(x + y)
    // k <= (m + n*y) / (x + y)
    
    long long maxByCandy = (m + n * y) / (x + y);
    long long ans = min(n, maxByCandy);
    
    cout << ans << "\n";
    
    return 0;
}