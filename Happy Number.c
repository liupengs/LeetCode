class Solution(object):
    def generate(self,numRows):
        if numRows==1:
            return [[1]]
        if numRows==0:
            return []
        lists=[[1]]
        for i in range(1,numRows):
            b=[1]*(i+1)
            for j in range(1,i):
                b[j]=lists[i-1][j-1]+lists[i-1][j]
            lists.append(b)
        return lists
