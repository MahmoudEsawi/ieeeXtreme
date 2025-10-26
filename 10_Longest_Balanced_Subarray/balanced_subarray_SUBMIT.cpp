#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        for (int i = 0; i < n && n - i > ans; ++i) {
            unordered_set<int> evens, odds;
            
            for (int j = i; j < n; ++j) {
                if (nums[j] & 1) {
                    odds.insert(nums[j]);
                } else {
                    evens.insert(nums[j]);
                }
                
                if (evens.size() == odds.size() && evens.size() > 0) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        
        return ans;
    }
};
