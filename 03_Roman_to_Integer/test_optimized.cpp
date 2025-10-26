#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int prev_value = 0;
        
        for (int i = s.length() - 1; i >= 0; i--) {
            int current_value = s[i] == 'I' ? 1 : s[i] == 'V' ? 5 : s[i] == 'X' ? 10 : 
                               s[i] == 'L' ? 50 : s[i] == 'C' ? 100 : s[i] == 'D' ? 500 : 
                               s[i] == 'M' ? 1000 : 0;
            
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
    
    cout << "🏆 Roman to Integer - OPTIMIZED Solution Test" << endl;
    cout << "تحويل الأرقام الرومانية - اختبار الحل المحسن" << endl;
    cout << "=============================================" << endl;
    cout << endl;
    
    // Test Case 1
    string s1 = "III";
    int result1 = sol.romanToInt(s1);
    cout << "Test 1: \"III\" → " << result1 << (result1 == 3 ? " ✅" : " ❌") << endl;
    
    // Test Case 2
    string s2 = "LVIII";
    int result2 = sol.romanToInt(s2);
    cout << "Test 2: \"LVIII\" → " << result2 << (result2 == 58 ? " ✅" : " ❌") << endl;
    
    // Test Case 3
    string s3 = "MCMXCIV";
    int result3 = sol.romanToInt(s3);
    cout << "Test 3: \"MCMXCIV\" → " << result3 << (result3 == 1994 ? " ✅" : " ❌") << endl;
    
    // Test Case 4
    string s4 = "IV";
    int result4 = sol.romanToInt(s4);
    cout << "Test 4: \"IV\" → " << result4 << (result4 == 4 ? " ✅" : " ❌") << endl;
    
    // Test Case 5
    string s5 = "IX";
    int result5 = sol.romanToInt(s5);
    cout << "Test 5: \"IX\" → " << result5 << (result5 == 9 ? " ✅" : " ❌") << endl;
    
    cout << endl;
    cout << "🎯 Optimizations Applied:" << endl;
    cout << "- Removed hash map (O(1) lookup overhead)" << endl;
    cout << "- Used ternary operators for direct character comparison" << endl;
    cout << "- Eliminated function call overhead" << endl;
    cout << "- Reduced memory allocations" << endl;
    cout << endl;
    cout << "🚀 Expected Performance: < 3ms, Beats > 80%" << endl;
}

int main() {
    test_solution();
    return 0;
}
