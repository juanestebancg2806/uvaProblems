from sys import stdin
import sys
sys.setrecursionlimit(10000000)


def find(df,i):
    if df[i] != i:
        df[i] = find(df,df[i])
    return df[i]

def union(df,i,j):
    pi,pj = find(df,i),find(df,j)
    if pi != pj:
        df[pj] = pi

def main():
    global comps
    tc = int(stdin.readline())
    c,x,y = map(int,stdin.readline().split())
    df = [i for i in range(tc)]
    relation = [None for i in range(tc)]
    ans = []
    while c != 0 or x != 0 or y !=0:
        if c == 1 or c == 2:
            if find(df,x) == find(df,y):
                ans.append(-1)
            #else:
            union(df,x,y)

        elif c ==3 or c==4:
            if find(df,x) == find(df,y):
                ans.append(1)
            else:
                ans.append(0)
        c,x,y = map(int,stdin.readline().split())
    for i in ans:
        print(i)
main()
        
        
