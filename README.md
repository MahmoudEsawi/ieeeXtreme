<div align="center">

# 🏆 IEEE Xtreme Competition - Solutions Repository

### Comprehensive Solutions for Competitive Programming Problems

[![IEEE](https://img.shields.io/badge/IEEE-00629B?style=for-the-badge&logo=ieee&logoColor=white)](https://www.ieee.org)
[![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)](https://www.python.org/)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](LICENSE)

<img src="https://capsule-render.vercel.app/api?type=waving&color=gradient&height=120&section=header&text=IEEE%20Xtreme%20Solutions&fontSize=42&fontAlignY=30&animation=twinkling&fontColor=ffffff"/>

</div>

---

## 📖 About This Repository

This repository contains **optimized solutions** for competitive programming problems, specifically designed for **IEEE Xtreme** competitions and other programming contests. Each solution is crafted with performance, clarity, and correctness in mind.

### 🎯 Key Features

- ✅ **31+ Problem Solutions** - Complete solutions for various competitive programming challenges
- ✅ **Multiple Languages** - Solutions in C++ and Python
- ✅ **Optimized Performance** - All solutions aimed at maximum speed and efficiency
- ✅ **Clean & Explained** - Both submission-ready and learning-friendly versions
- ✅ **Test Cases Included** - Comprehensive test suites for verification
- ✅ **Competition Templates** - Ready-to-use templates for fast coding

---

## 📁 Repository Structure

```
ieeeXtreme/
├── 📂 Problem Solutions (01-31)
│   ├── 01_Two_Sum/
│   ├── 02_Palindrome_Number/
│   ├── 03_Roman_to_Integer/
│   ├── ...
│   └── 31_Dominoes/
│
├── 📂 Special Problems
│   ├── Binary_Matrix_Change/
│   ├── Bitonic_Sequences/
│   ├── Elliptic_Curve_Point_Addition/
│   ├── Fibonacci_Sum/
│   └── ...
│
├── 📄 Templates & Resources
│   ├── cpp_template.cpp          # C++ template with STL optimizations
│   ├── algorithm_cheatsheet.py   # Quick reference for algorithms
│   ├── utility_functions.py      # Essential utility functions
│   └── quick_reference.py        # Quick copy-paste snippets
│
└── 📚 Documentation
    ├── README.md                  # This file
    ├── optimization_guide.md     # Performance optimization tips
    └── 2nd_best_solutions_guide.md
```

---

## 🚀 Quick Start

### For Competition Use:

1. **Browse Problems**: Navigate to the problem folder (e.g., `01_Two_Sum/`)
2. **Copy Solution**: Use the `*_SUBMIT.cpp` or `*_clean.cpp` file
3. **Submit**: Ready to paste into online judge!

### For Learning:

1. **Read README**: Each problem folder has a detailed README
2. **Study Solutions**: Check `*_EXPLAINED.cpp` files with comments
3. **Run Tests**: Execute test files to verify understanding

### Example:

```bash
# Navigate to a problem
cd 01_Two_Sum/

# View the problem description
cat README.md

# Copy clean solution for submission
cat two_sum_clean.cpp

# Run tests
g++ -o test test_two_sum_cpp.cpp && ./test
```

---

## 📊 Problem Categories

### 📝 **Basic Algorithms**
- Two Sum, Palindrome Number
- Roman to Integer, Longest Common Prefix
- Array Intersection, Anagrams

### 🔢 **Mathematical**
- Median of Two Sorted Arrays
- 3 Divisible Pairs, Odd Divisor Count
- Bit Count, Fibonacci Sum

### 🔄 **String Processing**
- Longest Substring Without Repeating Characters
- Longest Palindromic Substring
- Regular Expression Matching
- Word Permutation, Look and Say

### 🎯 **Dynamic Programming**
- Longest Balanced Subarray
- Generate Combinations
- Generate Parentheses
- Optimal Digits Removal

### 🌳 **Data Structures**
- Add Two Numbers (Linked Lists)
- Closest Pair
- Contained Intervals
- Previous Permutation

### 🎮 **Competition Problems**
- Pokemon Evolution
- Donkey Paradox
- Matrix Rotations
- Four Xtremes
- Shailesh Triplet

---

## 🛠️ Technologies Used

<div align="center">

![C++](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=c%2B%2B&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?style=flat-square&logo=python&logoColor=white)
![STL](https://img.shields.io/badge/STL-00599C?style=flat-square&logo=c%2B%2B&logoColor=white)
![Competitive](https://img.shields.io/badge/Competitive%20Programming-Red?style=flat-square)

</div>

---

## ⚡ Performance Optimization

### Key Principles:

1. **Fast I/O**: Always use `ios_base::sync_with_stdio(false)` and `cin.tie(NULL)`
2. **Optimal Algorithms**: Choose algorithms with best time/space complexity
3. **Memory Efficiency**: Minimize unnecessary allocations
4. **Direct Access**: Use arrays instead of maps when possible
5. **Loop Optimization**: Unroll loops for fixed iterations

### Example Optimization:

```cpp
// Fast I/O Setup
ios_base::sync_with_stdio(false);
cin.tie(NULL);

// Direct array access instead of map
int roman[256] = {0};
roman['I'] = 1;
roman['V'] = 5;
// ...

// Optimized loops
for (int i = 0; i < n; ++i) {
    // Direct access, no function calls
}
```

📖 **See [optimization_guide.md](optimization_guide.md) for detailed tips**

---

## 📂 Problem Organization

Each problem folder typically contains:

| File Type | Description | Use Case |
|:---:|:---|:---|
| `*_SUBMIT.cpp` | Clean solution, ready to submit | **Competition** |
| `*_EXPLAINED.cpp` | Solution with detailed comments | **Learning** |
| `*_clean.cpp` | Alternative clean version | **Competition** |
| `test_*.cpp` | Test cases and verification | **Testing** |
| `README.md` | Problem description & analysis | **Documentation** |

---

## 🎯 Solution Types

### ✅ **Submission-Ready Solutions**
- No comments (or minimal)
- Fast I/O optimized
- Proper formatting for online judges
- Edge cases handled

### 📚 **Educational Solutions**
- Detailed comments
- Step-by-step explanations
- Algorithm analysis
- Complexity breakdown

### 🧪 **Test Solutions**
- Comprehensive test cases
- Edge case coverage
- Performance benchmarks
- Verification tools

---

## 📖 Usage Examples

### Example 1: Two Sum Problem

```cpp
// Clean solution ready for submission
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    unordered_map<int, int> map;
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (map.find(target - nums[i]) != map.end()) {
            cout << map[target - nums[i]] << " " << i << endl;
            return 0;
        }
        map[nums[i]] = i;
    }
    return 0;
}
```

### Example 2: Problem Navigation

```bash
# List all problems
ls -d */ | grep -E "^[0-9]"

# View problem structure
cd 01_Two_Sum/
ls -la

# Read problem description
cat README.md

# Compile and test
g++ -std=c++17 -O2 test_two_sum_cpp.cpp -o test
./test
```

---

## 🏆 Competition Tips

### Before Competition:
1. ✅ Review templates (`cpp_template.cpp`)
2. ✅ Practice with test cases
3. ✅ Familiarize with common patterns
4. ✅ Set up fast I/O macros

### During Competition:
1. ⚡ Copy fast I/O setup first
2. ⚡ Read problem carefully
3. ⚡ Think of edge cases
4. ⚡ Test with sample inputs
5. ⚡ Optimize before final submission

### Common Pitfalls to Avoid:
- ❌ Slow I/O (forgot fast I/O setup)
- ❌ Wrong complexity (TLE on large inputs)
- ❌ Off-by-one errors
- ❌ Integer overflow
- ❌ Wrong data structure choice

---

## 📚 Resources & Templates

### Templates Available:
- **`cpp_template.cpp`** - Complete C++ template with all optimizations
- **`algorithm_cheatsheet.py`** - Quick reference for algorithms
- **`utility_functions.py`** - Helper functions
- **`quick_reference.py`** - Code snippets

### Useful Algorithms Included:
- Two Pointers
- Sliding Window
- Dynamic Programming
- Graph Algorithms
- String Matching
- Mathematical Algorithms

---

## 🎓 Learning Path

### Beginner:
1. Start with `01_Two_Sum` - Simple hash map problem
2. Try `02_Palindrome_Number` - String manipulation
3. Practice with `03_Roman_to_Integer` - Character mapping

### Intermediate:
1. `05_Add_Two_Numbers` - Linked lists
2. `07_Median_of_Two_Sorted_Arrays` - Binary search
3. `08_Longest_Palindromic_Substring` - Dynamic programming

### Advanced:
1. `09_Regular_Expression_Matching` - Complex DP
2. `Bitonic_Sequences` - Advanced math
3. `Shailesh_Triplet` - Competition problems

---

## 🤝 Contributing

Contributions are welcome! If you have:
- ✅ Better solutions
- ✅ More test cases
- ✅ Performance improvements
- ✅ Documentation fixes

Please feel free to submit a Pull Request!

---

## 📄 License

This project is licensed under the MIT License - see the LICENSE file for details.

---

## 🌟 Acknowledgments

- **IEEE Xtreme** for hosting amazing competitions
- **Competitive Programming Community** for inspiration
- **All Contributors** who helped improve solutions

---

## 📞 Contact & Support

- **Repository**: [GitHub](https://github.com/MahmoudEsawi/ieeeXtreme)
- **Issues**: Report bugs or request features via GitHub Issues
- **IEEE**: [IEEE.org](https://www.ieee.org)

---

<div align="center">

### 🏆 **Good luck with your IEEE Xtreme competition!**

*This repository is designed to help you succeed in competitive programming with optimal solutions and comprehensive explanations.*

![Profile Views](https://komarev.com/ghpvc/?username=MahmoudEsawi&color=00629B&style=flat-square&label=Repository+Views)

<img src="https://capsule-render.vercel.app/api?type=waving&color=gradient&height=120&section=footer&animation=twinkling"/>

</div>
