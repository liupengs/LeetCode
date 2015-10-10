# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

#solution one
class Solution(object):
    def trivial(self,head,lists):
        if head==None:
            return
        self.trivial(head.left,lists)
        lists.append(head.val)
        self.trivial(head.right,lists)
        
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        lists=[]
        self.trivial(root,lists)
        return lists
