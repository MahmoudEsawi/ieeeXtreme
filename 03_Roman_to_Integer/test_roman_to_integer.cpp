#include <iostream>
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

void test_solution() {
    Solution sol;
    
    cout << "🏆 Roman to Integer Problem - C++ Solution Test" << endl;
    cout << "تحويل الأرقام الرومانية إلى أرقام عربية - اختبار الحل" << endl;
    cout << "=====================================================" << endl;
    cout << endl;
    
    // Test Case 1
    string s1 = "III";
    int result1 = sol.romanToInt(s1);
    
    cout << "📝 Test Case 1:" << endl;
    cout << "   Input: s = \"III\"" << endl;
    cout << "   Expected: 3" << endl;
    cout << "   Result: " << result1 << " ";
    cout << (result1 == 3 ? "✅" : "❌") << endl;
    cout << endl;
    
    // Test Case 2
    string s2 = "LVIII";
    int result2 = sol.romanToInt(s2);
    
    cout << "📝 Test Case 2:" << endl;
    cout << "   Input: s = \"LVIII\"" << endl;
    cout << "   Expected: 58" << endl;
    cout << "   Result: " << result2 << " ";
    cout << (result2 == 58 ? "✅" : "❌") << endl;
    cout << endl;
    
    // Test Case 3
    string s3 = "MCMXCIV";
    int result3 = sol.romanToInt(s3);
    
    cout << "📝 Test Case 3:" << endl;
    cout << "   Input: s = \"MCMXCIV\"" << endl;
    cout << "   Expected: 1994" << endl;
    cout << "   Result: " << result3 << " ";
    cout << (result3 == 1994 ? "✅" : "❌") << endl;
    cout << endl;
    
    // Test Case 4 - Special cases
    string s4 = "IV";
    int result4 = sol.romanToInt(s4);
    
    cout << "📝 Test Case 4:" << endl;
    cout << "   Input: s = \"IV\"" << endl;
    cout << "   Expected: 4" << endl;
    cout << "   Result: " << result4 << " ";
    cout << (result4 == 4 ? "✅" : "❌") << endl;
    cout << endl;
    
    // Test Case 5 - Special cases
    string s5 = "IX";
    int result5 = sol.romanToInt(s5);
    
    cout << "📝 Test Case 5:" << endl;
    cout << "   Input: s = \"IX\"" << endl;
    cout << "   Expected: 9" << endl;
    cout << "   Result: " << result5 << " ";
    cout << (result5 == 9 ? "✅" : "❌") << endl;
    cout << endl;
    
    // Test Case 6 - Special cases
    string s6 = "XL";
    int result6 = sol.romanToInt(s6);
    
    cout << "📝 Test Case 6:" << endl;
    cout << "   Input: s = \"XL\"" << endl;
    cout << "   Expected: 40" << endl;
    cout << "   Result: " << result6 << " ";
    cout << (result6 == 40 ? "✅" : "❌") << endl;
    cout << endl;
    
    // Test Case 7 - Special cases
    string s7 = "XC";
    int result7 = sol.romanToInt(s7);
    
    cout << "📝 Test Case 7:" << endl;
    cout << "   Input: s = \"XC\"" << endl;
    cout << "   Expected: 90" << endl;
    cout << "   Result: " << result7 << " ";
    cout << (result7 == 90 ? "✅" : "❌") << endl;
    cout << endl;
    
    // Test Case 8 - Special cases
    string s8 = "CD";
    int result8 = sol.romanToInt(s8);
    
    cout << "📝 Test Case 8:" << endl;
    cout << "   Input: s = \"CD\"" << endl;
    cout << "   Expected: 400" << endl;
    cout << "   Result: " << result8 << " ";
    cout << (result8 == 400 ? "✅" : "❌") << endl;
    cout << endl;
    
    // Test Case 9 - Special cases
    string s9 = "CM";
    int result9 = sol.romanToInt(s9);
    
    cout << "📝 Test Case 9:" << endl;
    cout << "   Input: s = \"CM\"" << endl;
    cout << "   Expected: 900" << endl;
    cout << "   Result: " << result9 << " ";
    cout << (result9 == 900 ? "✅" : "❌") << endl;
    cout << endl;
    
    cout << "🎯 Algorithm Analysis:" << endl;
    cout << "تحليل الخوارزمية:" << endl;
    cout << "===================" << endl;
    cout << "Time Complexity: O(n) - تعقيد زمني خطي" << endl;
    cout << "Space Complexity: O(1) - تعقيد مكاني ثابت" << endl;
    cout << "Algorithm: Right-to-left traversal - اجتياز من اليمين لليسار" << endl;
    cout << "Best for: Competitive Programming - مثالي للبرمجة التنافسية" << endl;
    cout << endl;
    cout << "🏁 Recommendation: Use this solution for IEEE Xtreme competition!" << endl;
    cout << "🏁 التوصية: استخدم هذا الحل لمسابقة IEEE Xtreme!" << endl;
}

int main() {
    test_solution();
    return 0;
}
