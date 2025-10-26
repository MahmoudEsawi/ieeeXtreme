#include <iostream>
using namespace std;

long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

long long modInverse(long long a, long long mod) {
    return modPow(a, mod - 2, mod);
}

void addPoints(long long a, long long b, long long p, long long x1, long long y1, long long x2, long long y2) {
    if (x1 == x2 && y1 == y2) {
        if (y1 == 0) {
            cout << "POINT_AT_INFINITY\n";
            return;
        }
        
        long long slope = ((3 * x1 * x1 + a) % p * modInverse(2 * y1, p)) % p;
        long long x3 = (slope * slope - 2 * x1) % p;
        long long y3 = (slope * (x1 - x3) - y1) % p;
        
        if (x3 < 0) x3 += p;
        if (y3 < 0) y3 += p;
        
        cout << x3 << " " << y3 << "\n";
    } else {
        if (x1 == x2) {
            cout << "POINT_AT_INFINITY\n";
            return;
        }
        
        long long slope = ((y2 - y1) % p * modInverse(x2 - x1, p)) % p;
        long long x3 = (slope * slope - x1 - x2) % p;
        long long y3 = (slope * (x1 - x3) - y1) % p;
        
        if (x3 < 0) x3 += p;
        if (y3 < 0) y3 += p;
        
        cout << x3 << " " << y3 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long a, b, p, x1, y1, x2, y2;
        cin >> a >> b >> p >> x1 >> y1 >> x2 >> y2;
        addPoints(a, b, p, x1, y1, x2, y2);
    }
    
    return 0;
}

