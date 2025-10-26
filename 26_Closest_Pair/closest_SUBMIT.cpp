#include <bits/stdc++.h>
using namespace std;

int closestPair(vector<int>& first, vector<int>& second) {
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    
    int minDiff = INT_MAX;
    int i = 0, j = 0;
    int n = first.size();
    
    while (i < n && j < n) {
        minDiff = min(minDiff, abs(first[i] - second[j]));
        
        if (first[i] < second[j]) {
            i++;
        } else {
            j++;
        }
    }
    
    return minDiff;
}
