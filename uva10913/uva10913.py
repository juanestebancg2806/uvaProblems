from sys import stdin
import sys
sys.setrecursionlimit(100000000)

deltas = [(0,-1,1),(0,1,0),(1,0,2)]
INF = float('inf')

def solve(r,c,k,d):
    global visited,mem
    ans = None
    #visited[r][c] = True
    if(board[r][c] < 0):
        k -= 1
    if(k < 0):
        ans = -INF
    if k >= 0 and mem[r][c][k][d] != INF:
        ans = mem[r][c][k][d]
    elif(r == len(board)-1 and c == len(board)-1):
        ans = board[r][c]
    else:
        ans = -INF
        if d == 2:
            for i,j,dd in deltas:
                if 0 <= i+r < len(board) and 0 <= j+c < len(board):
                    ans = max(ans,board[r][c]+solve(i+r,j+c,k,dd))      
        elif d == 0:#go right,down, come from right
            i,j,dd = deltas[1]
            if 0 <= i+r < len(board) and 0 <= j+c < len(board):
                ans = max(ans,board[r][c]+solve(i+r,j+c,k,dd))
            i,j,dd = deltas[2]
            if 0 <= i+r < len(board) and 0 <= j+c < len(board):
                ans = max(ans,board[r][c]+solve(i+r,j+c,k,dd))
        else:#go left,down, come from left
            i,j,dd = deltas[0]
            if 0 <= i+r < len(board) and 0 <= j+c < len(board):
                ans = max(ans,board[r][c]+solve(i+r,j+c,k,dd))
            i,j,dd = deltas[2]
            if 0 <= i+r < len(board) and 0 <= j+c < len(board):
                ans = max(ans,board[r][c]+solve(i+r,j+c,k,dd))       
    #visited[r][c] = False
    return ans
    


def main():
    global board,visited,mem
    N,K = map(int,stdin.readline().strip().split())
    TC = 1
    while not (N == 0 and K == 0):
        board,visited = [],[[False for _ in range(N)] for _ in range(N)]
        for _ in range(N):
            line = [int(x) for x in stdin.readline().strip().split()]
            board.append(line)
        mem = [[[[INF for _ in range(3)] for _ in range(K+1)] for _ in range(N+1)] for _ in range(N+1)]
        ans = solve(0,0,K,2)
        print("Case {0}: {1}".format(TC,ans if ans >= 0 else "impossible"))
        TC += 1
        N,K = map(int,stdin.readline().strip().split())
            

main() 
