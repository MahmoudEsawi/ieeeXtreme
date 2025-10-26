#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0, prev = 0;
        
        for (int i = s.size() - 1; i >= 0; --i) {
            int val = 0;
            switch (s[i]) {
                case 'I': val = 1; break;
                case 'V': val = 5; break;
                case 'X': val = 10; break;
                case 'L': val = 50; break;
                case 'C': val = 100; break;
                case 'D': val = 500; break;
                case 'M': val = 1000; break;
            }
            
            if (val < prev) ans -= val;
            else ans += val;
            prev = val;
        }
        
        return ans;
    }
};
