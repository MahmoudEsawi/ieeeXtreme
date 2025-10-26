def solve():
    n = int(input())
    nums = list(map(int, input().split()))
    target = int(input())
    
    num_to_index = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in num_to_index:
            print(num_to_index[complement], i)
            return
        num_to_index[num] = i
    
    print(-1, -1)

if __name__ == "__main__":
    solve()
