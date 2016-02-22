class Solution(object):
    def clone(self, node, temp):
        result = UndirectedGraphNode(node.label)
        temp[node.label]=result
        for i in node.neighbors:
            if temp.has_key(i.label):
                result.neighbors.append(temp[i.label])
            else:
                result.neighbors.append(self.clone(i,temp))
        return result
    def cloneGraph(self, node):
        temp={}
        if node:
            return self.clone(node,temp)
        else:
            return None
