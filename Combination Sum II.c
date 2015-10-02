class Solution(object):
    def getsum(self,candidates,s,target,lens):
        if s==lens:
            return []
        r=[]
        f=self.getsum(candidates,s+1,target,lens)
        r+=f
        t=candidates[s]
        target-=t
        if target==0:
            r.append([t])
            return r
        elif target>=t:
            f=self.getsum(candidates,s+1,target,lens)
            for i in f:
                r.append([t]+i)
        
        return r
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates=sorted(candidates)
        lens=len(candidates)
        r=self.getsum(candidates,0,target,lens)
        re=[]
        for i in r:
            if i not in re:
                re.append(i)
        return re
