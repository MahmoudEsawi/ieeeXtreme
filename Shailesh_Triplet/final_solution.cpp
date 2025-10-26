#include <iostream>
using namespace std;

void solve(long long n) {
    if (n == 1 || n == 7) {
        cout << "-1\n";
        return;
    }
    
    if (n & 1) {
        cout << "-1\n";
        return;
    }
    
    if (n == 20) {
        cout << "22 8 10\n";
        return;
    }
    
    if (n == 52) {
        cout << "54 24 26\n";
        return;
    }
    
    long long a = n + 2;
    long long b = ((n - 2) >> 1) - 1;
    long long c = ((n - 2) >> 1) + 1;
    
    if (b > 0 && c > 0 && a != b && a != c && b != c) {
        cout << a << " " << b << " " << c << "\n";
        return;
    }
    
    a = n + 1;
    b = n - 1;
    c = 0;
    
    if (b > 0 && c >= 0 && a != b && a != c && b != c) {
        cout << a << " " << b << " " << c << "\n";
        return;
    }
    
    a = n;
    b = n - 2;
    c = 2;
    
    if (b > 0 && c > 0 && a != b && a != c && b != c) {
        cout << a << " " << b << " " << c << "\n";
        return;
    }
    
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long n;
        cin >> n;
        solve(n);
    }
    
    return 0;
}
