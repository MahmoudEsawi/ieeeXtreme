#include <iostream>
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

void test_solution() {
    Solution sol;
    
    cout << "🏆 Palindrome Number Problem - C++ Solution Test" << endl;
    cout << "مشكلة الرقم المتناظر - اختبار الحل" << endl;
    cout << "================================================" << endl;
    cout << endl;
    
    // Test Case 1
    int x1 = 121;
    bool result1 = sol.isPalindrome(x1);
    
    cout << "📝 Test Case 1:" << endl;
    cout << "   Input: x = 121" << endl;
    cout << "   Expected: true" << endl;
    cout << "   Result: " << (result1 ? "true" : "false") << " ";
    cout << (result1 ? "✅" : "❌") << endl;
    cout << endl;
    
    // Test Case 2
    int x2 = -121;
    bool result2 = sol.isPalindrome(x2);
    
    cout << "📝 Test Case 2:" << endl;
    cout << "   Input: x = -121" << endl;
    cout << "   Expected: false" << endl;
    cout << "   Result: " << (result2 ? "true" : "false") << " ";
    cout << (!result2 ? "✅" : "❌") << endl;
    cout << endl;
    
    // Test Case 3
    int x3 = 10;
    bool result3 = sol.isPalindrome(x3);
    
    cout << "📝 Test Case 3:" << endl;
    cout << "   Input: x = 10" << endl;
    cout << "   Expected: false" << endl;
    cout << "   Result: " << (result3 ? "true" : "false") << " ";
    cout << (!result3 ? "✅" : "❌") << endl;
    cout << endl;
    
    // Test Case 4
    int x4 = 0;
    bool result4 = sol.isPalindrome(x4);
    
    cout << "📝 Test Case 4:" << endl;
    cout << "   Input: x = 0" << endl;
    cout << "   Expected: true" << endl;
    cout << "   Result: " << (result4 ? "true" : "false") << " ";
    cout << (result4 ? "✅" : "❌") << endl;
    cout << endl;
    
    // Test Case 5
    int x5 = 12321;
    bool result5 = sol.isPalindrome(x5);
    
    cout << "📝 Test Case 5:" << endl;
    cout << "   Input: x = 12321" << endl;
    cout << "   Expected: true" << endl;
    cout << "   Result: " << (result5 ? "true" : "false") << " ";
    cout << (result5 ? "✅" : "❌") << endl;
    cout << endl;
    
    cout << "🎯 Algorithm Analysis:" << endl;
    cout << "تحليل الخوارزمية:" << endl;
    cout << "===================" << endl;
    cout << "Time Complexity: O(log n) - تعقيد زمني لوغاريتمي" << endl;
    cout << "Space Complexity: O(1) - تعقيد مكاني ثابت" << endl;
    cout << "Algorithm: Mathematical approach - نهج رياضي" << endl;
    cout << "Follow up: Solved without string conversion - تم الحل بدون تحويل لسلسلة نصية" << endl;
    cout << "Best for: Competitive Programming - مثالي للبرمجة التنافسية" << endl;
    cout << endl;
    cout << "🏁 Recommendation: Use this solution for IEEE Xtreme competition!" << endl;
    cout << "🏁 التوصية: استخدم هذا الحل لمسابقة IEEE Xtreme!" << endl;
}

int main() {
    test_solution();
    return 0;
}
