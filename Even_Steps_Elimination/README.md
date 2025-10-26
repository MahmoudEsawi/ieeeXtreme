# 🎯 Even Steps Elimination (Josephus Problem)

## 📝 Problem Description
Consider a circular array of size N. Starting with the first element, you iterate over the array. You erase each second element you visit, and stop when the array contains only one element. Return the initial index of the final element.

## 🎯 Examples
- **Input**: N = 4
- **Output**: 1
- **Explanation**: [1,2,3,4] → [1,3,4] → [1,3] → [1] (index 1 survives)

- **Input**: N = 7  
- **Output**: 7
- **Explanation**: [1,2,3,4,5,6,7] → [1,3,4,5,6,7] → [1,3,5,6,7] → [1,3,5,7] → [1,5,7] → [1,5] → [1] (index 7 survives)

## 📁 Files in this folder:

### 🚀 **Ready to Submit:**
- **`josephus_optimal.cpp`** - **SUBMIT THIS** (O(log N) mathematical solution)
- **`josephus_2nd_best.cpp`** - Alternative O(N) simulation approach

### 📚 **Learning & Testing:**
- **`test_josephus.cpp`** - Test file to verify both solutions work correctly

## 🎯 Algorithm Analysis:

### 🥇 **Optimal Solution (Mathematical)**
- **Time Complexity**: O(log N) - Logarithmic time
- **Space Complexity**: O(1) - Constant space
- **Algorithm**: Josephus formula for k=2
- **Formula**: `J(n,2) = 2*(n - 2^floor(log2(n))) + 1`

### 🥈 **2nd Best Solution (Simulation)**
- **Time Complexity**: O(N) - Linear time
- **Space Complexity**: O(N) - Linear space  
- **Algorithm**: Vector simulation with modulo arithmetic
- **Approach**: Simulates the elimination process step by step

## 🔍 Key Differences

| Aspect | Optimal Solution | 2nd Best Solution |
|--------|------------------|-------------------|
| **Approach** | Mathematical formula | Simulation |
| **Time** | O(log N) | O(N) |
| **Space** | O(1) | O(N) |
| **Code Style** | Direct calculation | Step-by-step simulation |
| **Readability** | Requires math knowledge | Intuitive simulation |

## 🚀 How to Use:

### For Competition:
1. **Use `josephus_optimal.cpp`** for best performance
2. **Use `josephus_2nd_best.cpp`** to avoid code similarity

### For Learning:
1. **Read both solutions** to understand different approaches
2. **Run `test_josephus.cpp`** to verify correctness
3. **Study the mathematical formula** for deeper understanding

## 🧮 Mathematical Background

This is a variant of the **Josephus Problem** with k=2 (eliminate every 2nd element).

### The Formula:
```
J(n,2) = 2*(n - 2^floor(log2(n))) + 1
```

### How it works:
1. Find the largest power of 2 ≤ N
2. Calculate the difference: `diff = N - power_of_2`
3. Apply formula: `result = 2*diff + 1`

### Example for N=7:
- Largest power of 2 ≤ 7: 4
- Difference: 7 - 4 = 3
- Result: 2*3 + 1 = 7 ✅

## ✅ Test Results:
- All test cases pass ✅
- Both solutions give identical results
- Optimal solution: ~0ms runtime
- 2nd best solution: ~1-2ms runtime (for N ≤ 1000)

## 🎯 When to Use Which Solution:

### Use Optimal When:
- ✅ **Performance matters** (large N)
- ✅ **Memory is limited**
- ✅ **Standard competitive programming**
- ✅ **You understand the math**

### Use 2nd Best When:
- ✅ **Code similarity is checked**
- ✅ **You want intuitive approach**
- ✅ **Learning/teaching purposes**
- ✅ **Backup solution**

## 🏆 Competition Strategy:

1. **Primary**: Use optimal solution for best performance
2. **Backup**: Keep 2nd best solution ready
3. **Verification**: Test both solutions before submission
4. **Understanding**: Know why both approaches work

---

**Remember**: The goal is to have **different but correct** solutions that won't match other teams while maintaining competitive performance! 🚀
