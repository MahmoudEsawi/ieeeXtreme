#include <bits/stdc++.h>
using namespace std;

int minMaxSubarray(const vector<int>& v) {
    int n = v.size();
    if (n == 1) return 1;
    
    int minVal = v[0], maxVal = v[0];
    for (int i = 1; i < n; i++) {
        minVal = min(minVal, v[i]);
        maxVal = max(maxVal, v[i]);
    }
    
    if (minVal == maxVal) return 1;
    
    int result = n;
    int minPos = -1, maxPos = -1;
    
    for (int i = 0; i < n; i++) {
        if (v[i] == minVal) {
            minPos = i;
            if (maxPos != -1) {
                result = min(result, abs(i - maxPos) + 1);
            }
        }
        if (v[i] == maxVal) {
            maxPos = i;
            if (minPos != -1) {
                result = min(result, abs(i - minPos) + 1);
            }
        }
    }
    
    return result;
}

int main() {
    int N;
    cin >> N;
    vector<int> v;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        v.push_back(val);
    }
    
    cout << minMaxSubarray(v) << "\n";
    return 0;
}
