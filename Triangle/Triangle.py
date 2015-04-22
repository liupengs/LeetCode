__author__ = 'liupeng'
class Solution:
    def minimumTotal(self, triangle):
        triangle_len_1=len(triangle)
        for i in range(triangle_len_1-1,-1,-1):
            print "turn %d"%(i)
            triangle_len_2=len(triangle[i])
            if i < triangle_len_1-1:
                print "in mind:"
                for j in range(0,triangle_len_2):
                    triangle[i][j]+=triangle[i+1][j]
                    print triangle[i][j]
            for j in range(0,triangle_len_2-1):
                print "in end:"
                triangle[i][j]=min(triangle[i][j],triangle[i][j+1])
                print triangle[i][j]
        return  triangle[0][0]
if __name__=="__main__":
    #t=[[2],[3,4],[6,5,7],[4,1,8,3]]
    t=[[2],[3,4]]
    test=Solution()
    test.minimumTotal(t)

