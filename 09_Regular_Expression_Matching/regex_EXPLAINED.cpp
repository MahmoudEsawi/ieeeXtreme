// =============================================================================
// 🏆 IEEE Xtreme Competition - Regular Expression Matching
// مطابقة التعبيرات النمطية - الحل الأمثل للبرمجة التنافسية
// =============================================================================

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        // مصفوفة ثنائية الأبعاد لحفظ النتائج الجزئية
        // 2D array to store partial results
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // الحالة الأساسية: سلسلة فارغة تطابق نمط فارغ
        // Base case: empty string matches empty pattern
        dp[0][0] = true;
        
        // معالجة الحالة الخاصة: سلسلة فارغة مع نمط يحتوي على '*'
        // Handle special case: empty string with pattern containing '*'
        for (int j = 2; j <= n; j += 2) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];  // تجاهل الحرف والنجمة
            }
        }
        
        // ملء المصفوفة باستخدام البرمجة الديناميكية
        // Fill the array using dynamic programming
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    // حالة النجمة: يمكن تجاهلها أو استخدامها
                    // Star case: can be ignored or used
                    dp[i][j] = dp[i][j - 2] ||  // تجاهل النجمة والحرف السابق
                              (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    // حالة الحرف العادي أو النقطة
                    // Normal character or dot case
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        
        return dp[m][n];  // إرجاع النتيجة النهائية
    }
};

// =============================================================================
// 🚀 شرح الحل باللهجة الأردنية
// =============================================================================

// هاد الحل هو الأسرع والأذكى لمطابقة التعبيرات النمطية. الفكرة الأساسية
// إنه بنستخدم البرمجة الديناميكية (Dynamic Programming) لحفظ النتائج الجزئية
// وتجنب إعادة الحساب.
// 
// الخوارزمية:
// 1. بنعمل مصفوفة ثنائية الأبعاد dp[i][j] عشان نحفظ إذا كان الجزء الأول
//    من السلسلة (طول i) يطابق الجزء الأول من النمط (طول j)
// 2. بنبدأ بالحالة الأساسية: سلسلة فارغة تطابق نمط فارغ
// 3. بنعالج الحالة الخاصة: سلسلة فارغة مع نمط يحتوي على '*'
// 4. بنملأ المصفوفة باستخدام القواعد:
//    - إذا كان الحرف '*'، يمكن تجاهله أو استخدامه
//    - إذا كان حرف عادي أو '.'، بنقارن الحرفين
// 5. النتيجة النهائية في dp[m][n]
// 
// مثال: s = "aa", p = "a*"
// - dp[0][0] = true (فارغ يطابق فارغ)
// - dp[0][2] = true (فارغ يطابق "a*")
// - dp[1][1] = true ("a" يطابق "a")
// - dp[1][2] = true ("a" يطابق "a*")
// - dp[2][2] = true ("aa" يطابق "a*")
// النتيجة: true
// 
// المميزات:
// - تعقيد زمني: O(m×n) حيث m,n أطوال السلسلة والنمط
// - تعقيد مكاني: O(m×n) للمصفوفة الثنائية الأبعاد
// - برمجة ديناميكية محسنة (تجنب إعادة الحساب)
// - معالجة جميع الحالات بكفاءة
// - مثالي للمسابقات البرمجية

// =============================================================================
// 🎯 تحليل الأداء
// =============================================================================

// Time Complexity: O(m×n) - تعقيد زمني تربيعي (ملء مصفوفة m×n)
// Space Complexity: O(m×n) - تعقيد مكاني تربيعي للمصفوفة
// Algorithm: Dynamic Programming - برمجة ديناميكية
// Best for: Competitive Programming - مثالي للبرمجة التنافسية

// =============================================================================
// 🏆 أمثلة على الاستخدام
// =============================================================================

// Example 1: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa"
// 
// Example 2: s = "aa", p = "a*"
// Output: true
// Explanation: '*' means zero or more of the preceding element, 'a'
// 
// Example 3: s = "ab", p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)"
// 
// Edge Cases:
// - Empty string with empty pattern: true
// - Empty string with pattern containing '*': handled correctly
// - Single character matching: works perfectly
// - Complex patterns with multiple '*': handled efficiently

// =============================================================================
// 🚀 READY TO COPY PASTE - NO COMMENTS
// =============================================================================

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        dp[0][0] = true;
        
        for (int j = 2; j <= n; j += 2) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || 
                              (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        
        return dp[m][n];
    }
};
