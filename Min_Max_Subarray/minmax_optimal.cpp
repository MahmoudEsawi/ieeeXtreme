#include <bits/stdc++.h>
using namespace std;

int minMaxSubarray(const vector<int>& v) {
    int n = v.size();
    if (n == 1) return 1;
    
    int minVal = *min_element(v.begin(), v.end());
    int maxVal = *max_element(v.begin(), v.end());
    
    if (minVal == maxVal) return 1;
    
    int result = n;
    int lastMin = -1, lastMax = -1;
    
    for (int i = 0; i < n; i++) {
        if (v[i] == minVal) {
            lastMin = i;
            if (lastMax != -1) {
                result = min(result, i - lastMax + 1);
            }
        }
        if (v[i] == maxVal) {
            lastMax = i;
            if (lastMin != -1) {
                result = min(result, i - lastMin + 1);
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
