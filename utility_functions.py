#!/usr/bin/env python3
"""
🏆 IEEE Xtreme Competition - Utility Functions
Essential helper functions for competitive programming
"""

import sys
import math
import heapq
import random
import string
from collections import defaultdict, deque, Counter
from typing import List, Tuple, Optional, Dict, Set
import bisect
from itertools import permutations, combinations, product

# =============================================================================
# 🚀 FAST I/O UTILITIES
# =============================================================================

def fast_input():
    """Fast input for competitive programming"""
    return sys.stdin.readline().strip()

def fast_output(*args, **kwargs):
    """Fast output for competitive programming"""
    print(*args, **kwargs, flush=True)

def read_int():
    """Read single integer"""
    return int(fast_input())

def read_ints():
    """Read list of integers"""
    return list(map(int, fast_input().split()))

def read_float():
    """Read single float"""
    return float(fast_input())

def read_floats():
    """Read list of floats"""
    return list(map(float, fast_input().split()))

def read_string():
    """Read single string"""
    return fast_input()

def read_strings():
    """Read list of strings"""
    return fast_input().split()

def read_matrix(rows, cols):
    """Read 2D matrix"""
    return [read_ints() for _ in range(rows)]

def read_graph_adjacency_list(n, m, directed=False):
    """Read graph as adjacency list"""
    graph = defaultdict(list)
    for _ in range(m):
        u, v = read_ints()
        graph[u].append(v)
        if not directed:
            graph[v].append(u)
    return graph

def read_graph_edge_list(m):
    """Read graph as edge list"""
    edges = []
    for _ in range(m):
        u, v, w = read_ints()  # weight is optional
        edges.append((u, v, w))
    return edges

# =============================================================================
# 🔢 MATHEMATICAL UTILITIES
# =============================================================================

def is_prime(n):
    """Check if number is prime - O(√n)"""
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            return False
    return True

