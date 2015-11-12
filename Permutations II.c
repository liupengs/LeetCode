class Solution:
	def combine(self,nums):
	    s=""
	    for i in nums:
	        s+=str(i)
	    return s
	def getcombine(self,nums,lens,myindex):
	    re=[]
	    if lens<=1:
	        re.append(nums)
	        return re
	        
	    for i in xrange(lens):
	        
	        t=nums[0:i]+nums[i+1:lens]
	        index=self.combine(t)
	        
	        if self.dists.has_key(index):
	            r=self.dists[index]
	        else:
	            r=self.getcombine(t,lens-1,index)
	  
	        for one in r:
	            t=nums[i:i+1]+one
	            if t not in re:
	                re.append(nums[i:i+1]+one)
	    if myindex:
	        self.dists[myindex]=re
	    return re
	            
    # @param {integer[]} nums
    # @return {integer[][]}
	def permuteUnique(self, nums):
	    self.dists={}
	    return self.getcombine(nums,len(nums),self.combine(nums))
