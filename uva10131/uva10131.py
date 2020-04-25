from sys import stdin

def solve():
    N = len(W)
    path,maxv,maxi = [[] for _  in range(N)],1,0
    path[0].append(idx[0])
    for i in range(1,N):
        for j in range(0,i):
            if W[j] < W[i] and IQ[j] > IQ[i] and len(path[i]) < len(path[j])+1:
                path[i] = list(path[j])
        path[i].append(idx[i])
        if len(path[i]) > maxv:
            maxv = len(path[i])
            maxi = i
    return path[maxi]


def main():
    global W,IQ,idx
    inp,txt,W,IQ,L,idx = stdin.readlines(),list(),list(),list(),list(),list()
    for line in inp:
        if line.strip() != "\n" and line.strip() != "":
            txt.append(line.strip())
    i = 1
    for line in txt:
        w,iq = map(int,line.split())
        L.append((w,iq,i))
        i += 1
    L.sort(key = lambda x: -x[1])
    for w,iq,i in L:
        #print(w,iq,i)
        W.append(w)
        IQ.append(iq)
        idx.append(i)
    
    ans = solve()
    print(len(ans))
    for i in range(len(ans)):
        print(ans[i])
    
main()
