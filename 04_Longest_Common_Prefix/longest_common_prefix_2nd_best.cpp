#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];
        
        string prefix = strs[0];
        
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            while (j < prefix.length() && j < strs[i].length() && 
                   prefix[j] == strs[i][j]) {
                j++;
            }
            
            prefix = prefix.substr(0, j);
            
            if (prefix.empty()) break;
        }
        
        return prefix;
    }
};
