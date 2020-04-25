from sys import stdin
import sys
sys.setrecursionlimit(100000000)


def solve(x,y,n,r,k):
    global mem
    ans = None
    if mem.get((x,y,n,r,k)) != None:
        ans = mem[(x,y,n,r,k)]
    elif x > n or y < 0 or r < 0:
        ans = 0
    elif x == n and y == 0 and r == 0:
        ans = 1
    else:
        ans = solve(x+1,y-1,n,r,k) #go down
        if(y+1 == k):
            ans += (solve(x+2,y,n,r-1,k) + solve(x+2,y+2,n,r,k))
        else:
            ans += solve(x+1,y+1,n,r,k)
    mem[(x,y,n,r,k)] = ans
    return ans
        

def main():
    global mem
    line,mem = stdin.readline().strip(),{}
    while len(line) and line != "" and line != "\n":
        n,r,k = map(int,line.split())
        print(solve(0,0,2*n,r,k))
        line = stdin.readline().strip()
    
main()
