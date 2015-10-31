class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        dicts={}
        if numerator*denominator<0:
            string1='-'
        else:
            string1=''
        numerator=abs(numerator)
        denominator=abs(denominator)
            
        t=numerator/denominator
        numerator=numerator%denominator
        string1+=str(t)
    
        string2=""
        i=0
        
        while numerator!=0:
            numerator*=10
            if dicts.has_key(numerator):
                break
            else:
                dicts[numerator]=i
            if numerator>=denominator:
                string2+=str(numerator/denominator)
                numerator%=denominator
            else:
                string2+='0'
            i+=1

        if numerator>0:
            return string1+'.'+string2[:dicts[numerator]]+'('+string2[dicts[numerator]:]+')'
        elif string2:
            return string1+'.'+string2
        else:
            return string1
            
        
        
