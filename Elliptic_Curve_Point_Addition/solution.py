import sys

def mod_pow(base, exp, mod):
    result = 1
    base = base % mod
    while exp > 0:
        if exp & 1:
            result = (result * base) % mod
        exp = exp >> 1
        base = (base * base) % mod
    return result

def mod_inverse(a, mod):
    return mod_pow(a, mod - 2, mod)

def add_points(a, b, p, x1, y1, x2, y2):
    if x1 == x2 and y1 == y2:
        if y1 == 0:
            print("POINT_AT_INFINITY")
            return
        
        slope = ((3 * x1 * x1 + a) % p * mod_inverse(2 * y1, p)) % p
        x3 = (slope * slope - 2 * x1) % p
        y3 = (slope * (x1 - x3) - y1) % p
        
        if x3 < 0:
            x3 += p
        if y3 < 0:
            y3 += p
        
        print(f"{x3} {y3}")
    else:
        if x1 == x2:
            print("POINT_AT_INFINITY")
            return
        
        slope = ((y2 - y1) % p * mod_inverse(x2 - x1, p)) % p
        x3 = (slope * slope - x1 - x2) % p
        y3 = (slope * (x1 - x3) - y1) % p
        
        if x3 < 0:
            x3 += p
        if y3 < 0:
            y3 += p
        
        print(f"{x3} {y3}")

def main():
    t = int(input())
    
    for _ in range(t):
        a, b, p, x1, y1, x2, y2 = map(int, input().split())
        add_points(a, b, p, x1, y1, x2, y2)

if __name__ == "__main__":
    main()

