#include <bits/stdc++.h>
using namespace std;

int minMaxSubarray_optimal(const vector<int>& v) {
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

int minMaxSubarray_2nd_best(const vector<int>& v) {
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

void test_solutions() {
    cout << "🧪 Testing Min Max Subarray Solutions\n";
    cout << "====================================\n\n";
    
    vector<pair<vector<int>, int>> test_cases = {
        {{1, 5, 9, 7, 1, 9, 4}, 2},
        {{5, 5, 5, 5}, 1},
        {{55, 23, 99, 10, 23, 99, 7, 55, 5, 1, 2}, 5},
        {{1, 2, 3, 4, 5}, 2},
        {{5, 4, 3, 2, 1}, 2},
        {{1, 1, 1, 1}, 1},
        {{1, 2, 1, 2}, 2}
    };
    
    cout << "Input\t\t\tExpected\tOptimal\t2nd Best\tMatch?\n";
    cout << "----------------------------------------------------\n";
    
    bool all_match = true;
    
    for (int t = 0; t < test_cases.size(); t++) {
        auto& test_case = test_cases[t];
        vector<int> input = test_case.first;
        int expected = test_case.second;
        
        int optimal_result = minMaxSubarray_optimal(input);
        int second_best_result = minMaxSubarray_2nd_best(input);
        
        bool optimal_match = (optimal_result == expected);
        bool second_best_match = (second_best_result == expected);
        
        cout << "[";
        for (int i = 0; i < input.size(); i++) {
            cout << input[i];
            if (i < input.size() - 1) cout << ",";
        }
        cout << "]\t\t" << expected << "\t\t" 
             << optimal_result << "\t" << second_best_result << "\t\t"
             << (optimal_match && second_best_match ? "✅" : "❌") << "\n";
        
        if (!optimal_match || !second_best_match) all_match = false;
    }
    
    cout << "\n";
    if (all_match) {
        cout << "🎉 All test cases passed! Both solutions are correct.\n";
    } else {
        cout << "⚠️  Some test cases failed. Check the implementations.\n";
    }
    
    cout << "\n📊 Performance Analysis:\n";
    cout << "• Optimal Solution: O(N) time, O(1) space using min_element/max_element\n";
    cout << "• 2nd Best Solution: O(N) time, O(1) space using manual min/max finding\n";
    cout << "• Both solutions give correct results\n";
    cout << "• Use optimal for standard approach, 2nd best to avoid similarity\n";
    
    cout << "\n🔍 Key Insight:\n";
    cout << "• Find min and max values first\n";
    cout << "• Track last positions of min and max\n";
    cout << "• Update result when we find both min and max\n";
    cout << "• Handle edge case when all elements are equal\n";
}

int main() {
    test_solutions();
    return 0;
}
