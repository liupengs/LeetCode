class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        tdict={'A':0,'C':1,'G':2,'T':3}
        sdict={}
        lists=[]
        sum=0
        for i in range(len(s)):
            sum=sum*4+tdict[s[i]]
            sum%=1048576
            if i>=9:
                if not sdict.has_key(sum):
                    sdict[sum]=1
                elif sdict[sum]==1:
                    sdict[sum]+=1
                    lists.append(s[i-9:i+1])
        return lists
