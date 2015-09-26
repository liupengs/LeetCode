class Solution(object):
    def combinletter(self,a,digits,s,lens):
        t=int(digits[s])
        if s==lens:
            ret=list(a[t])
        else:
            ret=[]
            r=self.combinletter(a,digits,s+1,lens)
            for i in a[t]:
                for j in range(len(r)):
                    ret.append(i+r[j])
        return ret
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        a=[0]*10
        a[2]='abc'
        a[3]='def'
        a[4]='ghi'
        a[5]='jkl'
        a[6]='mno'
        a[7]='pqrs'
        a[8]='tuv'
        a[9]='wxyz'
        lens=len(digits)
        if lens==0:
            return []
        else:
            return self.combinletter(a,digits,0,lens-1)
