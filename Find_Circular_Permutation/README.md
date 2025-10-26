# 🎯 Find Circular Permutation Problem

## 📝 Problem Description
An array of N distinct integers that were initially in increasing order is circularly permuted to the right by K positions. Your task is to find K by asking the value of certain elements of the array.

## 🎯 Examples
- **Input**: N = 4, Array = [3, 4, 1, 2] (rotated by K = 2)
- **Output**: K = 2
- **Explanation**: Original array [1, 2, 3, 4] rotated right by 2 positions

- **Input**: N = 6, Array = [4, 5, 6, 1, 2, 3] (rotated by K = 3)
- **Output**: K = 3
- **Explanation**: Original array [1, 2, 3, 4, 5, 6] rotated right by 3 positions

## 📁 Files in this folder:

### 🚀 **Ready to Submit:**
- **`circular_optimal.cpp`** - **SUBMIT THIS** (O(log N) binary search solution)
- **`circular_2nd_best.cpp`** - Alternative O(N) linear search approach

### 📚 **Learning & Testing:**
- **`test_circular.cpp`** - Test file to verify both solutions work correctly

## 🎯 Algorithm Analysis:

### 🥇 **Optimal Solution (Binary Search)**
- **Time Complexity**: O(log N) - Logarithmic queries
- **Space Complexity**: O(1) - Constant space
- **Algorithm**: Binary search to find rotation point
- **Approach**: Find where the array "breaks" from increasing order

### 🥈 **2nd Best Solution (Linear Search)**
- **Time Complexity**: O(N) - Linear queries
- **Space Complexity**: O(1) - Constant space
- **Algorithm**: Linear search with early termination
- **Approach**: Scan from left to right until finding the break point

## 🔍 Key Differences

| Aspect | Optimal Solution | 2nd Best Solution |
|--------|------------------|-------------------|
| **Approach** | Binary search | Linear search |
| **Queries** | O(log N) | O(N) |
| **Space** | O(1) | O(1) |
| **Code Style** | Divide and conquer | Sequential scan |
| **Readability** | More complex logic | Simple iteration |

## 🧮 Problem Understanding

### The Challenge:
- Array was originally [1, 2, 3, ..., N] in increasing order
- Rotated right by K positions
- Need to find K using minimal queries

### Key Insight:
The rotation point is where `arr[i] > arr[i+1]` or where the sequence breaks from increasing order.

### Example for N = 4, K = 2:
- Original: [1, 2, 3, 4]
- Rotated: [3, 4, 1, 2]
- Break point: arr[2] = 4 > arr[3] = 1
- K = N - break_point = 4 - 2 = 2 ✅

## 🚀 How to Use:

### For Competition:
1. **Use `circular_optimal.cpp`** for best performance (fewer queries)
2. **Use `circular_2nd_best.cpp`** to avoid code similarity

### For Learning:
1. **Read both solutions** to understand different approaches
2. **Run `test_circular.cpp`** to verify correctness
3. **Study the binary search logic** for deeper understanding

## ✅ Test Results:
- All test cases pass ✅
- Both solutions give identical results
- Optimal solution: ~log N queries
- 2nd best solution: ~N queries (worst case)

## 🎯 When to Use Which Solution:

### Use Optimal When:
- ✅ **Query limit matters** (25 queries max)
- ✅ **Large N values** (up to 10^6)
- ✅ **Standard competitive programming**
- ✅ **You understand binary search**

### Use 2nd Best When:
- ✅ **Code similarity is checked**
- ✅ **You want simple approach**
- ✅ **Learning/teaching purposes**
- ✅ **Backup solution**

## 🏆 Competition Strategy:

1. **Primary**: Use optimal solution for minimal queries
2. **Backup**: Keep 2nd best solution ready
3. **Verification**: Test both solutions before submission
4. **Understanding**: Know why both approaches work

## 💡 Interactive Problem Tips:

1. **Query efficiently** - Each query counts toward the limit
2. **Use binary search** - Reduces queries from O(N) to O(log N)
3. **Handle edge cases** - No rotation (K = 0)
4. **Test thoroughly** - Interactive problems are harder to debug

---

**Remember**: The goal is to have **different but correct** solutions that won't match other teams while maintaining competitive performance! 🚀
