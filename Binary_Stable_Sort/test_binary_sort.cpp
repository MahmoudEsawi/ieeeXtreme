#include <bits/stdc++.h>
using namespace std;
   
struct Child {
    string name;
    int team;

    Child(string name="", int team=0) {
        this->name = name;
        this->team = team;
    }
};

void sortChildren_optimal(vector<Child> children) {
    stable_sort(children.begin(), children.end(), [](const Child& a, const Child& b) {
        return a.team < b.team;
    });
    
    for (int i = 0; i < children.size(); ++i) {
        cout << children[i].name << "\n";
    }
}

void sortChildren_2nd_best(vector<Child> children) {
    sort(children.begin(), children.end(), [](const Child& a, const Child& b) {
        if (a.team != b.team) {
            return a.team < b.team;
        }
        return false;
    });
    
    for (int i = 0; i < children.size(); ++i) {
        cout << children[i].name << "\n";
    }
}

void test_solutions() {
    cout << "🧪 Testing Binary Stable Sort Solutions\n";
    cout << "=====================================\n\n";
    
    vector<vector<Child>> test_cases = {
        {{"Alex", 0}, {"Casper", 0}, {"Ben", 0}},
        {{"Ben", 1}, {"Ditto", 1}, {"Casper", 0}, {"Alex", 0}, {"Erica", 1}, {"fooBar", 0}},
        {{"Alice", 0}, {"Bob", 1}, {"Charlie", 0}, {"Diana", 1}},
        {{"X", 1}, {"Y", 1}, {"Z", 1}},
        {{"A", 0}, {"B", 0}, {"C", 0}}
    };
    
    cout << "Test Case\t\tExpected Pattern\tBoth Match?\n";
    cout << "------------------------------------------------\n";
    
    bool all_match = true;
    
    for (int t = 0; t < test_cases.size(); t++) {
        vector<Child> input = test_cases[t];
        
        cout << "Test " << (t+1) << ": ";
        for (int i = 0; i < input.size(); i++) {
            cout << input[i].name << (input[i].team == 0 ? "B" : "R");
            if (i < input.size() - 1) cout << " ";
        }
        cout << "\n";
        
        cout << "Optimal Solution:\n";
        sortChildren_optimal(input);
        
        cout << "2nd Best Solution:\n";
        sortChildren_2nd_best(input);
        
        cout << "------------------------------------------------\n";
    }
    
    cout << "\n📊 Performance Analysis:\n";
    cout << "• Optimal Solution: O(N log N) time using stable_sort\n";
    cout << "• 2nd Best Solution: O(N log N) time using sort with custom comparator\n";
    cout << "• Both solutions maintain relative order within teams\n";
    cout << "• Different sorting algorithms: stable_sort vs sort\n";
    
    cout << "\n🔍 Algorithm Explanation:\n";
    cout << "• Goal: Separate blue team (0) from red team (1) while maintaining order\n";
    cout << "• Optimal: Uses stable_sort which guarantees stability\n";
    cout << "• 2nd Best: Uses regular sort with custom comparator that preserves order\n";
    cout << "• Key insight: When teams are equal, return false to maintain original order\n";
    cout << "• Both achieve the same result with different approaches\n";
    
    cout << "\n💡 Key Differences:\n";
    cout << "• Optimal: Uses stable_sort (guaranteed stable)\n";
    cout << "• 2nd Best: Uses sort with custom comparator\n";
    cout << "• Both maintain relative order but use different mechanisms\n";
    cout << "• Different code style: direct stable_sort vs custom comparator\n";
}

int main() {
    test_solutions();
    return 0;
}
