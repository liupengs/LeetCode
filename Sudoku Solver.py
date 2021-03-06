class Solution(object):
    def solve(self,board,point):
        if point==81:
            return True
        r=point/9
        c=point%9
        if board[r][c]!='.':
            point+=1
            if self.solve(board,point):
                return True
            else:
                return False
        else:
            for i in range(1,10):
                t=str(i)
                if t not in self.m[(r/3)*3+c/3] and t not in self.line[r]  and t not in self.v[c]:
                    board[r][c]=t
                    self.line[r].append(t)
                    self.v[c].append(t)
                    self.m[(r/3)*3+c/3].append(t)
                    if self.solve(board,point+1):
                        return True
                    else:
                        board[r][c]='.'
                        self.line[r].remove(t)
                        self.v[c].remove(t)
                        self.m[(r/3)*3+c/3].remove(t)
            return False
                
    def solveSudoku(self, board):
        self.line=[[] for i in range(9)]
        self.v=[[] for i in range(9)]
        self.m=[[] for i in range(9)]
        for i in range(9):
            for j in range(9):
                if board[i][j]!='.':
                    self.line[i].append(board[i][j])
                    self.v[j].append(board[i][j])
                    self.m[(i/3)*3+j/3].append(board[i][j])
        self.solve(board,0)
