// =============================================================================
// 🏆 IEEE Xtreme Competition - Longest Substring Without Repeating Characters
// أطول سلسلة فرعية بدون تكرار - الحل الأمثل للبرمجة التنافسية
// =============================================================================

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // مصفوفة ثابتة لتخزين آخر موضع لكل حرف (أسرع من unordered_map)
        // Fixed array to store last position of each character (faster than unordered_map)
        int charIndex[128] = {0};  // 128 حرف ASCII
        int left = 0;  // مؤشر البداية للنافذة المنزلقة
        int maxLen = 0;  // أقصى طول تم العثور عليه
        
        // استخدام تقنية النافذة المنزلقة المحسنة (Ultra-Fast Sliding Window)
        // Using ultra-fast sliding window technique
        for (int right = 0; right < s.length(); right++) {
            // إذا كان الحرف موجود مسبقاً وكان موضعه داخل النافذة الحالية
            // If character exists and its position is within current window
            if (charIndex[s[right]] > left) {
                // تحريك مؤشر البداية إلى موضع الحرف المكرر
                // Move left pointer to position of repeated character
                left = charIndex[s[right]];
            }
            
            // تحديث موضع الحرف الحالي (موضع + 1 لتجنب الصفر)
            // Update position of current character (position + 1 to avoid zero)
            charIndex[s[right]] = right + 1;
            
            // تحديث أقصى طول
            // Update maximum length
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;  // إرجاع أقصى طول
    }
};

// =============================================================================
// 🚀 شرح الحل باللهجة الأردنية
// =============================================================================

// هاد الحل هو الأسرع والأذكى لإيجاد أطول سلسلة فرعية بدون تكرار. الفكرة الأساسية
// إنه بنستخدم تقنية "النافذة المنزلقة" (Sliding Window) مع خريطة لحفظ آخر موضع لكل حرف.
// 
// الخوارزمية المحسنة:
// 1. بنحفظ آخر موضع لكل حرف في مصفوفة ثابتة (أسرع من خريطة)
// 2. بنستخدم مؤشرين: left (بداية النافذة) و right (نهاية النافذة)
// 3. كل مرة نشوف حرف مكرر، بنحرك left إلى موضع الحرف المكرر مباشرة
// 4. بنحفظ الموضع + 1 عشان نتجنب الصفر
// 5. بنحسب طول النافذة الحالية ونقارنها بالأقصى
// 6. نكمل حتى نخلص كل الحروف
// 
// مثال: "abcabcbb"
// - a: charIndex['a'] = 0, window = "a", length = 1
// - b: charIndex['b'] = 1, window = "ab", length = 2
// - c: charIndex['c'] = 2, window = "abc", length = 3
// - a: موجود في الموضع 0, left = 1, window = "bca", length = 3
// - b: موجود في الموضع 1, left = 2, window = "cab", length = 3
// - c: موجود في الموضع 2, left = 3, window = "abc", length = 3
// - b: موجود في الموضع 4, left = 5, window = "cb", length = 2
// - b: موجود في الموضع 5, left = 6, window = "b", length = 1
// النتيجة: 3
// 
// المميزات:
// - تعقيد زمني: O(n) حيث n طول السلسلة
// - تعقيد مكاني: O(1) - مصفوفة ثابتة 128 عنصر
// - مصفوفة ثابتة بدل خريطة (أسرع بكثير)
// - نافذة منزلقة محسنة (أسرع من الحلول الأخرى)
// - معالجة جميع الحالات بكفاءة
// - مثالي للمسابقات البرمجية

// =============================================================================
// 🎯 تحليل الأداء
// =============================================================================

// Time Complexity: O(n) - تعقيد زمني خطي (تمريرة واحدة فقط)
// Space Complexity: O(1) - مصفوفة ثابتة 128 عنصر
// Algorithm: Ultra-Fast Sliding Window with Fixed Array - نافذة منزلقة فائقة السرعة مع مصفوفة ثابتة
// Best for: Competitive Programming - مثالي للبرمجة التنافسية

// =============================================================================
// 🏆 أمثلة على الاستخدام
// =============================================================================

// Example 1: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3
// 
// Example 2: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1
// 
// Example 3: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3
// 
// Edge Cases:
// - Empty string: returns 0
// - Single character: returns 1
// - All same characters: returns 1
// - No repeating characters: returns string length

// =============================================================================
// 🚀 READY TO COPY PASTE - NO COMMENTS
// =============================================================================

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int charIndex[128] = {0};
        int left = 0;
        int maxLen = 0;
        
        for (int right = 0; right < s.length(); right++) {
            if (charIndex[s[right]] > left) {
                left = charIndex[s[right]];
            }
            charIndex[s[right]] = right + 1;
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};
