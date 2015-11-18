class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        lists=[[]]
        for i in nums:
            list1=lists[:]
            for t in list1:
                t=sorted(t+[i])
                if t not in lists:
                    lists.append(t)
        return lists
                
        
