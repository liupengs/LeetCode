class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        p=[0]*26
        sdicts={}
        lenp=len(pattern)
        lists=str.split(' ')
        lens =len(lists)
        if lens!=lenp:
            return False
        for i in range(lens):
            if sdicts.has_key(lists[i]):
                if sdicts[lists[i]]==pattern[i]:
                    continue
                else:
                    return False
            else:
                t=ord(pattern[i])-97
                if p[t]==0:
                    sdicts[lists[i]]=pattern[i]
                    p[t]=1
                else:
                    return False
        return True
