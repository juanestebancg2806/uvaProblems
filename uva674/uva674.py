from sys import stdin
import sys
sys.setrecursionlimit(100000000)

coins = [1,5,10,25,50]
mem = [[-1 for _ in range(7500)] for _ in range(5)]


def solve(i,n):
    global mem
    ans = None
    if i < 5 and mem[i][n] != -1:
        ans = mem[i][n]
    elif n == 0:
        ans = 1
    elif i == 5 and n != 0:
        ans = 0
    else:
        ans = 0
        if coins[i] <= n:
            ans += solve(i,n-coins[i])
        ans += solve(i+1,n)
    if i < 5:
        mem[i][n] = ans
    return ans
        

def main():
    line = stdin.readline().strip()
    ans = [solve(0,i) for i in range(7500)]
    while len(line) and line != "" and line != "\n":
        N = int(line)
        print(ans[N])
        line = stdin.readline().strip()
main()
