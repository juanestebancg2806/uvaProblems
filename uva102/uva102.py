from sys import stdin

idx = {0:"B",1:"G",2:"C"}
INF = float('inf')

def solve(n):
    global cost,s,path,visited
    if(n == 3):
        _cost,_s =sum(B)+sum(G)+sum(C),idx[path[0]]+idx[path[1]]+idx[path[2]]
        for i in range(len(path)):
            if path[i] == 0:
                _cost -= B[i]
            elif path[i] == 1:
                _cost -= G[i]
            else:
                _cost -= C[i]
        if _cost < cost:
            cost,s = _cost,str(_s)
        elif _cost == cost and _s < s:
            s = str(_s)
    else:
        for i in range(3):
            if not visited[i]:
                path.append(i)
                visited[i] = True
                solve(n+1)
                path.pop()
                visited[i] = False


def main():
    global B,G,C,path,cost,s,visited
    line = stdin.readline().strip()
    while len(line) and line != "" and line != "\n":
        line = [int(x) for x in line.split()]
        B,G,C,path,cost,s,visited = list(),list(),list(),list(),INF,"ZZZ",[False for _ in range(3)]
        for i in range(len(line)):
            if (i+1)%3 == 1:
                B.append(line[i])
            elif (i+1)%3 == 2:
                G.append(line[i])
            else:
                C.append(line[i])
        solve(0)
        print(s,cost)
        line = stdin.readline().strip()
main()
