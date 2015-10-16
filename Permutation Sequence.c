class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        string=[]
        for i in range(1,n+1):
            string.append(str(i))
        t=1
        for i in range(1,n+1):
            if t*i<=k:
                t*=i
            else:
                i-=1
                break
        while k>1:
            if k>t:
                if k%t==0:
                    s=k/t-1
                else:
                    s=k/t
                st=n-i-1+s
                e=n-i-1
                temp=string[st]
                while st>e:
                    string[st]=string[st-1]
                    st-=1
                    
                    
                string[e]=temp
                if k%t==0:
                    k=t
                else:
                    k%=t
            elif k==t:
                s=n-i
                e=n-1
                while s<e:
                    temp=string[s]
                    string[s]=string[e]
                    string[e]=temp
                    s+=1
                    e-=1
                break
            t/=i
            i-=1
            
            
        return "".join(string)
