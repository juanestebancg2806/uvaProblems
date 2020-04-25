from sys import stdin
import sys
sys.setrecursionlimit(100000)


def find(df,i):
    if df[i] != i:
        df[i] = find(df,df[i])
    return df[i]

def union(df,i,j):
    global comps
    pi,pj = find(df,i),find(df,j)
    if pi != pj:
        df[pj] = pi
        comps -= 1

def main():
    global comps
    tc = int(stdin.readline())
    stdin.readline()
    while tc:
        c = int(stdin.readline())
        line = stdin.readline().split()
        df = [i for i in range(c)]
        comps = len(df)
        gans,bans = 0,0
        while line != "" and line != "\n" and len(line) != 0:
            if line[0] == "c":
                union(df,int(line[1])-1,int(line[2])-1)
            else:
                pi,pj = find(df,int(line[1])-1),find(df,int(line[2])-1)
                if pi == pj:
                    gans += 1
                else:
                    bans += 1                
            line = stdin.readline().split()
        print("{0},{1}".format(gans,bans))
        tc -= 1
        if tc:
            print("")
            
            
            
        
main()
