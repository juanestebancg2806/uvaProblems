from sys import stdin
import sys
sys.setrecursionlimit(10000000)
INF = float('inf')

def solve(i,r):
    global mem
    ans = None
    #if mem.get((i,r)) != None:
    #    ans = mem[(i,r)]
    if i == N:
        ans = 0
    else:
        ans = solve(i+1,r)
        if W[i] <= r:
            ans = max(ans,1+solve(i+1,min(r-W[i],M[i]-W[i])))
    mem[(i,r)] = ans
    return ans
    

def main():
    global W,M,mem,N
    line,W_M,W,M,mem = stdin.readline().strip(),list(),list(),list(),dict()
    while len(line) and line != "" and line != "\n":
        w,m = map(int,line.split())
        W_M.append((w,m))
        line = stdin.readline().strip()
    W_M.sort(key = lambda x: -(x[1]-x[0]))
    for w,m in W_M:
        W.append(w);M.append(m)
    print(W_M)
    N = len(W)
    print(solve(0,INF))
    
main()
