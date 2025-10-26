#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int prev_value = 0;
        
        for (int i = s.length() - 1; i >= 0; i--) {
            int current_value = getValue(s[i]);
            
            if (current_value < prev_value) {
                result -= current_value;
            } else {
                result += current_value;
            }
            
            prev_value = current_value;
        }
        
        return result;
    }
    
private:
    int getValue(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};
