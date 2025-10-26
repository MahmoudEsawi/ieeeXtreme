// =============================================================================
// 🏆 IEEE Xtreme Competition - Median of Two Sorted Arrays
// متوسط مصفوفتين مرتبتين - الحل الأمثل للبرمجة التنافسية
// =============================================================================

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        // تأكد من أن المصفوفة الأولى أصغر (لتحسين الأداء)
        // Ensure first array is smaller (for performance optimization)
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        
        int left = 0, right = m;
        // استخدام البحث الثنائي لإيجاد نقطة القطع المثلى
        // Use binary search to find optimal cut point
        while (left <= right) {
            int cut1 = (left + right) / 2;  // نقطة القطع في المصفوفة الأولى
            int cut2 = (m + n + 1) / 2 - cut1;  // نقطة القطع في المصفوفة الثانية
            
            // الحصول على العناصر المجاورة لنقاط القطع
            // Get elements adjacent to cut points
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int right1 = cut1 == m ? INT_MAX : nums1[cut1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            int right2 = cut2 == n ? INT_MAX : nums2[cut2];
            
            // التحقق من صحة التقسيم
            // Check if partition is valid
            if (left1 <= right2 && left2 <= right1) {
                // حساب المتوسط بناءً على عدد العناصر
                // Calculate median based on number of elements
                if ((m + n) % 2 == 0) {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                } else {
                    return max(left1, left2);
                }
            } else if (left1 > right2) {
                // تحريك نقطة القطع إلى اليسار
                // Move cut point to the left
                right = cut1 - 1;
            } else {
                // تحريك نقطة القطع إلى اليمين
                // Move cut point to the right
                left = cut1 + 1;
            }
        }
        return 0.0;  // قيمة افتراضية (لن تصل إليها أبداً)
    }
};

// =============================================================================
// 🚀 شرح الحل باللهجة الأردنية
// =============================================================================

// هاد الحل هو الأسرع والأذكى لإيجاد متوسط مصفوفتين مرتبتين. الفكرة الأساسية
// إنه بنستخدم البحث الثنائي (Binary Search) عشان نلاقي نقطة القطع المثلى
// اللي بتقسم المصفوفتين بطريقة صحيحة.
// 
// الخوارزمية:
// 1. بنتأكد إن المصفوفة الأولى أصغر من التانية (لتحسين الأداء)
// 2. بنستخدم البحث الثنائي على المصفوفة الأصغر
// 3. بنحسب نقطة القطع في المصفوفة التانية بناءً على الأولى
// 4. بنفحص إذا التقسيم صحيح (العناصر اليسرى أصغر من اليمنى)
// 5. إذا صح، بنحسب المتوسط
// 6. إذا مش صح، بنحرك نقطة القطع
// 
// مثال: nums1 = [1,3], nums2 = [2]
// - m=2, n=1, total=3 (فردي)
// - cut1=1, cut2=1
// - left1=1, right1=3, left2=2, right2=INT_MAX
// - 1 <= INT_MAX ✓, 2 <= 3 ✓
// - المتوسط = max(1,2) = 2
// 
// المميزات:
// - تعقيد زمني: O(log(min(m,n))) - أسرع من O(log(m+n))
// - تعقيد مكاني: O(1) - لا نستخدم مساحة إضافية
// - بحث ثنائي محسن (على المصفوفة الأصغر)
// - معالجة جميع الحالات بكفاءة
// - مثالي للمسابقات البرمجية

// =============================================================================
// 🎯 تحليل الأداء
// =============================================================================

// Time Complexity: O(log(min(m,n))) - تعقيد زمني لوغاريتمي محسن
// Space Complexity: O(1) - تعقيد مكاني ثابت
// Algorithm: Binary Search on Smaller Array - بحث ثنائي على المصفوفة الأصغر
// Best for: Competitive Programming - مثالي للبرمجة التنافسية

// =============================================================================
// 🏆 أمثلة على الاستخدام
// =============================================================================

// Example 1: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2
// 
// Example 2: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5
// 
// Edge Cases:
// - One empty array: handled correctly
// - Both arrays same size: works perfectly
// - All elements in one array: handled efficiently
// - Duplicate elements: works correctly

// =============================================================================
// 🚀 READY TO COPY PASTE - NO COMMENTS
// =============================================================================

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        
        int left = 0, right = m;
        while (left <= right) {
            int cut1 = (left + right) / 2;
            int cut2 = (m + n + 1) / 2 - cut1;
            
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int right1 = cut1 == m ? INT_MAX : nums1[cut1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            int right2 = cut2 == n ? INT_MAX : nums2[cut2];
            
            if (left1 <= right2 && left2 <= right1) {
                if ((m + n) % 2 == 0) {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                } else {
                    return max(left1, left2);
                }
            } else if (left1 > right2) {
                right = cut1 - 1;
            } else {
                left = cut1 + 1;
            }
        }
        return 0.0;
    }
};
