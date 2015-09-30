class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        d={}
        for i in nums:
            if not d.has_key(i):
                d[i]=1
            else:
                d[i]+=1
        for key in d:
            if d[key]==1:
                return key
        
