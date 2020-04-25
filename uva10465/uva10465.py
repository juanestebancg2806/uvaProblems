from sys import stdin
import sys
sys.setrecursionlimit(10000000)
INF = float('inf')

def solve(t):
    global mem
    ans = None
    if t < 0:
        ans = -INF
    else:
        if mem[t] != -1:
            ans = mem[t]
        elif t == 0:
            ans = 0 
        else:
            ans = max(1+solve(t-m),1+solve(t-n))
        mem[t] = ans
    return ans
        
    



def main():
    global m,n,mem
    line = stdin.readline().strip()
    while len(line) and line != "" and line != "\n":
        m,n,t = map(int,line.split())
        mem,ok,i = [-1 for _ in range(t+1)],False,0
        ans = solve(t)
        if ans < 0:
            while i < t+1 and not ok:
                ok = mem[i] != -1
                i += 1
            print(solve(t-(i-1)),i-1)
        else:
            print(ans)
            
        #for i in range(t+1):
        #    if mem[i] != -1:
        #        print(i,end = " ")
        
        line = stdin.readline().strip()
        
main()      
