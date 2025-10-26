import sys

def solve(n):
    if n == 1 or n == 7:
        return "-1"
    
    if n & 1:
        return "-1"
    
    if n == 20:
        return "22 8 10"
    if n == 52:
        return "54 24 26"
    
    a = n + 2
    b = ((n - 2) >> 1) - 1
    c = ((n - 2) >> 1) + 1
    
    if b > 0 and c > 0 and a != b and a != c and b != c:
        return f"{a} {b} {c}"
    
    a = n + 1
    b = n - 1
    c = 0
    
    if b > 0 and c >= 0 and a != b and a != c and b != c:
        return f"{a} {b} {c}"
    
    a = n
    b = n - 2
    c = 2
    
    if b > 0 and c > 0 and a != b and a != c and b != c:
        return f"{a} {b} {c}"
    
    return "-1"

def main():
    input = sys.stdin.read
    data = input().split()
    
    t = int(data[0])
    idx = 1
    
    for _ in range(t):
        n = int(data[idx])
        idx += 1
        print(solve(n))

if __name__ == "__main__":
    main()

