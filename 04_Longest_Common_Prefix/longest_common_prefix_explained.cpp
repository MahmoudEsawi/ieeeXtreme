// =============================================================================
// 🏆 IEEE Xtreme Competition - Longest Common Prefix Solution
// أطول بادئة مشتركة - الحل الأمثل للبرمجة التنافسية
// =============================================================================

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // التحقق من المصفوفة الفارغة
        // Check for empty array
        if (strs.empty()) return "";
        
        // إذا كان هناك سلسلة واحدة فقط، إرجاعها
        // If only one string, return it
        if (strs.size() == 1) return strs[0];
        
        // إيجاد أقصر طول سلسلة لتجنب المقارنات غير الضرورية
        // Find minimum length to avoid unnecessary comparisons
        int min_len = strs[0].length();
        for (int i = 1; i < strs.size(); i++) {
            int len = strs[i].length();
            if (len < min_len) min_len = len;
        }
        
        // إنهاء مبكر إذا كانت أي سلسلة فارغة
        // Early termination if any string is empty
        if (min_len == 0) return "";
        
        // مقارنة حرف بحرف مع إنهاء مبكر
        // Compare character by character with early termination
        for (int i = 0; i < min_len; i++) {
            char c = strs[0][i];  // الحرف المرجعي من السلسلة الأولى
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != c) {  // إذا اختلف الحرف
                    return strs[0].substr(0, i);  // إرجاع البادئة المشتركة حتى الآن
                }
            }
        }
        
        // إرجاع البادئة المشتركة الكاملة
        // Return complete common prefix
        return strs[0].substr(0, min_len);
    }
};

// =============================================================================
// 🚀 شرح الحل باللهجة الأردنية
// =============================================================================

// هاد الحل هو الأسرع والأذكى لإيجاد أطول بادئة مشتركة. الفكرة الأساسية إنه
// بناخد أول سلسلة كمرجع وبنقارن كل حرف مع نفس الموضع في باقي السلاسل.
// 
// الخوارزمية:
// 1. بنلاقي أقصر سلسلة عشان ما نقارنش حروف مش موجودة
// 2. بنقارن حرف بحرف من أول حرف لأقصر سلسلة
// 3. إذا لقينا حرف مختلف، بنرجع البادئة المشتركة حتى الآن
// 4. إذا كل الحروف متطابقة، بنرجع البادئة الكاملة
// 
// مثال: ["flower", "flow", "flight"]
// - min_len = 4 (أقصر سلسلة "flow")
// - i=0: 'f' == 'f' == 'f' ✅
// - i=1: 'l' == 'l' == 'l' ✅  
// - i=2: 'o' == 'o' == 'i' ❌
// - النتيجة: "fl"
// 
// المميزات:
// - تعقيد زمني: O(S) حيث S هو مجموع أحرف كل السلاسل
// - تعقيد مكاني: O(1) - لا نحتاج مساحة إضافية
// - إنهاء مبكر - نتوقف عند أول اختلاف
// - مثالي للمسابقات البرمجية

// =============================================================================
// 🎯 تحليل الأداء
// =============================================================================

// Time Complexity: O(S) - حيث S هو مجموع أحرف كل السلاسل في المصفوفة
// Space Complexity: O(1) - لا نحتاج مساحة إضافية
// Algorithm: Character-by-character comparison - مقارنة حرف بحرف
// Best for: Competitive Programming - مثالي للبرمجة التنافسية

// =============================================================================
// 🏆 أمثلة على الاستخدام
// =============================================================================

// Example 1: strs = ["flower","flow","flight"]
// Output: "fl"
// Explanation: Common prefix is "fl"
// 
// Example 2: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: No common prefix among the strings
// 
// Example 3: strs = ["interspecies","interstellar","interstate"]
// Output: "inters"
// Explanation: Common prefix is "inters"
// 
// Edge Cases:
// - Empty array: return ""
// - Single string: return the string itself
// - Empty strings: return ""
// - No common prefix: return ""

// =============================================================================
// 🚀 READY TO COPY PASTE - NO COMMENTS
// =============================================================================

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];
        
        int min_len = strs[0].length();
        for (int i = 1; i < strs.size(); i++) {
            int len = strs[i].length();
            if (len < min_len) min_len = len;
        }
        
        if (min_len == 0) return "";
        
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
