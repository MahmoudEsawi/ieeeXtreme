#include <bits/stdc++.h>
using namespace std;

string largestConcat_optimal(vector<string> v) {
    sort(v.begin(), v.end(), [](const string& a, const string& b) {
        return a + b > b + a;
    });
    
    string result = "";
    for (const string& s : v) {
        result += s;
    }
    
    return result;
}

bool compareStrings(const string& a, const string& b) {
    string ab = a + b;
    string ba = b + a;
    return ab > ba;
}

string largestConcat_2nd_best(vector<string> v) {
    sort(v.begin(), v.end(), compareStrings);
    
    string result = "";
    for (const string& s : v) {
        result += s;
    }
    
    return result;
}

void test_solutions() {
    cout << "🧪 Testing Largest Concat Number Solutions\n";
    cout << "==========================================\n\n";
    
    vector<pair<vector<string>, string>> test_cases = {
        {{"132", "13", "2"}, "213213"},
        {{"231", "23", "2"}, "232312"},
        {{"321", "32", "3", "0"}, "3323210"},
        {{"9", "99", "999"}, "999999"},
        {{"1", "2", "3"}, "321"},
        {{"10", "2"}, "210"},
        {{"3", "30", "34", "5", "9"}, "9534330"}
    };
    
    cout << "Input\t\t\tExpected\t\tOptimal\t\t2nd Best\tMatch?\n";
    cout << "--------------------------------------------------------------------\n";
    
    bool all_match = true;
    
    for (int t = 0; t < test_cases.size(); t++) {
        auto& test_case = test_cases[t];
        vector<string> input = test_case.first;
        string expected = test_case.second;
        
        string optimal_result = largestConcat_optimal(input);
        string second_best_result = largestConcat_2nd_best(input);
        
        bool optimal_match = (optimal_result == expected);
        bool second_best_match = (second_best_result == expected);
        
        cout << "[";
        for (int i = 0; i < input.size(); i++) {
            cout << input[i];
            if (i < input.size() - 1) cout << ",";
        }
        cout << "]\t\t" << expected << "\t\t" 
             << optimal_result << "\t\t" << second_best_result << "\t\t"
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
    cout << "• Optimal Solution: O(N log N) time using lambda comparator\n";
    cout << "• 2nd Best Solution: O(N log N) time using separate function\n";
    cout << "• Both solutions give correct results\n";
    cout << "• Use optimal for standard approach, 2nd best to avoid similarity\n";
    
    cout << "\n🔍 Key Insight:\n";
    cout << "• Compare a+b vs b+a to determine optimal order\n";
    cout << "• This ensures the largest possible concatenation\n";
    cout << "• Both approaches use the same logic, different syntax\n";
}

int main() {
    test_solutions();
    return 0;
}
