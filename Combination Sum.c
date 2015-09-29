class Solution(object):
    def getsum(self,candidates,s,target,lens):
        if s==lens:
            return []
        r=[]
        f=self.getsum(candidates,s+1,target,lens)
        r+=f
        t=candidates[s]
        target-=t
        l1=[]
        while target>=0:
            l1.append(t)
            if target==0:
                r.append(l1)
                break
            f=self.getsum(candidates,s+1,target,lens)
            for i in f:
                r.append(l1+i)
            target-=t
        return r
            
            
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates=sorted(candidates)
        lens=len(candidates)
        return self.getsum(candidates,0,target,lens)
        
        
