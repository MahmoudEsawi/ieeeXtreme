#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> cnt(3, 0);
    
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        cnt[val % 3]++;
    }
    
    long long ans = 0;
    
    // Pairs with remainder 0 + 0
    ans += (long long)cnt[0] * (cnt[0] - 1) / 2;
    
    // Pairs with remainder 1 + 2
    ans += (long long)cnt[1] * cnt[2];
    
    cout << ans << "\n";
    
    return 0;
}
