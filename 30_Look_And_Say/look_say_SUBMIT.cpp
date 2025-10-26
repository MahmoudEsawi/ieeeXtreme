#include <bits/stdc++.h>
using namespace std;

string lookAndSay(int N) {
    string s = "1";
    
    for (int iter = 1; iter < N; ++iter) {
        string next = "";
        int i = 0;
        
        while (i < s.length()) {
            char digit = s[i];
            int cnt = 0;
            
            while (i < s.length() && s[i] == digit) {
                cnt++;
                i++;
            }
            
            next += to_string(cnt) + digit;
        }
        
        s = next;
    }
    
    return s;
}
