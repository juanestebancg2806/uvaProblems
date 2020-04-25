from sys import stdin
import sys
sys.setrecursionlimit(1000000000)

def solve(N,M,n):
    ans = None
    if mem[N][M][n] != -1:
        ans = mem[N][M][n]
    elif(N == 0 and M == 0 and n%D == 0):
        ans = 1
    elif(N == 0):
        ans = 0
    else:
        ans = solve(N-1,M,n)
        if(M-1 >= 0):
            ans += solve(N-1,M-1,(n+numbers[N-1])%D)
    mem[N][M][n] = ans
    return ans


def main():
    global numbers,D,mem
    N,Q = map(int,stdin.readline().strip().split())
    TC = 1
    while(not(N == 0 and Q == 0)):
        numbers = list()
        for _ in range(N):
            v = int(stdin.readline().strip())
            numbers.append(v)
        print("SET {0}:".format(TC))
        for QU in range(Q):
            D,M = map(int,stdin.readline().strip().split())
            mem = [[[-1 for _ in range(21)]for _ in range(11)] for _ in range(202)]
            print("QUERY {0}: {1}".format(QU+1,solve(N,M,0)))

        N,Q = map(int,stdin.readline().strip().split())
        TC += 1
        
main()
