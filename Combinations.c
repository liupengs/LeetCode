class Solution(object):
    def addkey(self,s,k,value):
        if not self.dicts.has_key(s):
            self.dicts[s]={}
        if not self.dicts[s].has_key(k):
            self.dicts[s][k]=value
        
    def comsub(self,s,n,k):
        if n-s+1<k or k==0:
            return []
        if self.dicts.has_key(s) and self.dicts[s].has_key(k):
            return self.dicts[s][k]
        elif k==1:
            self.addkey(s,k,[[s]])
            return [[s]]
        re=[]
        for i in range(s+1,n-k+3):
            t=self.comsub(i,n,k-1)
            for j in t:
                if j:
                    re.append([s]+j)
        self.addkey(s,k,re)
        return re
            
    def combine(self, n, k):
        self.dicts={}
        re=[]
        for i in range(1,n-k+2):
            t=self.comsub(i,n,k)
            re+=t
        return re
