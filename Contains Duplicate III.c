class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        """
        :type nums: List[int]
        :type k: int
        :type t: int
        :rtype: bool
        """
        lens=len(nums)
        if len(nums)==0 or k<1 or t<0:
            return False
            
        hashs={}
        tp1=t+1
        
        for i in range(len(nums)):
            if i>k:
                del hashs[hash(nums[i-k-1]/tp1)]
            tp=nums[i]/tp1
            key=hash(tp)
            key1=hash(tp-1)
            key2=hash(tp+1)
            if (hashs.has_key(key) and abs(nums[i]-hashs[key])<=t) or (hashs.has_key(key1) and abs(nums[i]-hashs[key1])<=t) or (hashs.has_key(key2) and abs(hashs[key2]-nums[i])<=t):
                return True
            else:
                hashs[key]=nums[i]
        return False
