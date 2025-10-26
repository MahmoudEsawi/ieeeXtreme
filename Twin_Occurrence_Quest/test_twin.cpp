#include <iostream>
#include <vector>
using namespace std;

int findFirstOccurrence_optimal(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}

int findLastOccurrence_optimal(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            left = mid + 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}

int findFirstOccurrence_2nd_best(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int first_pos = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            first_pos = mid;
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return first_pos;
}

int findLastOccurrence_2nd_best(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int last_pos = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            last_pos = mid;
            left = mid + 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return last_pos;
}

void test_solutions() {
    cout << "🧪 Testing Twin Occurrence Quest Solutions\n";
    cout << "=========================================\n\n";
    
    vector<pair<vector<int>, vector<int>>> test_cases = {
        {{2, 4, 4, 4, 5, 8, 10, 12}, {4, 10, 5, 11}},
        {{1, 1, 1, 1, 1}, {1, 2}},
        {{1, 2, 3, 4, 5}, {1, 3, 5, 6}},
        {{1, 3, 3, 3, 5}, {3, 1, 5, 2}},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {5, 1, 10, 11}}
    };
    
    vector<vector<pair<int, int>>> expected = {
        {{2, 4}, {7, 7}, {5, 5}, {-1, -1}},
        {{1, 5}, {-1, -1}},
        {{1, 1}, {3, 3}, {5, 5}, {-1, -1}},
        {{2, 4}, {1, 1}, {5, 5}, {-1, -1}},
        {{5, 5}, {1, 1}, {10, 10}, {-1, -1}}
    };
    
    cout << "Test Case\t\tQuery\tExpected\tOptimal\t\t2nd Best\tMatch?\n";
    cout << "--------------------------------------------------------------------\n";
    
    bool all_match = true;
    
    for (int t = 0; t < test_cases.size(); t++) {
        vector<int> arr = test_cases[t].first;
        vector<int> queries = test_cases[t].second;
        vector<pair<int, int>> exp = expected[t];
        
        cout << "Test " << (t+1) << ": [";
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i];
            if (i < arr.size() - 1) cout << ",";
        }
        cout << "]\n";
        
        for (int q = 0; q < queries.size(); q++) {
            int X = queries[q];
            pair<int, int> expected_result = exp[q];
            
            int first_opt = findFirstOccurrence_optimal(arr, X);
            int last_opt = findLastOccurrence_optimal(arr, X);
            pair<int, int> result_opt = (first_opt == -1) ? make_pair(-1, -1) : make_pair(first_opt + 1, last_opt + 1);
            
            int first_2nd = findFirstOccurrence_2nd_best(arr, X);
            int last_2nd = findLastOccurrence_2nd_best(arr, X);
            pair<int, int> result_2nd = (first_2nd == -1) ? make_pair(-1, -1) : make_pair(first_2nd + 1, last_2nd + 1);
            
            bool opt_match = (result_opt == expected_result);
            bool second_match = (result_2nd == expected_result);
            bool both_match = opt_match && second_match;
            
            cout << "  Query " << X << "\t\t" << expected_result.first << "," << expected_result.second 
                 << "\t\t" << result_opt.first << "," << result_opt.second 
                 << "\t\t" << result_2nd.first << "," << result_2nd.second 
                 << "\t\t" << (both_match ? "✅" : "❌") << "\n";
            
            all_match = all_match && both_match;
        }
        cout << "\n";
    }
    
    cout << "\n📊 Performance Analysis:\n";
    cout << "• Optimal Solution: O(log N) per query using binary search\n";
    cout << "• 2nd Best Solution: O(log N) per query using binary search with different variable names\n";
    cout << "• Both solutions use the same algorithm with different variable naming\n";
    cout << "• Total complexity: O(Q log N) for Q queries\n";
    
    cout << "\n🔍 Algorithm Explanation:\n";
    cout << "• Use binary search to find first occurrence (leftmost)\n";
    cout << "• Use binary search to find last occurrence (rightmost)\n";
    cout << "• Key insight: When target is found, continue searching in the appropriate direction\n";
    cout << "• First occurrence: when found, search left (right = mid - 1)\n";
    cout << "• Last occurrence: when found, search right (left = mid + 1)\n";
    
    cout << "\n💡 Key Differences:\n";
    cout << "• Optimal: Uses 'result' variable name\n";
    cout << "• 2nd Best: Uses 'first_pos' and 'last_pos' variable names\n";
    cout << "• Both achieve the same result with different variable naming\n";
    cout << "• Different code style: generic 'result' vs descriptive 'first_pos'/'last_pos'\n";
}

int main() {
    test_solutions();
    return 0;
}
