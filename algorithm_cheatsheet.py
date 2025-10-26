#!/usr/bin/env python3
"""
🏆 IEEE Xtreme Competition - Algorithm Cheatsheet
Quick reference for common competitive programming algorithms
"""

import sys
import math
import heapq
from collections import defaultdict, deque, Counter
from typing import List, Tuple, Optional
import bisect

# =============================================================================
# 🚀 SORTING ALGORITHMS
# =============================================================================

def quick_sort(arr):
    """Quick Sort - O(n log n) average, O(n²) worst case"""
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

def merge_sort(arr):
    """Merge Sort - O(n log n) guaranteed"""
    if len(arr) <= 1:
        return arr
    
    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])
    
    return merge(left, right)

def merge(left, right):
    result = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result.extend(left[i:])
    result.extend(right[j:])
    return result

def counting_sort(arr, max_val):
    """Counting Sort - O(n + k) where k is the range"""
    count = [0] * (max_val + 1)
    for num in arr:
        count[num] += 1
    
    result = []
    for i in range(max_val + 1):
        result.extend([i] * count[i])
    return result

# =============================================================================
# 🔍 SEARCHING ALGORITHMS
# =============================================================================

def binary_search(arr, target):
    """Binary Search - O(log n)"""
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

def lower_bound(arr, target):
    """Lower bound - first position where element >= target"""
    left, right = 0, len(arr)
    while left < right:
        mid = (left + right) // 2
        if arr[mid] < target:
            left = mid + 1
        else:
            right = mid
    return left

def upper_bound(arr, target):
    """Upper bound - first position where element > target"""
    left, right = 0, len(arr)
    while left < right:
        mid = (left + right) // 2
        if arr[mid] <= target:
            left = mid + 1
        else:
            right = mid
    return left

# =============================================================================
# 🌳 TREE ALGORITHMS
# =============================================================================

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def inorder_traversal(root):
    """Inorder traversal - Left, Root, Right"""
    result = []
    def dfs(node):
        if node:
            dfs(node.left)
            result.append(node.val)
            dfs(node.right)
    dfs(root)
    return result

def preorder_traversal(root):
    """Preorder traversal - Root, Left, Right"""
    result = []
    def dfs(node):
        if node:
            result.append(node.val)
            dfs(node.left)
            dfs(node.right)
    dfs(root)
    return result

def postorder_traversal(root):
    """Postorder traversal - Left, Right, Root"""
    result = []
    def dfs(node):
        if node:
            dfs(node.left)
            dfs(node.right)
            result.append(node.val)
    dfs(root)
    return result

def level_order_traversal(root):
    """Level order traversal (BFS)"""
    if not root:
        return []
    
    result = []
    queue = deque([root])
    
    while queue:
        level_size = len(queue)
        level = []
        for _ in range(level_size):
            node = queue.popleft()
            level.append(node.val)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        result.append(level)
    
    return result

def tree_height(root):
    """Calculate height of binary tree"""
    if not root:
        return 0
    return 1 + max(tree_height(root.left), tree_height(root.right))

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

# =============================================================================
# 🔗 LINKED LIST ALGORITHMS
# =============================================================================

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def reverse_linked_list(head):
    """Reverse linked list iteratively"""
    prev = None
    current = head
    
    while current:
        next_temp = current.next
        current.next = prev
        prev = current
        current = next_temp
    
    return prev

def detect_cycle(head):
    """Detect cycle in linked list using Floyd's algorithm"""
    if not head or not head.next:
        return False
    
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    
    return False

def find_middle_node(head):
    """Find middle node of linked list"""
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    return slow

def merge_two_sorted_lists(l1, l2):
    """Merge two sorted linked lists"""
    dummy = ListNode(0)
    current = dummy
    
    while l1 and l2:
        if l1.val <= l2.val:
            current.next = l1
            l1 = l1.next
        else:
            current.next = l2
            l2 = l2.next
        current = current.next
    
    current.next = l1 or l2
    return dummy.next

# =============================================================================
# 🎯 BACKTRACKING ALGORITHMS
# =============================================================================

def generate_permutations(nums):
    """Generate all permutations"""
    result = []
    
    def backtrack(current):
        if len(current) == len(nums):
            result.append(current[:])
            return
        
        for num in nums:
            if num not in current:
                current.append(num)
                backtrack(current)
                current.pop()
    
    backtrack([])
    return result

def generate_combinations(n, k):
    """Generate all combinations of k elements from 1 to n"""
    result = []
    
    def backtrack(start, current):
        if len(current) == k:
            result.append(current[:])
            return
        
        for i in range(start, n + 1):
            current.append(i)
            backtrack(i + 1, current)
            current.pop()
    
    backtrack(1, [])
    return result

def solve_n_queens(n):
    """Solve N-Queens problem"""
    result = []
    board = [['.' for _ in range(n)] for _ in range(n)]
    
    def is_safe(row, col):
        # Check column
        for i in range(row):
            if board[i][col] == 'Q':
                return False
        
        # Check diagonals
        for i, j in zip(range(row-1, -1, -1), range(col-1, -1, -1)):
            if board[i][j] == 'Q':
                return False
        
        for i, j in zip(range(row-1, -1, -1), range(col+1, n)):
            if board[i][j] == 'Q':
                return False
        
        return True
    
    def backtrack(row):
        if row == n:
            result.append([''.join(row) for row in board])
            return
        
        for col in range(n):
            if is_safe(row, col):
                board[row][col] = 'Q'
                backtrack(row + 1)
                board[row][col] = '.'
    
    backtrack(0)
    return result

