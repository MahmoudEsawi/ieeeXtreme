#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b;
    cin >> a >> b;
    
    // A number has odd divisors if and only if it's a perfect square
    int cnt = 0;
    
    int sqrtA = ceil(sqrt(a));
    int sqrtB = floor(sqrt(b));
    
    cnt = max(0, sqrtB - sqrtA + 1);
    
    cout << cnt << "\n";
    
    return 0;
}
