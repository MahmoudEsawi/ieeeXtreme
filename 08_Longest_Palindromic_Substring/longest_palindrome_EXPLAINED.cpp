// =============================================================================
// 🏆 IEEE Xtreme Competition - Longest Palindromic Substring
// أطول سلسلة فرعية متناظرة - الحل الأمثل للبرمجة التنافسية
// =============================================================================

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        // معالجة الحالات البسيطة
        // Handle simple cases
        if (n < 2) return s;
        
        int start = 0, maxLen = 1;  // بداية وطول أطول سلسلة متناظرة
        
        // فحص كل حرف كمركز محتمل للسلسلة المتناظرة
        // Check each character as potential center of palindrome
        for (int i = 0; i < n; ++i) {
            // فحص السلسلة المتناظرة ذات المركز الفردي (مثل "aba")
            // Check palindrome with odd center (like "aba")
            int len1 = expandAroundCenter(s, i, i);
            // فحص السلسلة المتناظرة ذات المركز الزوجي (مثل "abba")
            // Check palindrome with even center (like "abba")
            int len2 = expandAroundCenter(s, i, i + 1);
            // أخذ أطول طول
            // Take maximum length
            int len = max(len1, len2);
            
            // تحديث أطول سلسلة متناظرة إذا لزم الأمر
            // Update longest palindrome if necessary
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;  // حساب بداية السلسلة
            }
        }
        
        return s.substr(start, maxLen);  // إرجاع أطول سلسلة متناظرة
    }
    
private:
    // دالة مساعدة لتوسيع السلسلة المتناظرة من المركز
    // Helper function to expand palindrome from center
    int expandAroundCenter(string& s, int left, int right) {
        // التوسيع طالما الأحرف متطابقة والحدود صحيحة
        // Expand while characters match and boundaries are valid
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;   // التحرك إلى اليسار
            right++;  // التحرك إلى اليمين
        }
        // إرجاع طول السلسلة المتناظرة
        // Return length of palindrome
        return right - left - 1;
    }
};

// =============================================================================
// 🚀 شرح الحل باللهجة الأردنية
// =============================================================================

// هاد الحل هو الأسرع والأذكى لإيجاد أطول سلسلة فرعية متناظرة. الفكرة الأساسية
// إنه بنفحص كل حرف في السلسلة كمركز محتمل للسلسلة المتناظرة، وبعدين بنوسع
// من المركز عشان نلاقي أطول سلسلة متناظرة ممكنة.
// 
// الخوارزمية:
// 1. بنفحص كل حرف كمركز للسلسلة المتناظرة
// 2. بنوسع من المركز في اتجاهين (يسار ويمين)
// 3. بنفحص نوعين من المراكز: فردي (aba) وزوجي (abba)
// 4. بنحفظ أطول سلسلة متناظرة شفناها
// 5. بنرجع السلسلة المتناظرة الأطول
// 
// مثال: "babad"
// - i=0: 'b' -> expand -> "b" (len=1)
// - i=1: 'a' -> expand -> "bab" (len=3) ✓
// - i=2: 'b' -> expand -> "aba" (len=3) ✓
// - i=3: 'a' -> expand -> "a" (len=1)
// - i=4: 'd' -> expand -> "d" (len=1)
// النتيجة: "bab" أو "aba" (كلاهما صحيح)
// 
// المميزات:
// - تعقيد زمني: O(n²) حيث n طول السلسلة
// - تعقيد مكاني: O(1) - لا نستخدم مساحة إضافية
// - توسيع من المركز (أسرع من الحلول الأخرى)
// - معالجة جميع الحالات بكفاءة
// - مثالي للمسابقات البرمجية

// =============================================================================
// 🎯 تحليل الأداء
// =============================================================================

// Time Complexity: O(n²) - تعقيد زمني تربيعي (فحص كل مركز وتوسيع)
// Space Complexity: O(1) - تعقيد مكاني ثابت
// Algorithm: Expand Around Centers - توسيع من المراكز
// Best for: Competitive Programming - مثالي للبرمجة التنافسية

// =============================================================================
// 🏆 أمثلة على الاستخدام
// =============================================================================

// Example 1: s = "babad"
// Output: "bab" or "aba"
// Explanation: Both "bab" and "aba" are valid longest palindromes
// 
// Example 2: s = "cbbd"
// Output: "bb"
// Explanation: The longest palindrome is "bb"
// 
// Edge Cases:
// - Single character: returns the character itself
// - All same characters: returns the entire string
// - No palindrome: returns first character
// - Empty string: handled by n < 2 check

// =============================================================================
// 🚀 READY TO COPY PASTE - NO COMMENTS
// =============================================================================

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2) return s;
        
        int start = 0, maxLen = 1;
        
        for (int i = 0; i < n; ++i) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);
            
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLen);
    }
    
private:
    int expandAroundCenter(string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};
