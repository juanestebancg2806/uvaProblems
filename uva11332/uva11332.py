from sys import stdin

def getSumDigits(n):
    ans = 0
    while n > 0:
        ans += n%10
        n //= 10
    return ans
        


def solve(n):
    ans = n
    while ans >= 10:
        ans = getSumDigits(ans)
    return ans

def main():
    n = int(stdin.readline().strip())
    while n != 0:
        ans = solve(n)
        print(ans)
        n = int(stdin.readline().strip())

main()
