from sys import stdin



def solve(nums):
    i = phi = ans = 0
    while i < len(nums):
        phi += nums[i]
        phi = max(phi,0)
        ans = max(phi,ans)
        i += 1
    return ans

def main():
    line = stdin.readline().strip()
    while(len(line) and line != "" and line != "\n"):
        nums = [int(x) for x in line.split()]
        print(solve(nums))
        line = stdin.readline().strip()

main()
