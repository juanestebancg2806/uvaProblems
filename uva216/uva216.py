from sys import stdin
import math
INF = float('inf')

def f(x1,y1,x2,y2):
    return math.sqrt(((x1-x2)**2)+((y1-y2)**2))

def solve(n):
    global visited,pathtmp,ans,path
    if n == len(computers):
        cost = 0
        for i in range(1,len(pathtmp)):
            posi,posj = pathtmp[i-1],pathtmp[i]
            cost += G[posi][posj]+16
        if cost < ans:
            ans = cost
            path = list(pathtmp)
        
    else:
        i = 0
        while i < len(computers):
            if not visited[i]:
                visited[i] = True
                pathtmp.append(i)
                solve(n+1)
                visited[i] = False
                pathtmp.pop()
            i += 1
                
    
            
            
                
def main():
    global computers,G,visited,ans,path,pathtmp
    N,line,tc = int(stdin.readline().strip()),"**********************************************************",1
    while(N):
        computers,ans,visited,path,pathtmp = list(),INF,[False for _ in range(N)],list(),list()
        for _ in range(N):
            x,y = map(int,stdin.readline().strip().split())
            computers.append((x,y))
        G = [[0 for _ in range(N)] for _ in range(N)]
        for i in range(N):
            xi,yi = computers[i]
            for j in range(i+1,N):
                xj,yj = computers[j]
                d = f(xi,yi,xj,yj)
                G[i][j] = d
                G[j][i] = d
        solve(0)
        print(line)
        print("Network #{0}".format(tc))
        for i in range(1,len(path)):
            xi,yi = computers[path[i-1]]
            xj,yj = computers[path[i]]
            print("Cable requirement to connect ({0},{1}) to ({2},{3}) is {4} feet.".format(xi,yi,xj,yj,f(xi,yi,xj,yj)+16))
        print("Number of feet of cable required is {0}.".format(ans))
        tc += 1
        N = int(stdin.readline().strip())
main()
