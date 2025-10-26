#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos[128] = {0};
        int leftPtr = 0, maxLen = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (pos[s[i]] > leftPtr) {
                leftPtr = pos[s[i]];
            }
            pos[s[i]] = i + 1;
            maxLen = max(maxLen, i - leftPtr + 1);
        }
        
        return maxLen;
    }
};
