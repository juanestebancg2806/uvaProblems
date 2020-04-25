from sys import stdin

def main():
    seq = {2: ['00', '01', '81'], 4: ['0000', '0001', '2025', '3025', '9801'], 6: ['000000', '000001', '088209', '494209', '998001'], 8: ['00000000', '00000001', '04941729', '07441984', '24502500', '25502500', '52881984', '60481729', '99980001']}
    line = stdin.readline().strip()
    while len(line) and line != "" and line != "\n":
        n = int(line)
        print("\n".join(seq[n]))
        line = stdin.readline().strip()
main()
