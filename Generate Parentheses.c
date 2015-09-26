class Solution(object):
    def __init__(self):
        self.re=[]
    def combin(self,deep,leftnum,rightnum,string):
        if leftnum<deep:
            self.combin(deep,leftnum+1,rightnum,string[:]+"(")
        if leftnum>rightnum:
            self.combin(deep,leftnum,rightnum+1,string[:]+")")
        if rightnum==deep:
            self.re.append(string)
            
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        self.p=[0]*n
        if n<1:
            return []
        self.combin(n,1,0,"(")
        return self.re
