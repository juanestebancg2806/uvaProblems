from sys import stdin


def solve(a):
    i = ans = 1
    while i < len(a)-1:
        ans = ans+1 if ans%2 != 0 and a[i+1]<a[i] else ans
        ans = ans+1 if ans%2 == 0 and a[i+1] > a[i] else ans
        i += 1
    return ans

def main():
    T = int(stdin.readline().strip())
    for _ in range(T):
        a = [int(x) for x in stdin.readline().strip().split()]
        print(solve(a))
main()
