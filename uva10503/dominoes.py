from sys import stdin
import sys
sys.setrecursionlimit(10000000)


def solve(i,last):
    global visited,ans
    if i == n:
        if last[1] == final[0]:
            ans = True
    else:
        k = 0
        while k < N and not ans:
            if not visited[k] and last[1] == dominoes[k][0]:
                visited[k] = True
                solve(i+1,dominoes[k])
                visited[k] = False
            elif not visited[k] and last[1] == dominoes[k][1]:
                visited[k] = True
                tmp = (dominoes[k][1],dominoes[k][0])
                solve(i+1,tmp)
                visited[k] = False
            k += 1
                
        

def main():
    global dominoes,N,ans,visited,n,initial,final
    n = int(stdin.readline().strip())
    while n != 0:
        m = int(stdin.readline().strip())
        dominoes,ans,visited = [],False,[False  for _ in range(m)]
        i_1,i_2 = map(int,stdin.readline().strip().split())
        initial = (i_1,i_2)
        f_1,f_2 = map(int,stdin.readline().strip().split())
        final = (f_1,f_2)
        for _ in range(m):
            t_1,t_2 = map(int,stdin.readline().strip().split())
            dominoes.append((t_1,t_2))
        N = len(dominoes)
        solve(0,initial)
        if ans:
            print("YES")
        else:
            print("NO")
        n = int(stdin.readline().strip())
        
        
main()
