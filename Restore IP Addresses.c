class Solution(object):
    def testLeft(self,s,b,lens,finds,r):
        #print finds
        if r==5 and b==lens:
            self.re.append(finds)
            return
        for i in xrange(b+1,lens+1):
            t=s[b:i]
            if len(t)>1 and t[0]=="0":
                break
            t1=int(t)
            if t1<256:
                self.testLeft(s,i,lens,finds+"."+t,r+1)
            else:
                break
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        lens=len(s)
        if lens>12:
            return []
        self.re=[]
        dicts={}
        have=0
        for i in xrange(1,lens+1):
            t=s[0:i]
            if len(t)>1 and t[0]=="0":
                break
            t1=int(t)
            if t1<256:
                self.testLeft(s,i,lens,t,2)
            else:
                break
        return self.re
