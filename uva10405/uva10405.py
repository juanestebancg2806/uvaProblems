from sys import stdin



def solve(s1,s2):
    n,m = len(s1),len(s2)
    dp = [[0 for i in range(m+1)] for i in range(n+1)]
    for i in range(1,n+1):
        for j in range(1,m+1):
            if s1[i-1] == s2[j-1]:
                dp[i][j] = dp[i-1][j-1]+1
            else:
                dp[i][j] = max(dp[i][j-1],dp[i-1][j])
    return dp[n][m]
    

def main():
    s1 = stdin.readline().strip()
    s2 = stdin.readline().strip()
    while s1 != "" and len(s1) and s1 != "\n":
        print(solve(s1,s2))
        s1 = stdin.readline().strip()
        if(s1 != "" and len(s1) and s1 != "\n"):
            s2 = stdin.readline().strip()



main()
