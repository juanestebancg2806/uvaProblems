from sys import stdin



def make_perms(n):
    global path,perms,visited
    if(n == 5):
        perms.append(list(path))
    else:
        for i in range(5):
            if not visited[i]:
                path.append(i)
                visited[i] = True
                make_perms(n+1)
                visited[i] = False
                path.pop()
        

def solve(s,N):
    ans = s == 23 and N == 5
    if N < 5: ans = solve(s+nums[N],N+1) or solve(s-nums[N],N+1) if s*nums[N] > 200 else solve(s+nums[N],N+1) or solve(s-nums[N],N+1) or solve(s*nums[N],N+1)
    return ans

def main():
    global path,perms,visited,nums
    perms,path,visited,nums,i,ans,j,inp = list(),list(),[False for _ in range(5)],list(),0,None,0,None
    make_perms(0)
    inp = [int(x) for x in stdin.readline().strip().split()]
    while not(inp[0] == 0):
        i,ans = 0,False
        while i < len(perms) and not ans:
            nums = list()
            for j in perms[i]: nums.append(inp[j])
            ans,i = ans or solve(nums[0],1),i+1
        print("Impossible" if not ans else "Possible")
        inp = [int(x) for x in stdin.readline().strip().split()]
                
            
        

main()
