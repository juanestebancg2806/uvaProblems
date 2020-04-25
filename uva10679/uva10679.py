from sys import stdin


def kmp_prefix(s):
    i,j,n = 1,-1,len(s)
    P = [None]*n
    P[0] = -1
    while i < n:
        while j>= 0 and s[j+1] != s[i]:
            j = P[j]
        if s[j+1] == s[i]:
            j += 1
        P[i] = j
        i += 1
    return P

def kmp_search(s1,s2):
    i,j,n1,n2 = 0,-1,len(s1),len(s2)
    P = kmp_prefix(s2)
    while i < n1:
        while j>= 0 and s2[j+1] != s1[i]:
            j = P[j]
        if s2[j+1] == s1[i]:
            j += 1
        if j == n2-1:
            return True
        i += 1
    return False


def solve(s1,s2):
    ans = "y" if kmp_search(s1,s2) else "n"
    return ans
def main():
    tc = int(stdin.readline())
    for i in range(tc):
        s1 = stdin.readline().strip()
        q = int(stdin.readline())
        for j in range(q):
            s2 = stdin.readline().strip()
            print(solve(s1,s2))
        
main()
