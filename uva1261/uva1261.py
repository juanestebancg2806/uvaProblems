from sys import stdin
import sys
sys.setrecursionlimit(100000000)


def strPop(s,i,j):
    ans,N = [],len(s)
    for k in range(N):
        if not(i <= k <= j-1):
            ans.append(s[k])
    return ans
    
    

def solve(s):
    global mem
    i,N,cnt,j,_s = 0,len(s),0,0,str(s)
    ans = len(s) == 0
    if(mem.get(_s) != None):
        ans = mem[_s]
    else:
        while i < N and not ans:
            cnt,j = 0,i
            while i < N and s[i] == 'b': cnt,i = cnt+1,i+1
            if cnt > 1 and not ans:
                ans = solve(strPop(s,j,j+(cnt)))
            cnt,j = 0,i
            while i < N and s[i] == 'a': cnt,i = cnt+1,i+1
            if cnt > 1 and not ans:
               ans = solve(strPop(s,j,j+(cnt)))
        mem[_s] = ans
    return ans

def main():
    global mem
    TC,mem = int(stdin.readline().strip()),{}
    for _ in range(TC):
        s = stdin.readline().strip()
        s = [c for c in s]
        print(1 if solve(s) else 0)
        
main()
