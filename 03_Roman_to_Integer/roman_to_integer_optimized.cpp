#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int prev_value = 0;
        
        for (int i = s.length() - 1; i >= 0; i--) {
            int current_value;
            
            switch (s[i]) {
                case 'I': current_value = 1; break;
                case 'V': current_value = 5; break;
                case 'X': current_value = 10; break;
                case 'L': current_value = 50; break;
                case 'C': current_value = 100; break;
                case 'D': current_value = 500; break;
                case 'M': current_value = 1000; break;
                default: current_value = 0; break;
            }
            
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
