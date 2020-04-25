from sys import stdin
import sys
sys.setrecursionlimit(100000000)

def solve(i,n):
    global ok
    if n == 0:
        ok = True
    elif n > 0 and not ok and i < len(W):
        solve(i+1,n-W[i])
        solve(i+1,n)
        


def main():
    global ok,W
    tc = int(stdin.readline().strip())
    for _ in range(tc):
        W,ok = [int(x) for x in stdin.readline().strip().split()],False
        tot = sum(W)
        if tot%2 == 0:
            solve(0,tot//2)
        ans = "NO" if not ok  else "YES"
        print(ans)

main()
