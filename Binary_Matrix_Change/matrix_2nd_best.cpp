#include <bits/stdc++.h>
using namespace std;

void matrixChange(vector<vector<bool>>& A) {
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

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> A(N, vector<bool>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            bool cell;
            cin >> cell;
            A[i][j] = cell;
        }
    }
    
    matrixChange(A);
    
    for (int i = 0; i < (int)A.size(); ++i) {
        for (int j = 0; j < (int)A[i].size(); ++j) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}
