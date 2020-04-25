from sys import stdin



def main():
    inp,txt = stdin.readlines(),[]
    for line in inp:
        if line.strip() != "\n" and line.strip() != "":
            txt.append(line.strip())
    tc,i = int(txt[0]),1
    for _ in range(tc):
        p,m,n = map(str,txt[i].split())
        m,n = int(m),int(n)
        if p == 'r':
            print(min(m,n))
        elif p == 'k':
            if m%2 == 0:
                print((m//2)*n)
            else:
                ans = 0
                for k in range(n):
                    ans = ans+((m//2)+1) if k%2 == 0 else ans + (m//2)
                print(ans)
        elif p == 'Q':
            print(min(n,m))
        else:
            m = (m//2)+1 if m%2 != 0 else m//2
            n = (n//2)+ 1 if n%2 != 0 else n//2
            print(n*m)
                
        i += 1
        
        
main()
