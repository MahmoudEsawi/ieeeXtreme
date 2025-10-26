#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // Use first string as reference
        string result = strs[0];
        
        for (int i = 1; i < strs.size(); i++) {
            // Find common prefix between result and current string
            int j = 0;
            while (j < result.length() && j < strs[i].length() && result[j] == strs[i][j]) {
                j++;
            }
            result = result.substr(0, j);
            
            // Early termination if no common prefix
            if (result.empty()) return "";
        }
        
        return result;
    }
};
