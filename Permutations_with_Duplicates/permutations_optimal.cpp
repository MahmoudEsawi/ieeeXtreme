#include <bits/stdc++.h>
using namespace std;

void printDistinctPermutations(vector<int>& v) {
    sort(v.begin(), v.end());
    
    do {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i < v.size() - 1) cout << " ";
        }
        cout << "\n";
    } while (next_permutation(v.begin(), v.end()));
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
    
    printDistinctPermutations(v);
    return 0;
}
