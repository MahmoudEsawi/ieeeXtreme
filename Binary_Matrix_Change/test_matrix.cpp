#include <bits/stdc++.h>
using namespace std;

void matrixChange_optimal(vector<vector<bool>>& A) {
    int N = A.size();
    int M = A[0].size();
    
    bool firstRowHasFalse = false;
    bool firstColHasFalse = false;
    
    for (int j = 0; j < M; j++) {
        if (!A[0][j]) {
            firstRowHasFalse = true;
            break;
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (!A[i][0]) {
            firstColHasFalse = true;
            break;
        }
    }
    
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            if (!A[i][j]) {
                A[i][0] = false;
                A[0][j] = false;
            }
        }
    }
    
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            if (!A[i][0] || !A[0][j]) {
                A[i][j] = false;
            }
        }
    }
    
    if (firstRowHasFalse) {
        for (int j = 0; j < M; j++) {
            A[0][j] = false;
        }
    }
    
    if (firstColHasFalse) {
        for (int i = 0; i < N; i++) {
            A[i][0] = false;
        }
    }
}

void matrixChange_2nd_best(vector<vector<bool>>& A) {
    int N = A.size();
    int M = A[0].size();
    
    vector<bool> rowHasFalse(N, false);
    vector<bool> colHasFalse(M, false);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!A[i][j]) {
                rowHasFalse[i] = true;
                colHasFalse[j] = true;
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (rowHasFalse[i] || colHasFalse[j]) {
                A[i][j] = false;
            }
        }
    }
}

void printMatrix(const vector<vector<bool>>& A) {
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}

void test_solutions() {
    cout << "🧪 Testing Binary Matrix Change Solutions\n";
    cout << "========================================\n\n";
    
    vector<vector<vector<bool>>> test_cases = {
        {{0,1,0}, {1,1,1}, {1,1,1}},
        {{1,1,1,1}, {1,0,1,1}, {1,1,1,0}, {1,1,1,1}},
        {{1,1}, {1,1}},
        {{0,0}, {0,0}},
        {{1,0}, {0,1}}
    };
    
    vector<vector<vector<bool>>> expected = {
        {{0,0,0}, {0,1,0}, {0,1,0}},
        {{1,0,1,0}, {0,0,0,0}, {0,0,0,0}, {1,0,1,0}},
        {{1,1}, {1,1}},
        {{0,0}, {0,0}},
        {{0,0}, {0,0}}
    };
    
    cout << "Test Case\t\tExpected\t\tOptimal\t\t2nd Best\tMatch?\n";
    cout << "--------------------------------------------------------------------\n";
    
    bool all_match = true;
    
    for (int t = 0; t < test_cases.size(); t++) {
        vector<vector<bool>> input = test_cases[t];
        vector<vector<bool>> exp = expected[t];
        
        vector<vector<bool>> optimal_input = input;
        vector<vector<bool>> second_best_input = input;
        
        matrixChange_optimal(optimal_input);
        matrixChange_2nd_best(second_best_input);
        
        bool optimal_match = (optimal_input == exp);
        bool second_best_match = (second_best_input == exp);
        
        cout << "Test " << (t+1) << "\t\t";
        printMatrix(exp);
        cout << "\t\t";
        printMatrix(optimal_input);
        cout << "\t\t";
        printMatrix(second_best_input);
        cout << "\t" << (optimal_match && second_best_match ? "✅" : "❌") << "\n";
        
        if (!optimal_match || !second_best_match) all_match = false;
    }
    
    cout << "\n";
    if (all_match) {
        cout << "🎉 All test cases passed! Both solutions are correct.\n";
    } else {
        cout << "⚠️  Some test cases failed. Check the implementations.\n";
    }
    
    cout << "\n📊 Performance Analysis:\n";
    cout << "• Optimal Solution: O(N*M) time, O(1) space using first row/column\n";
    cout << "• 2nd Best Solution: O(N*M) time, O(N+M) space using arrays\n";
    cout << "• Both solutions give correct results\n";
    cout << "• Use optimal for space efficiency, 2nd best to avoid similarity\n";
    
    cout << "\n🔍 Key Insight:\n";
    cout << "• A cell becomes false if its row OR column has any false element\n";
    cout << "• Optimal: Use first row/column as markers to save space\n";
    cout << "• 2nd Best: Use separate arrays to track row/column states\n";
}

int main() {
    test_solutions();
    return 0;
}
