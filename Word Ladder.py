class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: Set[str]
        :rtype: int
        """
        blens=len(beginWord)
        blists=[beginWord]
        trun=2
        if beginWord in wordList:
            wordList.remove(beginWord)
        if endWord in wordList:
            wordList.remove(endWord)
            
        while blists:
            temp=[]
            for word in blists:
                for i in range(blens):
                    for j in "abcdefghijklmnopqrstuvwxyz":
                        t=word[0:i]+j+word[i+1:blens]
                        if t==endWord:
                            return trun
                        elif t in wordList:
                            temp.append(t)
                            wordList.remove(t)
                        
            if len(temp)==0:
                return 0
            else:
                trun+=1
            blists=temp
        return 0
            
