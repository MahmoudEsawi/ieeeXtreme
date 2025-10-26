#include <iostream>
#include <vector>
using namespace std;

int findFirstOccurrence(const vector<int>& arr, int target) {
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

int findLastOccurrence(const vector<int>& arr, int target) {
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    while (Q--) {
        int X;
        cin >> X;
        
        int first = findFirstOccurrence(arr, X);
        int last = findLastOccurrence(arr, X);
        
        if (first == -1) {
            cout << "-1 -1\n";
        } else {
            cout << first + 1 << " " << last + 1 << "\n";
        }
    }
    
    return 0;
}
