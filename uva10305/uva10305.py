from sys import stdin



def toposort(G):
    ans,indeg,pending = list(),[0 for _ in range(len(G))],list()
    for u in range(len(G)):
        for v in G[u]:
            indeg[v] += 1
            
    for u in range(len(G)):
        if indeg[u] == 0:
            pending.append(u)
            
    while(len(pending)):
        u = pending.pop()
        ans.append(str(u+1))
        for v in G[u]:
            indeg[v] -= 1
            if indeg[v] == 0:
                pending.append(v)
    return ans
    


def main():
    n,m = map(int,stdin.readline().strip().split())
    while not(n == 0 and m == 0):
        G = [[] for _ in range(n)]
        for _ in range(m):
            u,v = map(int,stdin.readline().strip().split())
            G[u-1].append(v-1)
        ans = toposort(G)
        print(" ".join(ans))
        n,m = map(int,stdin.readline().strip().split())

main()