def sieve_of_eratosthenes(n):
    """Generate all primes up to n - O(n log log n)"""
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    
    for i in range(2, int(math.sqrt(n)) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
    
    return [i for i in range(2, n + 1) if is_prime[i]]

def prime_factors(n):
    """Get prime factors of a number"""
    factors = []
    while n % 2 == 0:
        factors.append(2)
        n //= 2
    
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        while n % i == 0:
            factors.append(i)
            n //= i
    
    if n > 2:
        factors.append(n)
    
    return factors

def gcd(a, b):
    """Greatest Common Divisor"""
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    """Least Common Multiple"""
    return abs(a * b) // gcd(a, b)

def extended_gcd(a, b):
    """Extended Euclidean Algorithm"""
    if a == 0:
        return b, 0, 1
    gcd, x1, y1 = extended_gcd(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    return gcd, x, y

def mod_inverse(a, m):
    """Modular inverse using extended Euclidean algorithm"""
    gcd, x, y = extended_gcd(a, m)
    if gcd != 1:
        raise ValueError("Modular inverse doesn't exist")
    return (x % m + m) % m

def fast_power(base, exp, mod=None):
    """Fast exponentiation - O(log exp)"""
    result = 1
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod if mod else result * base
        base = (base * base) % mod if mod else base * base
        exp //= 2
    return result

def factorial(n, mod=None):
    """Calculate factorial with optional modulo"""
    result = 1
    for i in range(1, n + 1):
        result = (result * i) % mod if mod else result * i
    return result

def nCr(n, r, mod=None):
    """Calculate nCr (combinations)"""
    if r > n or r < 0:
        return 0
    if r == 0 or r == n:
        return 1
    
    # Use the property: nCr = nC(n-r)
    if r > n - r:
        r = n - r
    
    result = 1
    for i in range(r):
        result = (result * (n - i)) // (i + 1)
        if mod:
            result %= mod
    
    return result

def fibonacci(n, mod=None):
    """Calculate nth Fibonacci number"""
    if n <= 1:
        return n
    
    a, b = 0, 1
    for _ in range(2, n + 1):
        a, b = b, (a + b) % mod if mod else a + b
    return b

# =============================================================================
# 🎯 ARRAY UTILITIES
# =============================================================================

def prefix_sum(arr):
    """Calculate prefix sum array"""
    prefix = [0]
    for num in arr:
        prefix.append(prefix[-1] + num)
    return prefix

def suffix_sum(arr):
    """Calculate suffix sum array"""
    suffix = [0] * (len(arr) + 1)
    for i in range(len(arr) - 1, -1, -1):
        suffix[i] = suffix[i + 1] + arr[i]
    return suffix

def prefix_max(arr):
    """Calculate prefix maximum array"""
    prefix = [arr[0]]
    for i in range(1, len(arr)):
        prefix.append(max(prefix[-1], arr[i]))
    return prefix

def prefix_min(arr):
    """Calculate prefix minimum array"""
    prefix = [arr[0]]
    for i in range(1, len(arr)):
        prefix.append(min(prefix[-1], arr[i]))
    return prefix

def find_peaks(arr):
    """Find all peaks in array (local maxima)"""
    peaks = []
    for i in range(1, len(arr) - 1):
        if arr[i] > arr[i-1] and arr[i] > arr[i+1]:
            peaks.append(i)
    return peaks

def find_valleys(arr):
    """Find all valleys in array (local minima)"""
    valleys = []
    for i in range(1, len(arr) - 1):
        if arr[i] < arr[i-1] and arr[i] < arr[i+1]:
            valleys.append(i)
    return valleys

def longest_increasing_subsequence(arr):
    """Find length of longest increasing subsequence - O(n log n)"""
    tails = []
    for num in arr:
        pos = bisect.bisect_left(tails, num)
        if pos == len(tails):
            tails.append(num)
        else:
            tails[pos] = num
    return len(tails)

def longest_decreasing_subsequence(arr):
    """Find length of longest decreasing subsequence - O(n log n)"""
    # Reverse the array and find LIS
    return longest_increasing_subsequence(arr[::-1])

def kadane_algorithm(arr):
    """Kadane's algorithm for maximum subarray sum"""
    max_sum = current_sum = arr[0]
    for i in range(1, len(arr)):
        current_sum = max(arr[i], current_sum + arr[i])
        max_sum = max(max_sum, current_sum)
    return max_sum

def sliding_window_maximum(arr, k):
    """Find maximum in each sliding window of size k"""
    from collections import deque
    dq = deque()
    result = []
    
    for i in range(len(arr)):
        # Remove elements outside current window
        while dq and dq[0] <= i - k:
            dq.popleft()
        
        # Remove elements smaller than current element
        while dq and arr[dq[-1]] <= arr[i]:
            dq.pop()
        
        dq.append(i)
        
        # Add maximum of current window
        if i >= k - 1:
            result.append(arr[dq[0]])
    
    return result

# =============================================================================
# 🎨 STRING UTILITIES
# =============================================================================

def is_palindrome(s):
    """Check if string is palindrome"""
    return s == s[::-1]

def longest_palindromic_substring(s):
    """Find longest palindromic substring using Manacher's algorithm"""
    # Transform string
    t = '#' + '#'.join(s) + '#'
    n = len(t)
    p = [0] * n
    center = right = 0
    
    for i in range(n):
        if i < right:
            p[i] = min(right - i, p[2 * center - i])
        
        while (i + p[i] + 1 < n and i - p[i] - 1 >= 0 and 
               t[i + p[i] + 1] == t[i - p[i] - 1]):
            p[i] += 1
        
        if i + p[i] > right:
            center = i
            right = i + p[i]
    
    max_len = max(p)
    center_idx = p.index(max_len)
    start = (center_idx - max_len) // 2
    return s[start:start + max_len]

def kmp_search(text, pattern):
    """KMP string matching algorithm"""
    def build_lps(pattern):
        lps = [0] * len(pattern)
        length = 0
        i = 1
        
        while i < len(pattern):
            if pattern[i] == pattern[length]:
                length += 1
                lps[i] = length
                i += 1
            else:
                if length != 0:
                    length = lps[length - 1]
                else:
                    lps[i] = 0
                    i += 1
        return lps
    
    lps = build_lps(pattern)
    i = j = 0
    matches = []
    
    while i < len(text):
        if pattern[j] == text[i]:
            i += 1
            j += 1
        
        if j == len(pattern):
            matches.append(i - j)
            j = lps[j - 1]
        elif i < len(text) and pattern[j] != text[i]:
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1
    
    return matches

def z_algorithm(s):
    """Z-algorithm for string matching"""
    n = len(s)
    z = [0] * n
    l = r = 0
    
    for i in range(1, n):
        if i <= r:
            z[i] = min(r - i + 1, z[i - l])
        
        while i + z[i] < n and s[z[i]] == s[i + z[i]]:
            z[i] += 1
        
        if i + z[i] - 1 > r:
            l = i
            r = i + z[i] - 1
    
    return z

def rabin_karp(text, pattern, base=256, mod=10**9+7):
    """Rabin-Karp string matching algorithm"""
    n, m = len(text), len(pattern)
    if m > n:
        return []
    
    # Calculate hash of pattern and first window of text
    pattern_hash = 0
    text_hash = 0
    h = 1
    
    for i in range(m):
        pattern_hash = (pattern_hash * base + ord(pattern[i])) % mod
        text_hash = (text_hash * base + ord(text[i])) % mod
    
    # Calculate h = base^(m-1) % mod
    for i in range(m - 1):
        h = (h * base) % mod
    
    matches = []
    for i in range(n - m + 1):
        if pattern_hash == text_hash:
            if text[i:i+m] == pattern:
                matches.append(i)
        
        if i < n - m:
            text_hash = (base * (text_hash - ord(text[i]) * h) + ord(text[i + m])) % mod
            if text_hash < 0:
                text_hash += mod
    
    return matches

# =============================================================================
# 🌳 TREE UTILITIES
# =============================================================================

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def tree_height(root):
    """Calculate height of binary tree"""
    if not root:
        return 0
    return 1 + max(tree_height(root.left), tree_height(root.right))

def tree_diameter(root):
    """Calculate diameter of binary tree"""
    def dfs(node):
        if not node:
            return 0
        
        left_height = dfs(node.left)
        right_height = dfs(node.right)
        
        # Update diameter
        tree_diameter.max_diameter = max(tree_diameter.max_diameter, 
                                        left_height + right_height)
        
        return 1 + max(left_height, right_height)
    
    tree_diameter.max_diameter = 0
    dfs(root)
    return tree_diameter.max_diameter

def is_balanced_tree(root):
    """Check if binary tree is height-balanced"""
    def check_height(node):
        if not node:
            return 0
        
        left_height = check_height(node.left)
        if left_height == -1:
            return -1
        
        right_height = check_height(node.right)
        if right_height == -1:
            return -1
        
        if abs(left_height - right_height) > 1:
            return -1
        
        return 1 + max(left_height, right_height)
    
    return check_height(root) != -1

def lowest_common_ancestor(root, p, q):
    """Find lowest common ancestor of two nodes"""
    if not root or root == p or root == q:
        return root
    
    left = lowest_common_ancestor(root.left, p, q)
    right = lowest_common_ancestor(root.right, p, q)
    
    if left and right:
        return root
    return left or right

# =============================================================================
# 🔗 GRAPH UTILITIES
# =============================================================================

def has_cycle_dfs(graph, visited, rec_stack, node):
    """Check if graph has cycle using DFS"""
    visited[node] = True
    rec_stack[node] = True
    
    for neighbor in graph[node]:
        if not visited[neighbor]:
            if has_cycle_dfs(graph, visited, rec_stack, neighbor):
                return True
        elif rec_stack[neighbor]:
            return True
    
    rec_stack[node] = False
    return False

def has_cycle(graph):
    """Check if directed graph has cycle"""
    n = len(graph)
    visited = [False] * n
    rec_stack = [False] * n
    
    for i in range(n):
        if not visited[i]:
            if has_cycle_dfs(graph, visited, rec_stack, i):
                return True
    return False

def topological_sort(graph):
    """Topological sort using Kahn's algorithm"""
    n = len(graph)
    in_degree = [0] * n
    
    for u in range(n):
        for v in graph[u]:
            in_degree[v] += 1
    
    queue = deque([u for u in range(n) if in_degree[u] == 0])
    result = []
    
    while queue:
        u = queue.popleft()
        result.append(u)
        
        for v in graph[u]:
            in_degree[v] -= 1
            if in_degree[v] == 0:
                queue.append(v)
    
    return result if len(result) == n else []

def strongly_connected_components(graph):
    """Find strongly connected components using Kosaraju's algorithm"""
    n = len(graph)
    visited = [False] * n
    order = []
    
    def dfs1(node):
        visited[node] = True
        for neighbor in graph[node]:
            if not visited[neighbor]:
                dfs1(neighbor)
        order.append(node)
    
    # First pass
    for i in range(n):
        if not visited[i]:
            dfs1(i)
    
    # Reverse graph
    reversed_graph = [[] for _ in range(n)]
    for u in range(n):
        for v in graph[u]:
            reversed_graph[v].append(u)
    
    # Second pass
    visited = [False] * n
    sccs = []
    
    def dfs2(node, component):
        visited[node] = True
        component.append(node)
        for neighbor in reversed_graph[node]:
            if not visited[neighbor]:
                dfs2(neighbor, component)
    
    for node in reversed(order):
        if not visited[node]:
            component = []
            dfs2(node, component)
            sccs.append(component)
    
    return sccs

# =============================================================================
# 🎯 BIT MANIPULATION UTILITIES
# =============================================================================

def count_set_bits(n):
    """Count number of set bits in binary representation"""
    count = 0
    while n:
        count += n & 1
        n >>= 1
    return count

def is_power_of_two(n):
    """Check if number is power of 2"""
    return n > 0 and (n & (n - 1)) == 0

def next_power_of_two(n):
    """Find next power of 2 greater than or equal to n"""
    if n == 0:
        return 1
    return 1 << (n - 1).bit_length()

def get_bit(n, i):
    """Get ith bit of number"""
    return (n >> i) & 1

def set_bit(n, i):
    """Set ith bit of number"""
    return n | (1 << i)

def clear_bit(n, i):
    """Clear ith bit of number"""
    return n & ~(1 << i)

def toggle_bit(n, i):
    """Toggle ith bit of number"""
    return n ^ (1 << i)

def lowest_set_bit(n):
    """Get position of lowest set bit"""
    return (n & -n).bit_length() - 1

def highest_set_bit(n):
    """Get position of highest set bit"""
    return n.bit_length() - 1

# =============================================================================
# 🎨 RANDOM UTILITIES
# =============================================================================

def generate_random_string(length, chars=string.ascii_letters + string.digits):
    """Generate random string of given length"""
    return ''.join(random.choice(chars) for _ in range(length))

def generate_random_array(n, min_val=1, max_val=100):
    """Generate random array of given size"""
    return [random.randint(min_val, max_val) for _ in range(n)]

def shuffle_array(arr):
    """Shuffle array in place"""
    random.shuffle(arr)
    return arr

def random_choice_weighted(choices, weights):
    """Random choice with weights"""
    return random.choices(choices, weights=weights)[0]

# =============================================================================
# 🚀 DEBUGGING UTILITIES
# =============================================================================

def debug_print(*args, **kwargs):
    """Debug print function"""
    print("DEBUG:", *args, **kwargs, file=sys.stderr)

def print_matrix(matrix, separator=' '):
    """Print 2D matrix"""
    for row in matrix:
        print(separator.join(map(str, row)))

def print_graph_adjacency_list(graph):
    """Print graph as adjacency list"""
    for node, neighbors in graph.items():
        print(f"{node}: {neighbors}")

def time_function(func, *args, **kwargs):
    """Time a function execution"""
    import time
    start = time.time()
    result = func(*args, **kwargs)
    end = time.time()
    print(f"Function {func.__name__} took {end - start:.6f} seconds")
    return result

if __name__ == "__main__":
    print("🏆 IEEE Xtreme Competition - Utility Functions")
    print("=" * 50)
    print("This file contains essential utility functions for competitive programming.")
    print("Import the functions you need for your solutions!")
    print()
    print("📚 Available categories:")
    print("- Fast I/O utilities")
    print("- Mathematical utilities")
    print("- Array utilities")
    print("- String utilities")
    print("- Tree utilities")
    print("- Graph utilities")
    print("- Bit manipulation utilities")
    print("- Random utilities")
    print("- Debugging utilities")
