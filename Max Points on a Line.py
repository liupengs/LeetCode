# Definition for a point.
# class Point(object):
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b

class Solution(object):
    def maxPoints(self, points):
        """
        :type points: List[Point]
        :rtype: int
        """
        Plen=len(points)
        if Plen<3:
            return Plen
        m=0
        dicts={}
        for i in range(Plen):
            t="x_"+str(points[i].x)+"_y_"+str(points[i].y)
            if dicts.has_key(t):
                dicts[t][2]+=1
            else:
                dicts[t]=[points[i].x,points[i].y,1]
        Ptemp=dicts.values()
        Plen=len(Ptemp)
        for i in range(Plen):
            m=max(m,Ptemp[i][2])
            dicts={}
            for j in range(i+1,Plen):
                if Ptemp[i][1]==Ptemp[j][1]:
                    t="y_0"
                elif Ptemp[i][0]==Ptemp[j][0]:
                    t="x_0"
                else:
                    if Ptemp[i][0]>Ptemp[j][0]:
                        t="index_"+str(float(Ptemp[i][0]-Ptemp[j][0])/float(Ptemp[i][1]-Ptemp[j][1]))
                    else:
                        t="index_"+str(float(Ptemp[j][0]-Ptemp[i][0])/float(Ptemp[j][1]-Ptemp[i][1]))
                if dicts.has_key(t):
                    dicts[t]+=Ptemp[j][2]
                else:
                    dicts[t]=Ptemp[i][2]+Ptemp[j][2]
                #print dicts
                m=max(m,dicts[t])
        return m
            
            
        
