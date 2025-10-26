# The Twin Occurrence Quest

## Problem Description
Given a sorted array A and Q queries, for each query find the first and last occurrence of a specified number X in the array. Report answers using 1-indexed positions.

## Constraints
- Time limit: 1000 ms
- Memory limit: 256 MB
- 1 ≤ N, Q ≤ 10^5
- Array is sorted (A_i ≤ A_{i+1})
- |A_i| ≤ 10^9, |X_j| ≤ 10^9

## Examples

### Example 1
**Input:**
```
8 4
2 4 4 4 5 8 10 12
4
10
5
11
```
**Output:**
```
2 4
7 7
5 5
-1 -1
```

**Explanation:**
- Query 4: First occurrence at position 2, last at position 4
- Query 10: Only occurrence at position 7
- Query 5: Only occurrence at position 5
- Query 11: Not found, output -1 -1

## Solutions

### 🥇 Optimal Solution - `twin_optimal.cpp`
```cpp
int findFirstOccurrence(const vector<int>& arr, int target) {
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

int findLastOccurrence(const vector<int>& arr, int target) {
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
```

### 🥈 2nd Best Solution - `twin_2nd_best.cpp`
```cpp
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
```

## Algorithm Analysis

### Key Insights
1. **Binary Search**: Use binary search to find first and last occurrences
2. **Two Separate Searches**: First occurrence (leftmost) and last occurrence (rightmost)
3. **Modified Binary Search**: When target is found, continue searching in appropriate direction
4. **1-Indexed Output**: Convert 0-indexed results to 1-indexed for output

### Time Complexity
- **O(log N) per query**: Each binary search takes O(log N) time
- **O(Q log N) total**: For Q queries
- **O(N) space**: For storing the array

### Key Differences Between Solutions

| Aspect | Optimal | 2nd Best |
|--------|---------|----------|
| **Variable Names** | `result` | `first_pos`, `last_pos` |
| **Algorithm** | Same binary search approach | Same binary search approach |
| **Code Style** | Generic variable names | Descriptive variable names |
| **Performance** | O(log N) per query | O(log N) per query |

## Strategy Explanation

### Why Binary Search Works
1. **Sorted Array**: Array is sorted, enabling binary search
2. **First Occurrence**: When target found, search left to find earliest occurrence
3. **Last Occurrence**: When target found, search right to find latest occurrence
4. **Efficient**: O(log N) instead of O(N) linear search

### Binary Search Modifications

#### First Occurrence (Leftmost)
```cpp
if (arr[mid] == target) {
    result = mid;           // Update result
    right = mid - 1;        // Continue searching left
}
```

#### Last Occurrence (Rightmost)
```cpp
if (arr[mid] == target) {
    result = mid;           // Update result
    left = mid + 1;         // Continue searching right
}
```

### Example Walkthrough
For array [2, 4, 4, 4, 5, 8, 10, 12] and query X = 4:

**First Occurrence Search:**
1. left=0, right=7, mid=3, arr[3]=4 → found, right=2
2. left=0, right=2, mid=1, arr[1]=4 → found, right=0
3. left=0, right=0, mid=0, arr[0]=2 → not found, left=1
4. left=1, right=0 → exit, result=1

**Last Occurrence Search:**
1. left=0, right=7, mid=3, arr[3]=4 → found, left=4
2. left=4, right=7, mid=5, arr[5]=8 → not found, right=4
3. left=4, right=4, mid=4, arr[4]=5 → not found, right=3
4. left=4, right=3 → exit, result=3

**Output:** 1-indexed positions: 2 4

## Testing
Run the test file to verify both solutions:
```bash
g++ -o test_twin test_twin.cpp && ./test_twin
```

## Files
- `twin_optimal.cpp` - Optimal solution using 'result' variable names
- `twin_2nd_best.cpp` - 2nd best solution using 'first_pos'/'last_pos' variable names
- `test_twin.cpp` - Comprehensive test cases with verification
- `README.md` - This documentation

## Notes
- Both solutions use identical algorithms with different variable naming
- The key insight is modifying binary search to find leftmost/rightmost occurrences
- 1-indexed output requires adding 1 to 0-indexed results
- Efficient O(log N) per query makes it suitable for large inputs
