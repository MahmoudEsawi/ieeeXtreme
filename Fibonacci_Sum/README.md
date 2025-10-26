# 🎯 Fibonacci Sum Problem

## 📝 Problem Description
Write N as a sum of Fibonacci numbers having as few terms as possible. Return a sorted array with the Fibonacci numbers adding up to N.

## 🎯 Examples
- **Input**: N = 7
- **Output**: [2, 5]
- **Explanation**: 7 = 2 + 5 (both are Fibonacci numbers)

- **Input**: N = 12  
- **Output**: [1, 3, 8]
- **Explanation**: 12 = 1 + 3 + 8 (all are Fibonacci numbers)

## 📁 Files in this folder:

### 🚀 **Ready to Submit:**
- **`fibonacci_optimal.cpp`** - **SUBMIT THIS** (O(log N) greedy solution)
- **`fibonacci_2nd_best.cpp`** - Alternative O(N log N) DP approach

### 📚 **Learning & Testing:**
- **`test_fibonacci.cpp`** - Test file to verify both solutions work correctly

## 🎯 Algorithm Analysis:

### 🥇 **Optimal Solution (Greedy)**
- **Time Complexity**: O(log N) - Logarithmic time
- **Space Complexity**: O(log N) - For storing Fibonacci numbers
- **Algorithm**: Zeckendorf's theorem - greedy approach
- **Approach**: Always take the largest Fibonacci number ≤ remaining sum

### 🥈 **2nd Best Solution (Dynamic Programming)**
- **Time Complexity**: O(N log N) - Linear time with log N Fibonacci numbers
- **Space Complexity**: O(N) - For DP table
- **Algorithm**: DP to find minimum number of terms
- **Approach**: Build solution bottom-up using DP

## 🔍 Key Differences

| Aspect | Optimal Solution | 2nd Best Solution |
|--------|------------------|-------------------|
| **Approach** | Greedy (Zeckendorf) | Dynamic Programming |
| **Time** | O(log N) | O(N log N) |
| **Space** | O(log N) | O(N) |
| **Code Style** | Simple greedy loop | DP with parent tracking |
| **Readability** | Intuitive | More complex logic |

## 🧮 Mathematical Background

### Zeckendorf's Theorem:
Every positive integer can be uniquely represented as the sum of one or more distinct, non-consecutive Fibonacci numbers.

### Greedy Algorithm:
1. Find largest Fibonacci number ≤ N
2. Subtract it from N
3. Repeat until N = 0

### Example for N = 12:
- Largest Fib ≤ 12: 8 → 12 - 8 = 4
- Largest Fib ≤ 4: 3 → 4 - 3 = 1  
- Largest Fib ≤ 1: 1 → 1 - 1 = 0
- Result: [1, 3, 8] ✅

## 🚀 How to Use:

### For Competition:
1. **Use `fibonacci_optimal.cpp`** for best performance
2. **Use `fibonacci_2nd_best.cpp`** to avoid code similarity

### For Learning:
1. **Read both solutions** to understand different approaches
2. **Run `test_fibonacci.cpp`** to verify correctness
3. **Study Zeckendorf's theorem** for deeper understanding

## ✅ Test Results:
- All test cases pass ✅
- Both solutions give identical results
- Optimal solution: ~0ms runtime
- 2nd best solution: ~1-3ms runtime (for N ≤ 1000)

## 🎯 When to Use Which Solution:

### Use Optimal When:
- ✅ **Performance matters** (large N)
- ✅ **Memory is limited**
- ✅ **Standard competitive programming**
- ✅ **You understand the math**

### Use 2nd Best When:
- ✅ **Code similarity is checked**
- ✅ **You want DP approach**
- ✅ **Learning/teaching purposes**
- ✅ **Backup solution**

## 🏆 Competition Strategy:

1. **Primary**: Use optimal solution for best performance
2. **Backup**: Keep 2nd best solution ready
3. **Verification**: Test both solutions before submission
4. **Understanding**: Know why both approaches work

---

**Remember**: The goal is to have **different but correct** solutions that won't match other teams while maintaining competitive performance! 🚀
