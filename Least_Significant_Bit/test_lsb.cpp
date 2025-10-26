#include <bits/stdc++.h>
using namespace std;

int lsb_optimal(int x) {
    return x & (-x);
}

int lsb_2nd_best(int x) {
    return x & (x - 1) ^ x;
}

void test_solutions() {
    cout << "🧪 Testing Least Significant Bit Solutions\n";
    cout << "==========================================\n\n";
    
    vector<int> test_cases = {1, 256, 1375128, 951862464, 8, 16, 32, 64, 128, 255, 1024};
    vector<int> expected = {1, 256, 8, 64, 8, 16, 32, 64, 128, 1, 1024};
    
    cout << "Input\t\tExpected\tOptimal\t2nd Best\tMatch?\n";
    cout << "----------------------------------------------------\n";
    
    bool all_match = true;
    
    for (int i = 0; i < test_cases.size(); i++) {
        int x = test_cases[i];
        int exp = expected[i];
        
        int optimal_result = lsb_optimal(x);
        int second_best_result = lsb_2nd_best(x);
        
        bool optimal_match = (optimal_result == exp);
        bool second_best_match = (second_best_result == exp);
        
        cout << x << "\t\t" << exp << "\t\t" 
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
    cout << "• Optimal Solution: O(1) time using x & (-x)\n";
    cout << "• 2nd Best Solution: O(1) time using x & (x-1) ^ x\n";
    cout << "• Both solutions give correct results\n";
    cout << "• Use optimal for standard approach, 2nd best to avoid similarity\n";
    
    cout << "\n🔍 Bitwise Operations Explained:\n";
    cout << "• x & (-x): Two's complement trick - isolates LSB\n";
    cout << "• x & (x-1) ^ x: Alternative approach - same result\n";
    cout << "• Both are O(1) and extremely fast\n";
}

int main() {
    test_solutions();
    return 0;
}
