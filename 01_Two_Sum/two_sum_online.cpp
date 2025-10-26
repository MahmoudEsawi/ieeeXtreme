#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int target;
    cin >> target;
    
    unordered_map<int, int> num_to_index;
    for (int i = 0; i < n; i++) {
        int complement = target - nums[i];
        if (num_to_index.find(complement) != num_to_index.end()) {
            cout << num_to_index[complement] << " " << i << endl;
            return 0;
        }
        num_to_index[nums[i]] = i;
    }
    
    cout << -1 << " " << -1 << endl;
    return 0;
}