# =============================================================================
# 🔢 NUMBER THEORY
# =============================================================================

def gcd(a, b):
    """Greatest Common Divisor using Euclidean algorithm"""
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    """Least Common Multiple"""
    return abs(a * b) // gcd(a, b)

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

def fibonacci(n):
    """Calculate nth Fibonacci number - O(n)"""
    if n <= 1:
        return n
    
    a, b = 0, 1
    for _ in range(2, n + 1):
        a, b = b, a + b
    return b

def fibonacci_matrix(n):
    """Calculate nth Fibonacci using matrix exponentiation - O(log n)"""
    def matrix_multiply(A, B):
        return [[A[0][0]*B[0][0] + A[0][1]*B[1][0], A[0][0]*B[0][1] + A[0][1]*B[1][1]],
                [A[1][0]*B[0][0] + A[1][1]*B[1][0], A[1][0]*B[0][1] + A[1][1]*B[1][1]]]
    
    def matrix_power(matrix, power):
        if power == 1:
            return matrix
        if power % 2 == 0:
            half = matrix_power(matrix, power // 2)
            return matrix_multiply(half, half)
        else:
            return matrix_multiply(matrix, matrix_power(matrix, power - 1))
    
    if n == 0:
        return 0
    
    base_matrix = [[1, 1], [1, 0]]
    result_matrix = matrix_power(base_matrix, n)
    return result_matrix[0][1]

# =============================================================================
# 🎨 GEOMETRY ALGORITHMS
# =============================================================================

def distance(p1, p2):
    """Calculate Euclidean distance between two points"""
    return math.sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)

def cross_product(o, a, b):
    """Cross product of vectors OA and OB"""
    return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])

def convex_hull(points):
    """Graham scan algorithm for convex hull"""
    if len(points) < 3:
        return points
    
    # Find bottom-most point
    start = min(points, key=lambda p: (p[1], p[0]))
    
    # Sort points by polar angle
    def polar_angle(p):
        return math.atan2(p[1] - start[1], p[0] - start[0])
    
    sorted_points = sorted(points, key=polar_angle)
    
    # Build convex hull
    hull = []
    for point in sorted_points:
        while len(hull) > 1 and cross_product(hull[-2], hull[-1], point) <= 0:
            hull.pop()
        hull.append(point)
    
    return hull

def point_in_polygon(point, polygon):
    """Ray casting algorithm to check if point is inside polygon"""
    x, y = point
    n = len(polygon)
    inside = False
    
    p1x, p1y = polygon[0]
    for i in range(1, n + 1):
        p2x, p2y = polygon[i % n]
        if y > min(p1y, p2y):
            if y <= max(p1y, p2y):
                if x <= max(p1x, p2x):
                    if p1y != p2y:
                        xinters = (y - p1y) * (p2x - p1x) / (p2y - p1y) + p1x
                    if p1x == p2x or x <= xinters:
                        inside = not inside
        p1x, p1y = p2x, p2y
    
    return inside

# =============================================================================
# 🚀 UTILITY FUNCTIONS
# =============================================================================

def read_int():
    """Fast integer input"""
    return int(sys.stdin.readline().strip())

def read_ints():
    """Fast integer array input"""
    return list(map(int, sys.stdin.readline().strip().split()))

def read_string():
    """Fast string input"""
    return sys.stdin.readline().strip()

def print_array(arr, separator=' '):
    """Print array with custom separator"""
    print(separator.join(map(str, arr)))

def flatten_2d(arr):
    """Flatten 2D array"""
    return [item for sublist in arr for item in sublist]

def transpose_matrix(matrix):
    """Transpose 2D matrix"""
    return list(zip(*matrix))

def rotate_matrix_90_clockwise(matrix):
    """Rotate matrix 90 degrees clockwise"""
    return [list(row) for row in zip(*matrix[::-1])]

def is_palindrome(s):
    """Check if string is palindrome"""
    return s == s[::-1]

def count_substrings(s, pattern):
    """Count occurrences of pattern in string"""
    count = 0
    start = 0
    while True:
        pos = s.find(pattern, start)
        if pos == -1:
            break
        count += 1
        start = pos + 1
    return count

# =============================================================================
# 🎯 COMPETITIVE PROGRAMMING SHORTCUTS
# =============================================================================

# Common imports for competitive programming
# import sys
# import math
# import heapq
# from collections import defaultdict, deque, Counter
# from typing import List, Tuple, Optional
# import bisect

# Fast I/O setup
# input = sys.stdin.readline

# Common constants
MOD = 10**9 + 7
INF = float('inf')
NEG_INF = float('-inf')

# Common data structures
# defaultdict(int) - for counting
# deque() - for BFS and efficient append/pop from both ends
# heapq - for priority queue
# set() - for O(1) lookup
# Counter() - for frequency counting

# Common patterns
# Two pointers technique
# Sliding window
# Binary search on answer
# Meet in the middle
# Bit manipulation
# Coordinate compression

if __name__ == "__main__":
    print("🏆 IEEE Xtreme Competition Algorithm Cheatsheet")
    print("=" * 50)
    print("This file contains optimized algorithms for competitive programming.")
    print("Use the functions as needed for your solutions!")
    print()
    print("📚 Available categories:")
    print("- Sorting algorithms")
    print("- Searching algorithms") 
    print("- Tree algorithms")
    print("- Linked list algorithms")
    print("- Backtracking algorithms")
    print("- Number theory")
    print("- Geometry algorithms")
    print("- Utility functions")
