from sys import stdin

class sgtree(object):
    def __init__(self,arr):
        self.size = len(arr)
        self.tree = [None for i in range(4*len(arr))]
        self.initialize(arr,0,0,len(arr))
        self.freq = {}

    def left(self,i):
        return 2*i+1
    def right(self,i):
        return 2*i+2
    
    def parent(self,i):
        return (i-1)//2
    def initialize(self,arr,i,low,hi):
        if low +1 == hi:
            self.tree[i] = arr[low]
        else:
            mid = (low+hi)//2
            self.tree[i] = self.initialize(arr,self.left(i),low,mid)
            self.tree[i] += self.initialize(arr,self.right(i),mid,hi)
        return self.tree[i]

    def update(self,x,j):
        self.update_aux(0,0,self.size,x,j)

    def update_aux(self,i,low,hi,x,j):
        if low+1 == hi:
            self.tree[i] = x
        else:
            mid = (low+hi)//2
            if j < mid:
                l,r = self.update_aux(self.left(i),low,mid,x,j),self.tree[self.right(i)]
            else:
                l,r = self.tree[self.left(i)],self.update_aux(self.right(i),mid,hi,x,j)
            self.tree[i] = l+r
        return self.tree[i]
    def query(self,i,j):
        return self.query_aux(0,0,self.size,i,j)
        
    def query_aux(self,i,ilow,ihi,low,hi):
        ans = None
        if ihi <= low or hi<=ilow: ans = 0

        elif ilow >= low and ihi<=hi :
            ans = self.tree[i]
        elif ilow+1 == ihi:
            ans = self.tree[i]
        else:
            imid = (ilow+ihi)//2
            ans = self.query_aux(self.left(i),ilow,imid,low,hi) + self.query_aux(self.right(i),imid,ihi,low,hi)
        return ans

def main():
    n = [int(x) for x in stdin.readline().split()]
    while len(n) != 1:
        N,Q = n
        arr = [int(x) for x in stdin.readline().split()]
        for i in range(Q):
            low,hi = 
main()
        
        
        
                
                
        



    
        
