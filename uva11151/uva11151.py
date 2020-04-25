from sys import stdin


def solve(A):
    N = len(A)
    if N == 0:
        return 0
    tab = [[0 for _ in range(N) ] for _ in range(N)]
    for i in range(N):
        tab[i][i] = 1
    n,m = 1,0
    while n != N:
        if m == -1:
            n += 1
            m = n-1
        else:
            if A[n] == A[m]:
                tab[m][n] = 2 + tab[m+1][n-1]
            else:
                tab[m][n] = max(tab[m+1][n],tab[m][n-1])
            m -= 1
    return tab[0][N-1]


def main():
    n = int(stdin.readline())
    while n != 0:
        word = list(stdin.readline().strip())
        #print(word)
        print(solve(word))
        
        n -= 1
main()
