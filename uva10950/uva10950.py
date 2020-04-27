from sys import stdin
import sys
sys.setrecursionlimit(1000000000)


def solve(i,_s):
    global codes,s,letters,cnt
    if i == len(s) and cnt < 100:
        print(_s)
        cnt += 1
    else:
        for k in range(26):
            _chr = chr(k+97)
            if _chr in letters:
                ok,scpy,j = True,'',i
                while j < len(s) and ok and cnt < 100:
                    scpy += s[j]
                    if codes.get(int(scpy)) != None and codes[int(scpy)] == _chr:
                        solve(j+1,_s+codes[int(scpy)])
                    j,ok = j+1,int(scpy) <= 99



def main():
    global codes,s,letters,cnt
    N,TC = int(stdin.readline().strip()),1
    while N :
        codes,letters = {},set()
        for _ in range(N):
            l,n = map(str,stdin.readline().strip().split())
            codes[int(n)] = l
            letters.add(l)
        s = stdin.readline().strip()    
        cnt = 0
        print("Case #{0}".format(TC))
        solve(0,'')
        TC += 1
        N = int(stdin.readline().strip())
        print("")
        
    
main()
