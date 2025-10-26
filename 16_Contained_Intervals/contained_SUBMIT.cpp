#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int l, r;
};

int containedIntervals(vector<Interval>& intervals) {
    int n = intervals.size();
    int cnt = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                // Check if interval i is contained by interval j
                if (intervals[j].l <= intervals[i].l && intervals[i].r <= intervals[j].r) {
                    cnt++;
                    break;
                }
            }
        }
    }
    
    return cnt;
}
