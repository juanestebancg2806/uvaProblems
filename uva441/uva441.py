from sys import stdin
import sys
sys.setrecursionlimit(1000000000)
INF = float('inf')

def solve(i,n,s):
    global path
    if s == 0:
        print(" ".join(path))
    elif i < N:
        if numbers[i] >= n:
            path.append(str(numbers[i]))
            solve(i+1,numbers[i],s-1)
            path.pop()
        solve(i+1,n,s)


def main():
    global numbers,path,N
    numbers = [int(x) for x in stdin.readline().strip().split()]
    while numbers[0] != 0:
        path,N = list(),numbers[0]+1
        solve(1,-INF,6)
        numbers = [int(x) for x in stdin.readline().strip().split()]
        if numbers[0] != 0:
            print("")
        
main()
