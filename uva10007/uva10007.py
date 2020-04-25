from sys import stdin

fact = [1 for _ in range(601)]


def make_seq():
    for i in range(1,601):
        fact[i] = i*fact[i-1]
        

def main():
    make_seq()
    n = int(stdin.readline().strip())
    while n != 0:
        ans = fact[2*n]//fact[n+1]
        print(ans)
        n = int(stdin.readline().strip())

main()
