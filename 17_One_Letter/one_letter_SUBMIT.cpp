#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<char> minChars(n);
    
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        
        char minChar = word[0];
        for (char c : word) {
            if (c < minChar) {
                minChar = c;
            }
        }
        
        minChars[i] = minChar;
    }
    
    sort(minChars.begin(), minChars.end());
    
    for (char c : minChars) {
        cout << c;
    }
    cout << "\n";
    
    return 0;
}
