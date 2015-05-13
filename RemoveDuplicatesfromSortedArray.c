class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def removeDuplicates(self, nums):
        lens=len(nums)
        if lens==0:
            return 0
        temp=0
        for i in range(1,lens):
            if nums[i]!=nums[temp]:
                temp+=1
                nums[temp]=nums[i]
        return temp+1
