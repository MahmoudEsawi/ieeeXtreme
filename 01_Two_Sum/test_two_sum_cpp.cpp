#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_to_index;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (num_to_index.find(complement) != num_to_index.end()) {
                return {num_to_index[complement], i};
            }
            num_to_index[nums[i]] = i;
        }
        
        return {-1, -1};
    }
};

void test_solution() {
    Solution sol;
    
    cout << "🏆 Two Sum Problem - C++ Solution Test" << endl;
    cout << "مشكلة مجموع رقمين - اختبار الحل" << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    // Test Case 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = sol.twoSum(nums1, target1);
    
    cout << "📝 Test Case 1:" << endl;
    cout << "   Input: nums = [2, 7, 11, 15], target = 9" << endl;
    cout << "   Expected: [0, 1]" << endl;
    cout << "   Result: [" << result1[0] << ", " << result1[1] << "] ";
    cout << ((result1[0] == 0 && result1[1] == 1) ? "✅" : "❌") << endl;
    cout << endl;
    
    // Test Case 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = sol.twoSum(nums2, target2);
    
    cout << "📝 Test Case 2:" << endl;
    cout << "   Input: nums = [3, 2, 4], target = 6" << endl;
    cout << "   Expected: [1, 2]" << endl;
    cout << "   Result: [" << result2[0] << ", " << result2[1] << "] ";
    cout << ((result2[0] == 1 && result2[1] == 2) ? "✅" : "❌") << endl;
    cout << endl;
    
    // Test Case 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = sol.twoSum(nums3, target3);
    
    cout << "📝 Test Case 3:" << endl;
    cout << "   Input: nums = [3, 3], target = 6" << endl;
    cout << "   Expected: [0, 1]" << endl;
    cout << "   Result: [" << result3[0] << ", " << result3[1] << "] ";
    cout << ((result3[0] == 0 && result3[1] == 1) ? "✅" : "❌") << endl;
    cout << endl;
    
    cout << "🎯 Algorithm Analysis:" << endl;
    cout << "تحليل الخوارزمية:" << endl;
    cout << "===================" << endl;
    cout << "Time Complexity: O(n) - تعقيد زمني خطي" << endl;
    cout << "Space Complexity: O(n) - تعقيد مكاني خطي" << endl;
    cout << "Algorithm: Hash Map - خريطة التجزئة" << endl;
    cout << "Best for: Competitive Programming - مثالي للبرمجة التنافسية" << endl;
    cout << endl;
    cout << "🏁 Recommendation: Use this solution for IEEE Xtreme competition!" << endl;
    cout << "🏁 التوصية: استخدم هذا الحل لمسابقة IEEE Xtreme!" << endl;
}

int main() {
    test_solution();
    return 0;
}
