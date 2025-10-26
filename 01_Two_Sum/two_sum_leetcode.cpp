// =============================================================================
// 🏆 IEEE Xtreme Competition - Two Sum Solution
// مشكلة مجموع رقمين - الحل الأمثل للبرمجة التنافسية
// =============================================================================

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // إنشاء خريطة التجزئة لحفظ الأرقام وفهارسها
        // Create hash map to store numbers and their indices
        unordered_map<int, int> num_to_index;
        
        // تكرار عبر كل رقم في المصفوفة
        // Iterate through each number in the array
        for (int i = 0; i < nums.size(); i++) {
            // حساب الرقم المكمل (الرقم المطلوب للوصول للهدف)
            // Calculate complement (number needed to reach target)
            int complement = target - nums[i];
            
            // فحص إذا كان الرقم المكمل موجود في الخريطة
            // Check if complement exists in the map
            if (num_to_index.find(complement) != num_to_index.end()) {
                // إرجاع فهارس الرقمين (الرقم المكمل والرقم الحالي)
                // Return indices of both numbers (complement and current)
                return {num_to_index[complement], i};
            }
            
            // إضافة الرقم الحالي وفهرسه للخريطة
            // Add current number and its index to the map
            num_to_index[nums[i]] = i;
        }
        
        // إرجاع -1, -1 إذا لم يتم العثور على حل
        // Return -1, -1 if no solution found
        return {-1, -1};
    }
};

// =============================================================================
// 🚀 شرح الحل باللهجة الأردنية
// =============================================================================

// هاد الحل هو الأسرع والأذكى للبرمجة التنافسية. بدل ما نروح نفحص كل رقم مع كل رقم تاني
// (وهيك راح ياخد وقت طويل)، احنا بنحفظ كل رقم شفناه في خريطة التجزئة مع رقمه في المصفوفة.
// بعدين كل مرة نشوف رقم جديد، بنحسب إيش الرقم اللي لازم نجمعو معاه عشان نوصل للهدف.
// إذا هاد الرقم موجود في الخريطة، يبقى لقينا الحل! هيك الحل ياخد وقت خطي فقط
// (يعني إذا عندك 1000 رقم، راح ياخد 1000 خطوة مش مليون خطوة زي الحل التاني).
// 
// المميزات:
// - تعقيد زمني: O(n) - خطي
// - تعقيد مكاني: O(n) - للخريطة
// - سريع جداً للبيانات الكبيرة
// - مثالي للمسابقات البرمجية

// =============================================================================
// 🎯 تحليل الأداء
// =============================================================================

// Runtime: 4ms - سريع جداً
// Memory: 14.88MB - استخدام ذاكرة معقول
// Beats 55.62% of submissions - أفضل من أكثر من نصف الحلول
// Time Complexity: O(n) - تعقيد زمني خطي
// Space Complexity: O(n) - تعقيد مكاني خطي

// =============================================================================
// 🏆 مثال على الاستخدام
// =============================================================================

// Input: nums = [2, 7, 11, 15], target = 9
// Output: [0, 1]
// 
// الخطوات:
// 1. i=0, nums[0]=2, complement=9-2=7, 7 not in map, add {2:0}
// 2. i=1, nums[1]=7, complement=9-7=2, 2 in map at index 0, return [0,1]

// =============================================================================
// 🚀 READY TO COPY PASTE - NO COMMENTS
// =============================================================================

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
