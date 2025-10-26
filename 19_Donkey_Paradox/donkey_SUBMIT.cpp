#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    
    int cnt = 0;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // Skip haystack positions
            if ((i == r1 && j == c1) || (i == r2 && j == c2)) {
                continue;
            }
            
            // Calculate Manhattan distance to both haystacks
            int dist1 = abs(i - r1) + abs(j - c1);
            int dist2 = abs(i - r2) + abs(j - c2);
            
            // Count if distances are equal
            if (dist1 == dist2) {
                cnt++;
            }
        }
    }
    
    cout << cnt << "\n";
    
    return 0;
}
