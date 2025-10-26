#include <bits/stdc++.h>
using namespace std;

long long solve(long long a, long long b, long long s, long long n) {
    // We need: x*a + y*b = s and x + y = n
    // From second: y = n - x
    // Substitute: x*a + (n-x)*b = s
    // x*a + n*b - x*b = s
    // x*(a-b) = s - n*b
    // x = (s - n*b) / (a - b)
    
    if ((s - n * b) % (a - b) != 0) {
        return -1;
    }
    
    long long x = (s - n * b) / (a - b);
    
    if (x < 0 || x > n) {
        return -1;
    }
    
    return x;
}

int main() {
    long long a, b, s, n;
    cin >> a >> b >> s >> n;
    
    cout << solve(a, b, s, n) << "\n";
    
    return 0;
}
