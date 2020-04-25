from sys import stdin
import sys
sys.setrecursionlimit(10000000)

def solve_aux(arr,low,mid,hi):
    i,j,ans = low,mid,0
    tmp = []
    while i < mid and j < hi:
        if arr[i] <= arr[j]:
            tmp.append(arr[i])
            i += 1
        else:
            tmp.append(arr[j])
            j += 1
            ans += mid-i
    while i < mid:
        tmp.append(arr[i])
        i += 1
    while j < hi:
        tmp.append(arr[j])
        j += 1
    arr[low:hi] = tmp
    return ans

def solve(arr,low,hi):
    ans = None
    if low == hi or low+1 == hi:
        ans = 0
    else:
        mid = (low+hi)//2
        ans = solve(arr,low,mid)
        ans += solve(arr,mid,hi)
        ans += solve_aux(arr,low,mid,hi)
    return ans


def main():
    n = stdin.readline()
    while n != "" and n != "\n" and len(n):
        n = int(n)
        arr = [int(x) for x in stdin.readline().split()]
        #print(arr)
        print("Minimum exchange operations : {0}".format(solve(arr,0,n)))
        n = stdin.readline()
main()
