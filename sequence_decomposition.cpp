#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        
        int n = s.length();
        vector<bool> used(n, false);
        vector<vector<int>> result;
        
        while (true) {
            vector<int> pattern = {1, 1, 2, 0, 1, 2};
            vector<int> indices;
            int pattern_idx = 0;
            
            for (int i = 0; i < n && pattern_idx < 6; i++) {
                if (!used[i] && s[i] - '0' == pattern[pattern_idx]) {
                    indices.push_back(i + 1);
                    used[i] = true;
                    pattern_idx++;
                }
            }
            
            if (pattern_idx == 6) {
                result.push_back(indices);
            } else {
                break;
            }
        }
        
        for (const auto& indices : result) {
            for (int i = 0; i < 6; i++) {
                if (i > 0) cout << " ";
                cout << indices[i];
            }
            cout << "\n";
        }
    }
    
    return 0;
}
