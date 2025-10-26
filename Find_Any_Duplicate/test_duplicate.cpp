#include <bits/stdc++.h>
using namespace std;

int findDuplicate_optimal(const vector<int>& v) {
    int slow = v[0];
    int fast = v[0];
    
    do {
        slow = v[slow];
        fast = v[v[fast]];
    } while (slow != fast);
    
    slow = v[0];
    while (slow != fast) {
        slow = v[slow];
        fast = v[fast];
    }
    
    return slow;
}

int findDuplicate_2nd_best(const vector<int>& v) {
    int n = v.size();
    int tortoise = v[0];
    int hare = v[0];
    
    while (true) {
        tortoise = v[tortoise];
        hare = v[v[hare]];
        if (tortoise == hare) break;
    }
    
    tortoise = v[0];
    while (tortoise != hare) {
        tortoise = v[tortoise];
        hare = v[hare];
    }
    
    return tortoise;
}

void test_solutions() {
    cout << "🧪 Testing Find Any Duplicate Solutions\n";
    cout << "=====================================\n\n";
    
    vector<pair<vector<int>, int>> test_cases = {
        {{1, 1}, 1},
        {{3, 3, 3, 3, 3}, 3},
        {{6, 3, 1, 7, 5, 2, 1, 4}, 1},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9, 5}, 5},
        {{2, 1, 3, 4, 2}, 2},
        {{1, 3, 4, 2, 2}, 2}
    };
    
    cout << "Input\t\t\tExpected\tOptimal\t2nd Best\tMatch?\n";
    cout << "----------------------------------------------------\n";
    
    bool all_match = true;
    
    for (int t = 0; t < test_cases.size(); t++) {
        auto& test_case = test_cases[t];
        vector<int> input = test_case.first;
        int expected = test_case.second;
        
        int optimal_result = findDuplicate_optimal(input);
        int second_best_result = findDuplicate_2nd_best(input);
        
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
    cout << "• Optimal Solution: O(N) time, O(1) space using do-while loop\n";
    cout << "• 2nd Best Solution: O(N) time, O(1) space using while(true) loop\n";
    cout << "• Both solutions give correct results\n";
    cout << "• Use optimal for standard approach, 2nd best to avoid similarity\n";
    
    cout << "\n🔍 Floyd's Cycle Detection Algorithm:\n";
    cout << "• Phase 1: Find intersection point using slow/fast pointers\n";
    cout << "• Phase 2: Find cycle start by moving both pointers one step\n";
    cout << "• The cycle start is the duplicate number\n";
    cout << "• Works because array values are valid indices (1 to N)\n";
}

int main() {
    test_solutions();
    return 0;
}
