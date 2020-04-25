from sys import stdin
import sys

def solve(a):
    tmp,N = 1,len(a)
    ans = a[0] if N > 0 else 0
    for i in range(N):
        tmp = a[i]
        ans = max(ans,tmp)
        for j in range(i+1,N):
            tmp *= a[j]
            ans = max(ans,tmp)
    return ans
            
    

def main():
    line = stdin.readline().strip()
    while len(line) and line != "" and line != "\n":
        a = [int(x) for x in line.split()]
        a.pop()
        ans = solve(a)
        print(ans)
        line = stdin.readline().strip()

main()
