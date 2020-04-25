from sys import stdin


def solve(s):
    ans = ""
    if s == "HELLO":
        ans = "ENGLISH"
    elif s == "HOLA":
        ans = "SPANISH"
    elif s == "HALLO":
        ans = "GERMAN"
    elif s == "BONJOUR":
        ans = "FRENCH"
    elif s == "CIAO":
        ans = "ITALIAN"
    elif s == "ZDRAVSTVUJTE":
        ans = "RUSSIAN"
    else:
        ans = "UNKNOWN"
    return ans


def main():
    s = stdin.readline().strip()
    tc = 1
    while s != '#':
        ans = solve(s)
        print("Case {0}: {1}".format(tc,ans))
        tc += 1
        s = stdin.readline().strip()
main()
