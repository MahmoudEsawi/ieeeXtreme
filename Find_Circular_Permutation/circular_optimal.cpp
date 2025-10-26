#include <bits/stdc++.h>
using namespace std;

int query(int index) {
    cout << "Q " << index << "\n";
    cout.flush();
    int value;
    cin >> value;
    return value;
}

int solve(int N) {
    int left = 1, right = N;
    
    while (left < right) {
        int mid = (left + right) / 2;
        int mid_val = query(mid);
        
        if (mid_val > query(N)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return N - left;
}
