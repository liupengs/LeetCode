class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        mark=0
        if n==0:
            return 1
        elif n<0:
            n=abs(n)
            mark=1
        dicts={}
        dicts[1]=x
        t=2
        while t<=n:
            dicts[t]=dicts[t/2]*dicts[t/2]
            t*=2
        sum=1.0
        while n>0:
            #print sum," ",t," ",n
            if n>=t:
                sum*=dicts[t]
                n-=t
            else:
                t/=2
            #print sum," ",t," ",n
        if mark==1:
            return 1/sum
        else:
            return sum
            
