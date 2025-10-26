#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    unordered_map<string, int> freq;
    int maxCnt = 0;
    
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        
        sort(word.begin(), word.end());
        freq[word]++;
        maxCnt = max(maxCnt, freq[word]);
    }
    
    cout << maxCnt << endl;
    
    return 0;
}
