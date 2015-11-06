class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        string="1"
        m=0
        while n>1:
            temp=""
            lens=len(string)
            m=1
            for i in range(1,lens):
                if string[i]==string[i-1]:
                    m+=1
                else:
                    temp+=(str(m)+string[i-1])
                    m=1
            if m>0:
                temp+=(str(m)+string[lens-1])
            string=temp
            n-=1
            #print string
        return string
