#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];
        
        // Find minimum length - avoid repeated length() calls
        int min_len = strs[0].length();
        for (int i = 1; i < strs.size(); i++) {
            int len = strs[i].length();
            if (len < min_len) min_len = len;
        }
        
        // Early termination if any string is empty
        if (min_len == 0) return "";
        
        // Compare character by character with early termination
        for (int i = 0; i < min_len; i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0].substr(0, min_len);
    }
};
