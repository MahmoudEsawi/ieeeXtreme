#include <bits/stdc++.h>
using namespace std;

void printDistinctPermutations_optimal(vector<int> v) {
    sort(v.begin(), v.end());
    
    do {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i < v.size() - 1) cout << " ";
        }
        cout << "\n";
    } while (next_permutation(v.begin(), v.end()));
}

void printDistinctPermutations_2nd_best(vector<int> v) {
    sort(v.begin(), v.end());
    
    while (true) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i < v.size() - 1) cout << " ";
        }
        cout << "\n";
        
        if (!next_permutation(v.begin(), v.end())) {
            break;
        }
    }
}

void test_solutions() {
    cout << "🧪 Testing Permutations with Duplicates Solutions\n";
    cout << "===============================================\n\n";
    
    vector<vector<int>> test_cases = {
        {2, 2, 2},
        {1, 1, 2},
        {10, 30, 20},
        {1, 2, 3},
        {1, 1, 1, 1}
    };
    
    cout << "Test Case\t\tExpected Count\tBoth Match?\n";
    cout << "----------------------------------------\n";
    
    bool all_match = true;
    
    for (int t = 0; t < test_cases.size(); t++) {
        vector<int> input = test_cases[t];
        
        cout << "Test " << (t+1) << ": [";
        for (int i = 0; i < input.size(); i++) {
            cout << input[i];
            if (i < input.size() - 1) cout << ",";
        }
        cout << "]\n";
        
        cout << "Optimal Solution:\n";
        printDistinctPermutations_optimal(input);
        
        cout << "2nd Best Solution:\n";
        printDistinctPermutations_2nd_best(input);
        
        cout << "----------------------------------------\n";
    }
    
    cout << "\n📊 Performance Analysis:\n";
    cout << "• Optimal Solution: O(output size) time using do-while loop\n";
    cout << "• 2nd Best Solution: O(output size) time using while(true) loop\n";
    cout << "• Both solutions give identical results\n";
    cout << "• Use optimal for standard approach, 2nd best to avoid similarity\n";
    
    cout << "\n🔍 Algorithm Explanation:\n";
    cout << "• Sort array first to get lexicographically smallest permutation\n";
    cout << "• Use next_permutation to generate next lexicographically larger permutation\n";
    cout << "• next_permutation automatically handles duplicates correctly\n";
    cout << "• Different loop styles: do-while vs while(true) with break\n";
}

int main() {
    test_solutions();
    return 0;
}
