// =============================================================================
// 🏆 IEEE Xtreme Competition - Palindrome Number Solution
// مشكلة الرقم المتناظر - الحل الأمثل للبرمجة التنافسية
// =============================================================================

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // التحقق من الأرقام السالبة - الأرقام السالبة ليست متناظرة
        // Check for negative numbers - negative numbers are not palindromes
        if (x < 0) {
            return false;
        }
        
        // التحقق من الأرقام التي تنتهي بصفر (عدا الصفر نفسه)
        // Check for numbers ending with 0 (except 0 itself)
        if (x != 0 && x % 10 == 0) {
            return false;
        }
        
        // متغير لحفظ نصف الرقم المقلوب
        // Variable to store half of the reversed number
        int reversed_half = 0;
        
        // تكرار حتى يصبح الرقم الأصلي أصغر من النصف المقلوب
        // Loop until original number becomes smaller than reversed half
        while (x > reversed_half) {
            // إضافة آخر رقم من x إلى reversed_half
            // Add last digit of x to reversed_half
            reversed_half = reversed_half * 10 + x % 10;
            
            // إزالة آخر رقم من x
            // Remove last digit from x
            x /= 10;
        }
        
        // للرقم الفردي: x == reversed_half / 10
        // للرقم الزوجي: x == reversed_half
        // For odd digits: x == reversed_half / 10
        // For even digits: x == reversed_half
        return x == reversed_half || x == reversed_half / 10;
    }
};

// =============================================================================
// 🚀 شرح الحل باللهجة الأردنية
// =============================================================================

// هاد الحل هو الأذكى والأسرع للتحقق من الرقم المتناظر. بدل ما نحول الرقم لسلسلة نصية
// ونقارنها (وهيك راح ياخد مساحة إضافية ووقت أطول)، احنا بنعمل العكس بطريقة ذكية.
// 
// الفكرة الأساسية:
// 1. الأرقام السالبة مش متناظرة (مثل -121 مش متناظر)
// 2. الأرقام اللي بتنتهي بصفر (عدا الصفر نفسه) مش متناظرة (مثل 10 مش متناظر)
// 3. بناخد نصف الرقم ونقلبه ونقارنه مع النصف التاني
// 
// مثال: 1221
// - x = 1221, reversed_half = 0
// - x = 122, reversed_half = 1
// - x = 12, reversed_half = 12
// - x < reversed_half, نوقف
// - x == reversed_half (12 == 12) → true
// 
// مثال: 12321 (رقم فردي)
// - x = 12321, reversed_half = 0
// - x = 1232, reversed_half = 1
// - x = 123, reversed_half = 12
// - x = 12, reversed_half = 123
// - x < reversed_half, نوقف
// - x == reversed_half / 10 (12 == 123/10 = 12) → true

// =============================================================================
// 🎯 تحليل الأداء
// =============================================================================

// Time Complexity: O(log n) - تعقيد زمني لوغاريتمي
// Space Complexity: O(1) - تعقيد مكاني ثابت
// Algorithm: Mathematical approach - نهج رياضي
// Best for: Competitive Programming - مثالي للبرمجة التنافسية
// Follow up: Solved without string conversion - تم الحل بدون تحويل لسلسلة نصية

// =============================================================================
// 🏆 أمثلة على الاستخدام
// =============================================================================

// Example 1: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left
// 
// Example 2: x = -121  
// Output: false
// Explanation: Negative numbers are not palindromes
// 
// Example 3: x = 10
// Output: false
// Explanation: Numbers ending with 0 (except 0) are not palindromes
// 
// Example 4: x = 0
// Output: true
// Explanation: 0 is a palindrome

// =============================================================================
// 🚀 READY TO COPY PASTE - NO COMMENTS
// =============================================================================

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        if (x != 0 && x % 10 == 0) {
            return false;
        }
        
        int reversed_half = 0;
        
        while (x > reversed_half) {
            reversed_half = reversed_half * 10 + x % 10;
            x /= 10;
        }
        
        return x == reversed_half || x == reversed_half / 10;
    }
};
