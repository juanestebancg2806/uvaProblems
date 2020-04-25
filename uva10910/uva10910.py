from sys import stdin
import sys
sys.setrecursionlimit(10000000)


def f(N,T,P):
    global mem
    ans,i = None,P
    if mem[N][T][P] != -1:
        ans = mem[N][T][P]
    elif N == 1 and T >= P:
        ans = 1
    elif N == 0 and T == 0:
        ans = 1
    elif N == 0 or (N != 0 and T == 0):
        ans = 0
    else:
        ans = 0
        while i <= T:
            ans += f(N-1,T-i,P)
            i += 1
    mem[N][T][P] = ans
    return ans
            
        
        

def main():
    global mem,arr
    
    TC = int(stdin.readline().strip())
    mem = [[[-1 for _ in range(71)] for _ in range(71)] for _ in range(71)]
    for _ in range(TC):
        arr = []
        N,T,P = map(int,stdin.readline().strip().split())
        print(f(N,T,P))
        
main()
