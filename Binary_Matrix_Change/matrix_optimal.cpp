#include <bits/stdc++.h>
using namespace std;

void matrixChange(vector<vector<bool>>& A) {
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
