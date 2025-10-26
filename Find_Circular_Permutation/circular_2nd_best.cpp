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
    int last = query(N);
    
    for (int i = 1; i <= N; i++) {
        int curr = query(i);
        if (curr <= last) {
            return N - i;
        }
    }
    
    return 0;
}
