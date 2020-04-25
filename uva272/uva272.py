from sys import stdin


def main():
    lines = stdin.readlines()
    text,i,sym,left,right,cnt = [],0,chr(34),chr(96),chr(39),0
    for l in lines:
        text.append(l.strip())
    while i < len(text):
        s = text[i]
        out = ""
        for j in range(len(s)):
            if s[j] == sym and not cnt:
                out += left+left
                cnt += 1
            elif s[j] == sym:
                out += right+right
                cnt += 1
            else:
                out += s[j]
            if cnt == 2:
                cnt = 0
        print(out)
        i += 1
                
                
main()
