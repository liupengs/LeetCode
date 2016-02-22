# Definition for a undirected graph node
# class UndirectedGraphNode(object):
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

class Solution(object):
    def clone(self, node, temp):
        result =None
        if node == None:
            return None
        else:
            result = UndirectedGraphNode(node.label)
            temp[node.label]=result
            for i in node.neighbors:
                if temp.has_key(i.label):
                    result.neighbors.append(temp[i.label])
                else:
                    result.neighbors.append(self.clone(i,temp))
        return result
    def cloneGraph(self, node):
        """
        :type node: UndirectedGraphNode
        :rtype: UndirectedGraphNode
        """
        temp={}
        
        return self.clone(node,temp)
