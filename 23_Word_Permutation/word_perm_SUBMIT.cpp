#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<pair<string, int>> words(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> words[i].first;
        words[i].second = i + 1;
    }
    
    // Sort by word to get original lexicographic order
    sort(words.begin(), words.end());
    
    // Now words[i].second tells us where the i-th sorted word is now
    for (int i = 0; i < n; ++i) {
        cout << words[i].second;
        if (i < n - 1) cout << " ";
    }
    cout << "\n";
    
    return 0;
}
