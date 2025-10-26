#include <bits/stdc++.h>
using namespace std;

bool compareStrings(const string& a, const string& b) {
    string ab = a + b;
    string ba = b + a;
    return ab > ba;
}

string largestConcat(vector<string>& v) {
    sort(v.begin(), v.end(), compareStrings);
    
    string result = "";
    for (const string& s : v) {
        result += s;
    }
    
    return result;
}
