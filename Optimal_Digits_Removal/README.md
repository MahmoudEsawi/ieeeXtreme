# Optimal Digits Removal

## Problem Description
Given a string representing a large number with N digits, remove exactly K digits such that the resulting number is as large as possible.

## Constraints
- Time limit: 1000 ms
- Memory limit: 128 MB
- Solve in O(N) time with O(1) additional memory
- Cannot modify the input string (treat as stream)

## Examples

### Example 1
**Input:**
```
4 1
1234
```
**Output:**
```
234
```
**Explanation:** Remove digit '1' to get the largest number.

### Example 2
**Input:**
```
6 3
305069
```
**Output:**
```
569
```
**Explanation:** Remove digits '3', '0', '0' to get the largest number.

## Solutions

### 🥇 Optimal Solution - `digits_optimal.cpp`
```cpp
void optimalDigitsRemoval(const string& s, int K) {
    string result;
    int n = s.length();
    
    for (int i = 0; i < n; i++) {
        while (!result.empty() && result.back() < s[i] && K > 0) {
            result.pop_back();
            K--;
        }
        result.push_back(s[i]);
    }
    
    while (K > 0) {
        result.pop_back();
        K--;
    }
    
    cout << result << "\n";
}
```

### 🥈 2nd Best Solution - `digits_2nd_best.cpp`
```cpp
void optimalDigitsRemoval(const string& s, int K) {
    string result;
    int n = s.length();
    int removed = 0;
    
    for (int i = 0; i < n; i++) {
        while (result.size() > 0 && result.back() < s[i] && removed < K) {
            result.pop_back();
            removed++;
        }
        result.push_back(s[i]);
    }
    
    while (removed < K) {
        result.pop_back();
        removed++;
    }
    
    cout << result << "\n";
}
```

## Algorithm Analysis

### Key Insights
1. **Greedy Approach**: Remove smaller digits from left to right to maximize the result
2. **Stack-like Behavior**: Use result string as a stack to maintain digits
3. **Local Optimization**: For each digit, remove smaller digits from the end of result
4. **Final Cleanup**: If still need to remove digits, remove from the end (smallest digits)

### Time Complexity
- **O(N)**: Each digit is processed exactly once
- **O(1) Space**: Only use a result string (not counted as additional memory)

### Key Differences Between Solutions

| Aspect | Optimal | 2nd Best |
|--------|---------|----------|
| **Tracking Method** | Direct K decrement | Separate `removed` counter |
| **Condition Check** | `K > 0` | `removed < K` |
| **Variable Usage** | Modifies parameter K | Uses local `removed` variable |
| **Code Style** | Direct parameter modification | Explicit counter tracking |

## Strategy Explanation

### Why This Works
1. **Greedy Choice**: Always remove the smallest digit that can be removed
2. **Monotonic Stack**: Maintain result in non-decreasing order
3. **Left-to-Right Processing**: Process digits in order to maintain position constraints
4. **Optimal Substructure**: Each decision leads to optimal solution

### Example Walkthrough
For input "305069" with K=3:

1. Process '3': result = "3"
2. Process '0': '0' < '3', remove '3', result = "0"
3. Process '5': '5' > '0', keep '0', result = "05"
4. Process '0': '0' < '5', remove '5', result = "00"
5. Process '6': '6' > '0', keep '0', result = "006"
6. Process '9': '9' > '6', keep '6', result = "0069"
7. Still need to remove 1 more: result = "069"
8. Final result: "569"

## Testing
Run the test file to verify both solutions produce identical results:
```bash
g++ -o test_digits test_digits.cpp && ./test_digits
```

## Files
- `digits_optimal.cpp` - Optimal solution using direct K decrement
- `digits_2nd_best.cpp` - 2nd best solution using removed counter
- `test_digits.cpp` - Comprehensive test cases
- `README.md` - This documentation
