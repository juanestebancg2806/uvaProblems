from sys import stdin
import sys
sys.setrecursionlimit(1000000)
INF = float('inf')

def solve(i,w):
    global memo
    ans = None
    if memo.get((i,w)) != None:
        #print(i,w)
        ans = memo[(i,w)]
    elif w < 0:
        ans = -INF
    elif w == 0 or i == len(P):
        ans = 0
    else:
        ans = max(0,solve(i+1,w),P[i]+solve(i+1,w-W[i]))
    memo[(i,w)] = ans
    return ans




def main():
    global P,W,memo
    T = int(stdin.readline().strip())
    for _ in range(T):
        N = int(stdin.readline().strip())
        P,W,memo,ans = list(),list(),{},0
        for _ in range(N):
            p,w = map(int,stdin.readline().strip().split())
            P.append(p);W.append(w)

        G = int(stdin.readline().strip())
        for _ in range(G):
            w = int(stdin.readline().strip())
            ans += solve(0,w)
        print(ans)
main()
