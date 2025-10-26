#include <bits/stdc++.h>
using namespace std;

int evenStepsElimination(int N) {
    if (N == 1) return 1;
    
    vector<int> arr;
    for (int i = 1; i <= N; i++) {
        arr.push_back(i);
    }
    
    int current_pos = 0;
    
    while (arr.size() > 1) {
        current_pos = (current_pos + 1) % (int)arr.size();
        arr.erase(arr.begin() + current_pos);
        
        if (current_pos >= (int)arr.size() && arr.size() > 0) {
            current_pos = 0;
        }
    }
    
    return arr[0];
}
