from sys import stdin
import sys
sys.setrecursionlimit(1000000000)

"""
wa
"""



def solve(i,_s):
    global s,ans,codes
    if i == len(s) and len(ans) < 100:
        ans.add(str(_s))
    else:
        scpy = ''
        while i < len(s) and len(ans) < 100:
            scpy += s[i]
            if codes.get(int(scpy)) != None:
                solve(i+1,_s+codes[int(scpy)])
            i += 1


def main():
    global ans,codes,s
    N,TC = int(stdin.readline().strip()),1
    while N != 0:
        ans,codes = set(),{}
        for _ in range(N):
            l,n = map(str,stdin.readline().strip().split())
            codes[int(n)] = l
        s = stdin.readline().strip()    
        solve(0,'')
        ans = list(ans)
        ans.sort()
        print("Case #{0}".format(TC))
        for i in range(len(ans)):
            print(ans[i],end = "" if i+1 == len(ans) else "\n")
        TC += 1
        N = int(stdin.readline().strip())
        if N != 0:
            print("\n")
        
    
main()
