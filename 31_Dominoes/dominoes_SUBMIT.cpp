#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> coords(n);
    for (int i = 0; i < n; ++i) {
        cin >> coords[i];
    }
    
    int maxLen = 0;
    
    // Try starting from each existing domino
    for (int i = 0; i < n; ++i) {
        int remaining = k;
        int len = 1;
        int pos = coords[i];
        
        // Extend forward
        for (int j = i + 1; j < n; ++j) {
            int gap = coords[j] - pos - 1;
            
            if (gap <= remaining) {
                remaining -= gap;
                len += gap + 1;
                pos = coords[j];
            } else {
                len += remaining;
                remaining = 0;
                break;
            }
        }
        
        // Add remaining dominoes at the end
        if (remaining > 0) {
            len += remaining;
        }
        
        maxLen = max(maxLen, len);
    }
    
    // Try starting from a new position
    maxLen = max(maxLen, k);
    
    cout << maxLen << "\n";
    
    return 0;
}
