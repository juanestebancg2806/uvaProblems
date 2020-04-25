from sys import stdin
import math

def find(dforest,i):
    if dforest[i] != i:
        dforest[i] = find(dforest,dforest[i])
    return dforest[i]

def union(dforest,i,j):
    global components
    pi,pj = find(dforest,i),find(dforest,j)
    if pi != pj:
        components -= 1
        dforest[pj] = pi
        
    
def distance(p0, p1):
    return math.sqrt((p1[0] - p0[0])**2 + (p1[1] - p0[1])**2)

def solve(points):
    global components,N,D
    components = N
    dforest = [k for k in range(N)]
    for i in range(len(points)):
        x,y = points[i]
        for j in range(i+1,len(points)):
            if i != j and distance(points[j],points[i]) < D:
                union(dforest,i,j)
    return components
    
                                
    
def main():
    global N,D
    tc = int(stdin.readline())
    c = 1
    for i in range(tc):
        N,D = map(float,stdin.readline().split())
        N = int(N)
        points = []
        for j in range(N):
            x,y = map(float,stdin.readline().split())
            points.append((x,y))
        print("Case {0}: {1}".format(c,solve(points)))
        c += 1
            
main()            
