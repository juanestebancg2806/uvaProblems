from sys import stdin


def solve(N,v,o):
    global mem
    ans = None
    if mem.get((N,v)) != None:
        ans = mem[(N,v)]
    elif(N == 0 and v <= 5000):
        ans = 0
    elif(v > 5000):
        ans = (100*o)/(v)
    else:
        ans = max(solve(N-1,v,o),solve(N-1,v+stockH[N-1],o))
    mem[(N,v)] = ans
    return ans
    


def main():
    global stockH,mem
    N,X = map(int,stdin.readline().strip().split())
    while(not (N == 0 and X == 0)):
        stockH = list()
        for _ in range(N):
            stockH.append(int(float(stdin.readline().strip())*100))
        stockH[X-1],stockH[-1] = stockH[-1],stockH[X-1]
        mem = {}
        v = stockH.pop()
        ans = solve(N-1,v,v)
        print("{0:.2f}".format(ans))
        N,X = map(int,stdin.readline().strip().split())

main()
