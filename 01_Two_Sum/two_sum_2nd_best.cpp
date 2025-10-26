#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> nums_with_index;
        for (int i = 0; i < nums.size(); i++) {
            nums_with_index.push_back({nums[i], i});
        }
        
        sort(nums_with_index.begin(), nums_with_index.end());
        
        int left = 0, right = nums_with_index.size() - 1;
        
        while (left < right) {
            int sum = nums_with_index[left].first + nums_with_index[right].first;
            
            if (sum == target) {
                int idx1 = nums_with_index[left].second;
                int idx2 = nums_with_index[right].second;
                return {min(idx1, idx2), max(idx1, idx2)};
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
        
        return {-1, -1};
    }
};
