from heapq import heappop,heappush
from sys import stdin

INF = float('inf')

deltas = [(1,0),(-1,0),(0,1),(0,-1)]


def dijkstra(board):
    global N,M
    visited = [[False for _ in range(len(board[0]))] for _ in range(len(board))]
    heap = [(board[0][0],(0,0))]
    ans = [[INF for _ in range(len(board[0]))] for _ in range(len(board))]
    ans[0][0] = board[0][0]
    while len(heap) and ans[N-1][M-1] == INF:
        d,t = heappop(heap)
        i,j = t
        if visited[i][j] == False:
            visited[i][j] = True
            for ti,tj in deltas:
                if  0<= i+ti <N and 0<= j+tj < M and d + board[i+ti][j+tj] < ans[i+ti][j+tj]:
                    ans[i+ti][tj+j] = d + board[i+ti][tj+j]
                    heappush(heap,(ans[ti+i][tj+j],(i+ti,j+tj)))

    return ans[N-1][M-1]
                    
    

def main():
    global board,N,M
    tc = int(stdin.readline())
    while tc != 0:
        N = int(stdin.readline())
        M = int(stdin.readline())
        board = []
        for i in range(N):
            tmp = [int(x) for x in stdin.readline().split()]
            board.append(tmp)
        print(dijkstra(board))
        tc -= 1
  
        
main()
