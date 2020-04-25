from sys import stdin

INF = float('inf')
def find(dforest,i):
    if dforest[i] != i:
        dforest[i] = find(dforest,dforest[i])
    return dforest[i]

def union(dforest,i,j):
    pi,pj = find(dforest,i),find(dforest,j)
    if pi != pj:
        dforest[pj] = pi


def kruskal(G):
    dforest = [i for i in range(n)]
    G.sort(key = lambda x: -x[2])
    ans = INF
    for i in range(len(G)):
        u,v,d = G[i]
        if find(dforest,u) != find(dforest,v):
            union(dforest,u,v)
            ans = min(ans,d)
    return ans


def main():
    global n,m
    tc = int(stdin.readline())
    for i in range(tc):
        n,m = map(int,stdin.readline().split())
        G = []
        for j in range(m):
            u,v,d = map(int,stdin.readline().split())
            G.append((u,v,d))
        print("Case #{0}: {1}".format(i+1,kruskal(G)))
main()
        
