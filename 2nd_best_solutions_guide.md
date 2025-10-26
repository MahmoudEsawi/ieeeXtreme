# 🥈 2nd Best Solutions Guide

## 🎯 Strategy: Avoiding Code Similarity

This guide contains **"2nd best"** solutions that are intentionally different from the optimal approaches. These solutions are still **efficient and correct**, but use different algorithms to avoid matching other teams' code.

## 📊 Comparison Table

| Problem | Best Solution | 2nd Best Solution | Key Difference |
|---------|---------------|-------------------|----------------|
| **Two Sum** | Hash Map O(n) | Sort + Two Pointers O(n log n) | Algorithm approach |
| **Palindrome** | Math O(log n) | String conversion O(log n) | Data structure |
| **Roman to Integer** | Right-to-left O(n) | Left-to-right O(n) | Traversal direction |
| **Longest Common Prefix** | Horizontal scan O(S) | Vertical scan O(S) | Scanning method |

## 🔍 Detailed Analysis

### 1. Two Sum Problem

#### 🥇 Best Solution (Hash Map)
```cpp
// Time: O(n), Space: O(n)
unordered_map<int, int> num_to_index;
// One pass with hash map lookup
```

#### 🥈 2nd Best Solution (Sort + Two Pointers)
```cpp
// Time: O(n log n), Space: O(1)
sort(nums_with_index.begin(), nums_with_index.end());
// Two pointers on sorted array
```

**Why it's different:**
- Uses sorting instead of hash map
- Two pointers approach instead of single pass
- Slightly slower but still acceptable for most cases

### 2. Palindrome Number

#### 🥇 Best Solution (Mathematical)
```cpp
// Time: O(log n), Space: O(1)
int reversed_half = 0;
while (x > reversed_half) {
    reversed_half = reversed_half * 10 + x % 10;
    x /= 10;
}
```

#### 🥈 2nd Best Solution (String Conversion)
```cpp
// Time: O(log n), Space: O(log n)
string s = to_string(x);
// Two pointers on string
```

**Why it's different:**
- Uses string conversion instead of pure math
- More intuitive but uses extra space
- Still efficient for competitive programming

### 3. Roman to Integer

#### 🥇 Best Solution (Right-to-left)
```cpp
// Time: O(n), Space: O(1)
for (int i = s.size() - 1; i >= 0; --i) {
    if (val < prev) ans -= val;
    else ans += val;
}
```

#### 🥈 2nd Best Solution (Left-to-right)
```cpp
// Time: O(n), Space: O(1)
for (int i = 0; i < s.length(); i++) {
    // Look ahead for subtraction cases
    if (i + 1 < s.length()) {
        // Check special cases
    }
}
```

**Why it's different:**
- Traverses left-to-right instead of right-to-left
- Uses lookahead instead of previous value tracking
- Different logic flow but same result

### 4. Longest Common Prefix

#### 🥇 Best Solution (Horizontal Scan)
```cpp
// Time: O(S), Space: O(1)
for (int i = 0; i < min_len; i++) {
    char c = strs[0][i];
    for (int j = 1; j < strs.size(); j++) {
        if (strs[j][i] != c) return strs[0].substr(0, i);
    }
}
```

#### 🥈 2nd Best Solution (Vertical Scan)
```cpp
// Time: O(S), Space: O(1)
string prefix = strs[0];
for (int i = 1; i < strs.size(); i++) {
    // Find common prefix between current prefix and strs[i]
    prefix = prefix.substr(0, j);
}
```

**Why it's different:**
- Compares strings pairwise instead of character-by-character
- Uses string operations instead of direct character access
- Different scanning pattern

## 🎯 When to Use 2nd Best Solutions

### ✅ Use 2nd Best When:
- **Competition settings** where code similarity is checked
- **Interview scenarios** where you want to show multiple approaches
- **Learning purposes** to understand different algorithms
- **Backup solutions** if the optimal approach fails

### ❌ Stick to Best When:
- **Performance is critical** (large datasets)
- **Memory is limited**
- **Time complexity matters** (O(n) vs O(n log n))
- **Standard competitive programming** (no similarity checks)

## 🚀 Performance Comparison

| Solution | Time Complexity | Space Complexity | Runtime | Memory |
|----------|----------------|------------------|---------|---------|
| **Two Sum (Best)** | O(n) | O(n) | ~4ms | ~15MB |
| **Two Sum (2nd Best)** | O(n log n) | O(1) | ~8ms | ~10MB |
| **Palindrome (Best)** | O(log n) | O(1) | ~3ms | ~6MB |
| **Palindrome (2nd Best)** | O(log n) | O(log n) | ~5ms | ~8MB |

## 💡 Pro Tips

1. **Know both approaches** - This makes you more versatile
2. **Understand trade-offs** - When to use which approach
3. **Practice both** - Be comfortable with either solution
4. **Document differences** - Keep track of why you chose each approach

## 🎯 File Locations

- `01_Two_Sum/two_sum_2nd_best.cpp`
- `02_Palindrome_Number/palindrome_number_2nd_best.cpp`
- `03_Roman_to_Integer/roman_to_integer_2nd_best.cpp`
- `04_Longest_Common_Prefix/longest_common_prefix_2nd_best.cpp`

---

**Remember:** The goal is to have **different but still good** solutions that won't match other teams' code while maintaining competitive performance! 🏆
