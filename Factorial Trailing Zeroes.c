class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n==0:
            return 0
        
        sum=0    
        while n>0:
            n/=5
            sum+=n
            
        return sum
        
