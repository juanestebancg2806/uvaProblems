from sys import stdin



def main():
    line = stdin.readline().strip()
    while len(line) and line != "" and line != "\n":
        n,m = map(int,line.split())
        print(abs(n-m))
        line = stdin.readline().strip()
main()
