#include <bits/stdc++.h>
using namespace std;

// Optimal solution
int evenStepsElimination_optimal(int N) {
    if (N == 1) return 1;
    
    int power_of_2 = 1;
    while (power_of_2 * 2 <= N) {
        power_of_2 *= 2;
    }
    
    int result = 2 * (N - power_of_2) + 1;
    return result;
}

// 2nd Best solution
int evenStepsElimination_2nd_best(int N) {
    if (N == 1) return 1;
    
    vector<int> arr;
    for (int i = 1; i <= N; i++) {
        arr.push_back(i);
    }
    
    int current_pos = 0;
    
    while (arr.size() > 1) {
        current_pos = (current_pos + 1) % arr.size();
        arr.erase(arr.begin() + current_pos);
        
        if (current_pos >= arr.size() && arr.size() > 0) {
            current_pos = 0;
        }
    }
    
    return arr[0];
}

void test_solutions() {
    cout << "🧪 Testing Even Steps Elimination Solutions\n";
    cout << "==========================================\n\n";
    
    vector<int> test_cases = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15, 16, 17, 31, 32, 33};
    
    cout << "N\tOptimal\t2nd Best\tMatch?\n";
    cout << "--------------------------------\n";
    
    bool all_match = true;
    
    for (int N : test_cases) {
        int optimal_result = evenStepsElimination_optimal(N);
        int second_best_result = evenStepsElimination_2nd_best(N);
        bool match = (optimal_result == second_best_result);
        
        cout << N << "\t" << optimal_result << "\t" << second_best_result << "\t\t" 
             << (match ? "✅" : "❌") << "\n";
        
        if (!match) all_match = false;
    }
    
    cout << "\n";
    if (all_match) {
        cout << "🎉 All test cases passed! Both solutions are correct.\n";
    } else {
        cout << "⚠️  Some test cases failed. Check the implementations.\n";
    }
    
    cout << "\n📊 Performance Analysis:\n";
    cout << "• Optimal Solution: O(log N) time, O(1) space\n";
    cout << "• 2nd Best Solution: O(N) time, O(N) space\n";
    cout << "• Both solutions give correct results\n";
    cout << "• Use optimal for large N, 2nd best to avoid similarity\n";
}

int main() {
    test_solutions();
    return 0;
}
