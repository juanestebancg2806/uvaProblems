from sys import stdin


def find(dforest,x):
    if dforest[x] != x:
        dforest[x] = find(dforest,dforest[x])
    return dforest[x]

def union(dforest,x,y):
    global comps
    px,py = find(dforest,x),find(dforest,y)
    if px != py:
        dforest[py] = px
        comps -= 1


def main():
    global comps
    n,m = map(int,stdin.readline().split())
    tc = 1
    while n != 0 and m != 0:
        dforest = [i for i in range(n)]
        comps = n
        for i in range(m):
            a,b = map(int,stdin.readline().split())
            union(dforest,a-1,b-1)
        print("Case {0}: {1}".format(tc,comps))
        tc += 1
        n,m = map(int,stdin.readline().split())
        
main()
