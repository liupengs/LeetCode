class Solution(object):
    def __init__(self):
        self.re=[]
    def get(self,lists,i,left,k):
        if k==1:
            for j in range(i,10):
                if j>left:
                    return
                if j==left:
                    l=lists[:]
                    l.append(j)
                    self.re.append(l)
        else:
            for i in range(i,10):
                if i>left:
                    return

                l=lists[:]
                l.append(i)
                self.get(l,i+1,left-i,k-1)

    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        if k<1 or n<1 or n>55:
            return []
        t=k
        top=0
        while t:
            top+=t
            t-=1
        if n<top:
            return []

        t=10-k
        top=0
        while t<10:
            top+=t
            t+=1
        if n>top:
            return []
        self.re=[]


        self.get([],1,n,k)
        return self.re
