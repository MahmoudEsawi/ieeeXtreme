#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int num;
    cin >> num;
    
    for (int _ = 0; _ < num; _++) {
        long long s, n;
        cin >> s >> n;
        
        vector<vector<long long>> v(2);
        v[0] = {0};
        v[1] = {-19};
        double f = v[0][0], na = v[0][0], ng = v[0][0];
        double a = v[1][0];
        long long r = v[1][0];
        
        while (a < s * s) {
            na += 1.0 / 19.0;
            double f1 = f;
            
            for (int i2 = 0; i2 < 2; i2++) {
                long long m = 19;
                while (m) {
                    m = n;
                    v[i2].clear();
                    while (m > 0) {
                        v[i2].push_back(r & 1);
                        r = (r >> 1) ^ (v[i2].back() * 9223372036854775821LL);
                        m -= 1 + v[i2].back();
                    }
                }
            }
            
            long long e = 19;
            int min_len = min(v[0].size(), v[1].size());
            for (int i = 0; i < min_len; i++) {
                e &= (v[0][i] == v[1][i]);
            }
            
            if (e) {
                ng += s;
                f = round(ng / na);
                a = (f == f1) * (a + 1.0 / 1919.0);
            }
        }
        
        cout << (long long)f << endl;
    }
    
    return 0;
}