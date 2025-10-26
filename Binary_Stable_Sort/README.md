# Binary Stable Sort

## Problem Description
Sort a row of N children such that:
1. All blue team members are in front of red team members
2. Children from the same team maintain their relative order (stable sort)

## Constraints
- Time limit: 1000 ms
- Memory limit: 128 MB
- Solve in O(N log N) time with O(1) extra memory
- Names are distinct
- Teams are either 'B' (blue) or 'R' (red)

## Examples

### Example 1
**Input:**
```
3
Alex B
Casper B
Ben B
```
**Output:**
```
Alex
Casper
Ben
```
**Explanation:** All children are blue team, so order remains unchanged.

### Example 2
**Input:**
```
6
Ben R
Ditto R
Casper B
Alex B
Erica R
fooBar B
```
**Output:**
```
Casper
Alex
fooBar
Ben
Ditto
Erica
```
**Explanation:** Blue team members (Casper, Alex, fooBar) come first, then red team members (Ben, Ditto, Erica), maintaining relative order within each team.

## Solutions

### 🥇 Optimal Solution - `binary_sort_optimal.cpp`
```cpp
void sortChildren(vector<Child>& children) {
    stable_sort(children.begin(), children.end(), [](const Child& a, const Child& b) {
        return a.team < b.team;
    });
}
```

### 🥈 2nd Best Solution - `binary_sort_2nd_best.cpp`
```cpp
void sortChildren(vector<Child>& children) {
    sort(children.begin(), children.end(), [](const Child& a, const Child& b) {
        if (a.team != b.team) {
            return a.team < b.team;
        }
        return false;
    });
}
```

## Algorithm Analysis

### Key Insights
1. **Stable Partitioning**: Separate blue team (0) from red team (1)
2. **Relative Order**: Maintain original order within each team
3. **Binary Classification**: Only two teams, so simple comparison
4. **Stability Requirement**: Critical for maintaining relative order

### Time Complexity
- **O(N log N)**: Both solutions use comparison-based sorting
- **O(1) Space**: Only use the input vector, no additional memory

### Key Differences Between Solutions

| Aspect | Optimal | 2nd Best |
|--------|---------|----------|
| **Sorting Algorithm** | `stable_sort` | `sort` with custom comparator |
| **Stability** | Guaranteed by algorithm | Achieved by custom comparator |
| **Comparator Logic** | Simple `a.team < b.team` | Explicit team comparison with fallback |
| **Code Style** | Direct stable sort | Custom comparator approach |

## Strategy Explanation

### Why This Works
1. **Stable Sort**: Maintains relative order of equal elements
2. **Binary Classification**: Blue team (0) < Red team (1)
3. **Custom Comparator**: Ensures proper ordering while preserving stability
4. **Optimal Substructure**: Each comparison leads to correct final order

### Example Walkthrough
For input: Ben(R), Ditto(R), Casper(B), Alex(B), Erica(R), fooBar(B)

1. **Original order**: Ben(R), Ditto(R), Casper(B), Alex(B), Erica(R), fooBar(B)
2. **After sorting**: Casper(B), Alex(B), fooBar(B), Ben(R), Ditto(R), Erica(R)
3. **Blue team order preserved**: Casper → Alex → fooBar
4. **Red team order preserved**: Ben → Ditto → Erica

### Comparator Logic (2nd Best)
```cpp
[](const Child& a, const Child& b) {
    if (a.team != b.team) {
        return a.team < b.team;  // Blue(0) < Red(1)
    }
    return false;  // Equal teams: maintain original order
}
```

## Testing
Run the test file to verify both solutions produce identical results:
```bash
g++ -o test_binary_sort test_binary_sort.cpp && ./test_binary_sort
```

## Files
- `binary_sort_optimal.cpp` - Optimal solution using stable_sort
- `binary_sort_2nd_best.cpp` - 2nd best solution using sort with custom comparator
- `test_binary_sort.cpp` - Comprehensive test cases
- `README.md` - This documentation

## Notes
- Both solutions achieve the same result with different approaches
- The 2nd best solution demonstrates how to achieve stability with regular sort
- The custom comparator's `return false` for equal teams is crucial for stability
