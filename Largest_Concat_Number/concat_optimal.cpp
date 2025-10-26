#include <bits/stdc++.h>
using namespace std;

string largestConcat(vector<string>& v) {
    sort(v.begin(), v.end(), [](const string& a, const string& b) {
        return a + b > b + a;
    });
    
    string result = "";
    for (const string& s : v) {
        result += s;
    }
    
    return result;
}
