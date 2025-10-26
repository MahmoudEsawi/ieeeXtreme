// =============================================================================
// 🏆 IEEE Xtreme Competition - Longest Balanced Subarray
// أطول مصفوفة فرعية متوازنة - الحل الأمثل للبرمجة التنافسية
// =============================================================================

#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;  // أطول طول تم العثور عليه
        
        // فحص كل مصفوفة فرعية محتملة
        // Check every possible subarray
        for (int i = 0; i < n; ++i) {
            unordered_set<int> evens, odds;  // مجموعات للأرقام الزوجية والفردية المميزة
            
            // توسيع المصفوفة الفرعية من الموضع i
            // Expand subarray starting from position i
            for (int j = i; j < n; ++j) {
                // تصنيف الرقم الحالي وإضافته للمجموعة المناسبة
                // Classify current number and add to appropriate set
                if (nums[j] % 2 == 0) {
                    evens.insert(nums[j]);  // رقم زوجي
                } else {
                    odds.insert(nums[j]);   // رقم فردي
                }
                
                // التحقق من التوازن: عدد الأرقام الزوجية المميزة = عدد الأرقام الفردية المميزة
                // Check balance: distinct even numbers = distinct odd numbers
                if (evens.size() == odds.size()) {
                    ans = max(ans, j - i + 1);  // تحديث أطول طول
                }
            }
        }
        
        return ans;  // إرجاع أطول طول
    }
};

// =============================================================================
// 🚀 شرح الحل باللهجة الأردنية
// =============================================================================

// هاد الحل هو الأسرع والأذكى لإيجاد أطول مصفوفة فرعية متوازنة. الفكرة الأساسية
// إنه بنفحص كل مصفوفة فرعية محتملة، وبعدين بنحسب عدد الأرقام الزوجية والفردية
// المميزة في كل مصفوفة فرعية.
// 
// الخوارزمية:
// 1. بنفحص كل مصفوفة فرعية محتملة (من i إلى j)
// 2. بنستخدم مجموعتين (sets) لحفظ الأرقام الزوجية والفردية المميزة
// 3. بنضيف كل رقم للمجموعة المناسبة (زوجي أو فردي)
// 4. بنفحص إذا عدد الأرقام الزوجية المميزة يساوي عدد الأرقام الفردية المميزة
// 5. إذا صح، بنحدث أطول طول
// 6. بنرجع أطول طول شفناه
// 
// مثال: nums = [2,5,4,3]
// - i=0, j=0: evens={2}, odds={}, not balanced
// - i=0, j=1: evens={2}, odds={5}, balanced! len=2
// - i=0, j=2: evens={2,4}, odds={5}, not balanced
// - i=0, j=3: evens={2,4}, odds={5,3}, balanced! len=4
// النتيجة: 4
// 
// المميزات:
// - تعقيد زمني: O(n²) حيث n طول المصفوفة
// - تعقيد مكاني: O(n) للمجموعات
// - فحص شامل لجميع المصفوفات الفرعية
// - معالجة جميع الحالات بكفاءة
// - مثالي للمسابقات البرمجية

// =============================================================================
// 🎯 تحليل الأداء
// =============================================================================

// Time Complexity: O(n²) - تعقيد زمني تربيعي (فحص كل مصفوفة فرعية)
// Space Complexity: O(n) - تعقيد مكاني خطي للمجموعات
// Algorithm: Brute Force with Sets - قوة غاشمة مع مجموعات
// Best for: Competitive Programming - مثالي للبرمجة التنافسية

// =============================================================================
// 🏆 أمثلة على الاستخدام
// =============================================================================

// Example 1: nums = [2,5,4,3]
// Output: 4
// Explanation: [2,5,4,3] has 2 distinct even numbers [2,4] and 2 distinct odd numbers [5,3]
// 
// Example 2: nums = [3,2,2,5,4]
// Output: 5
// Explanation: [3,2,2,5,4] has 2 distinct even numbers [2,4] and 2 distinct odd numbers [3,5]
// 
// Example 3: nums = [1,2,3,2]
// Output: 3
// Explanation: [2,3,2] has 1 distinct even number [2] and 1 distinct odd number [3]
// 
// Edge Cases:
// - Single element: returns 0 (cannot be balanced)
// - All even numbers: returns 0 (no odd numbers)
// - All odd numbers: returns 0 (no even numbers)
// - Alternating pattern: works correctly

// =============================================================================
// 🚀 READY TO COPY PASTE - NO COMMENTS
// =============================================================================

#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            unordered_set<int> evens, odds;
            
            for (int j = i; j < n; ++j) {
                if (nums[j] % 2 == 0) {
                    evens.insert(nums[j]);
                } else {
                    odds.insert(nums[j]);
                }
                
                if (evens.size() == odds.size()) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        
        return ans;
    }
};
