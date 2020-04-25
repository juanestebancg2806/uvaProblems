from sys import stdin
import sys
sys.setrecursionlimit(1000)

def find(df,i):
    #print(i)
    if df[i] != i:
        df[i] = find(df,df[i])
    return df[i]

def union(df,i,j):
    global comps
    pi,pj = find(df,i),find(df,j)
    if pi != pj:
        df[pj] = pi
        comps -= 1
        #find(df,i);find(df,j)

    

def main():
    global comps
    tc = int(stdin.readline())
    stdin.readline()
    while tc:
        src = stdin.readline().strip()
        df = [i for i in range(ord(src)-65+1)]
        comps = len(df)
        line = stdin.readline().strip()
        while line != "" and len(line) != 0 and line != "\n":
            union(df,ord(line[0])-65,ord(line[1])-65)
            line = stdin.readline().strip()
        print(comps)    
        tc -= 1
        if tc:
            print("")
        
        
main()           
        
    
    
