# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.s=[]
    def Tree(self,root,s):
        t=s+"->"+str(root.val)
        if root.left==None and root.right==None:
            self.s.append(t)
        else:
            if root.left!=None:
                self.Tree(root.left,t)
            if root.right!=None:
                self.Tree(root.right,t)
            
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        if root==None:
            return []
        elif root.left==None and root.right==None:
            self.s.append(str(root.val))
        else:
            t=str(root.val)
            if root.left!=None:
                self.Tree(root.left,t)
            if root.right!=None:
                self.Tree(root.right,t)
        return self.s
            
        
