// =============================================================================
// 🏆 IEEE Xtreme Competition - Roman to Integer Solution
// تحويل الأرقام الرومانية إلى أرقام عربية - الحل الأمثل للبرمجة التنافسية
// =============================================================================

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // إنشاء خريطة التجزئة لحفظ قيم الرموز الرومانية
        // Create hash map to store Roman symbol values
        unordered_map<char, int> roman_values = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int result = 0;  // متغير لحفظ النتيجة النهائية
        int prev_value = 0;  // متغير لحفظ قيمة الرمز السابق
        
        // تكرار من اليمين إلى اليسار (من آخر رمز إلى أول رمز)
        // Iterate from right to left (from last symbol to first symbol)
        for (int i = s.length() - 1; i >= 0; i--) {
            int current_value = roman_values[s[i]];  // قيمة الرمز الحالي
            
            // إذا كانت قيمة الرمز الحالي أقل من الرمز السابق، نطرحها
            // If current value is less than previous value, subtract it
            if (current_value < prev_value) {
                result -= current_value;
            } else {
                // وإلا نضيفها للنتيجة
                // Otherwise, add it to the result
                result += current_value;
            }
            
            prev_value = current_value;  // تحديث قيمة الرمز السابق
        }
        
        return result;  // إرجاع النتيجة النهائية
    }
};

// =============================================================================
// 🚀 شرح الحل باللهجة الأردنية
// =============================================================================

// هاد الحل هو الأذكى والأسرع لتحويل الأرقام الرومانية. الفكرة الأساسية إنه
// بنروح من اليمين لليسار (من آخر حرف لأول حرف) ونقارن كل رمز مع اللي بعده.
// 
// القاعدة الأساسية:
// - إذا كان الرمز الحالي أقل من اللي بعده، معناه إنه حالة طرح (مثل IV = 4)
// - إذا كان الرمز الحالي أكبر أو يساوي اللي بعده، معناه إنه حالة جمع عادي
// 
// مثال: MCMXCIV = 1994
// - نبدأ من اليمين: V = 5, I = 1, C = 100, X = 10, M = 1000, C = 100, M = 1000
// - V: 5 (أول رمز، نضيفه) → result = 5
// - I: 1 < 5 (أقل من السابق، نطرحه) → result = 5 - 1 = 4
// - C: 100 > 1 (أكبر من السابق، نضيفه) → result = 4 + 100 = 104
// - X: 10 < 100 (أقل من السابق، نطرحه) → result = 104 - 10 = 94
// - M: 1000 > 10 (أكبر من السابق، نضيفه) → result = 94 + 1000 = 1094
// - C: 100 < 1000 (أقل من السابق، نطرحه) → result = 1094 - 100 = 994
// - M: 1000 > 100 (أكبر من السابق، نضيفه) → result = 994 + 1000 = 1994
// 
// المميزات:
// - تعقيد زمني: O(n) - خطي
// - تعقيد مكاني: O(1) - ثابت (الخريطة صغيرة)
// - سريع جداً للبيانات الكبيرة
// - مثالي للمسابقات البرمجية

// =============================================================================
// 🎯 تحليل الأداء
// =============================================================================

// Time Complexity: O(n) - تعقيد زمني خطي حيث n هو طول السلسلة
// Space Complexity: O(1) - تعقيد مكاني ثابت (خريطة صغيرة)
// Algorithm: Right-to-left traversal with comparison - اجتياز من اليمين لليسار مع المقارنة
// Best for: Competitive Programming - مثالي للبرمجة التنافسية

// =============================================================================
// 🏆 أمثلة على الاستخدام
// =============================================================================

// Example 1: s = "III"
// Output: 3
// Explanation: I + I + I = 1 + 1 + 1 = 3
// 
// Example 2: s = "LVIII"
// Output: 58
// Explanation: L + V + I + I + I = 50 + 5 + 1 + 1 + 1 = 58
// 
// Example 3: s = "MCMXCIV"
// Output: 1994
// Explanation: M + CM + XC + IV = 1000 + 900 + 90 + 4 = 1994
// 
// Special Cases:
// - IV = 4 (5 - 1)
// - IX = 9 (10 - 1)
// - XL = 40 (50 - 10)
// - XC = 90 (100 - 10)
// - CD = 400 (500 - 100)
// - CM = 900 (1000 - 100)

// =============================================================================
// 🚀 READY TO COPY PASTE - NO COMMENTS
// =============================================================================

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman_values = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int result = 0;
        int prev_value = 0;
        
        for (int i = s.length() - 1; i >= 0; i--) {
            int current_value = roman_values[s[i]];
            
            if (current_value < prev_value) {
                result -= current_value;
            } else {
                result += current_value;
            }
            
            prev_value = current_value;
        }
        
        return result;
    }
};
