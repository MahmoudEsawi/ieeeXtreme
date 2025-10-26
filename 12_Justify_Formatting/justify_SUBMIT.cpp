#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> justifyText(vector<string>& words, int K) {
    vector<string> result;
    int n = words.size();
    int i = 0;
    
    while (i < n) {
        int lineLen = words[i].length();
        int j = i + 1;
        
        while (j < n && lineLen + 1 + words[j].length() <= K) {
            lineLen += 1 + words[j].length();
            j++;
        }
        
        string line;
        int numWords = j - i;
        
        if (j == n || numWords == 1) {
            for (int k = i; k < j; ++k) {
                line += words[k];
                if (k < j - 1) line += " ";
            }
            while (line.length() < K) line += " ";
        } else {
            int totalSpaces = K - (lineLen - (numWords - 1));
            int gaps = numWords - 1;
            int spacesPerGap = totalSpaces / gaps;
            int extraSpaces = totalSpaces % gaps;
            
            for (int k = i; k < j; ++k) {
                line += words[k];
                if (k < j - 1) {
                    int spaces = spacesPerGap + (k - i < extraSpaces ? 1 : 0);
                    line += string(spaces, ' ');
                }
            }
        }
        
        result.push_back(line);
        i = j;
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }
    
    vector<string> lines = justifyText(words, k);
    
    for (const string& line : lines) {
        cout << line << endl;
    }
    
    return 0;
}
