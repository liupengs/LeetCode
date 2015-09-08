class Solution(object):
    def __init__(self):
        self.r=[]
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        num=len(nums)
        if num==0:
            return []
        for i in range(0,num-k+1):
            t=nums[i:i+k]
            self.r.append(max(t))
        return self.r
