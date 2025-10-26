#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman_values = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int result = 0;
        
        for (int i = 0; i < s.length(); i++) {
            int current_value = roman_values[s[i]];
            
            if (i + 1 < s.length()) {
                int next_value = roman_values[s[i + 1]];
                
                if ((s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) ||
                    (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) ||
                    (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M'))) {
                    result += next_value - current_value;
                    i++;
                } else {
                    result += current_value;
                }
            } else {
                result += current_value;
            }
        }
        
        return result;
    }
};
