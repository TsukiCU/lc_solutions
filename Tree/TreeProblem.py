from tree import TreeNode, construct_tree

class TreeOps:
    def __init__(self) -> None:
        pass

    def CountNodesCommon(self, rootNode):
        '''
            General solution of counting nodes.
        '''
        if not rootNode:
            return 0

        return self.CountNodesCommon(rootNode.left) \
            + self.CountNodesCommon(rootNode.right) + 1

    def maxDepth(self, rootNode):
        if rootNode is None:
            return 0

        left = self.maxDepth(rootNode.left)
        right = self.maxDepth(rootNode.right)
        return max(left, right) + 1

    def isSameTree(self, p, q):
        if p is None and q is None:
            return True

        elif p is None or q is None:
            return False

        return p.val == q.val and self.isSameTree(p.left, q.left) \
            and self.isSameTree(p.right, q.right)

    def invertTree(self, rootNode):
        # [4,2,7,1,3,6,9] -> [4,7,2,9,6,3,1]
        if rootNode is None:
            return

        left, right = rootNode.left, rootNode.right
        rootNode.left, rootNode.right = right, left

        self.invertTree(left)
        self.invertTree(right)

        return rootNode

    def isSymmetric(self, rootNode):
        # [1,2,2,3,4,4,3] is a symmetric tree.
        # [] is not a symmetric tree by definition.
        if rootNode is None:
            return False

        if not rootNode.left and not rootNode.right:
            return True

        elif not rootNode.left or not rootNode.right:
            return False

        left, right = rootNode.left, rootNode.right
        left = self.invertTree(left)
        return self.isSameTree(left, right)

    def countNodes(self, rootNode):
        '''
            Number of Nodes in a Complete Binary Tree.
        '''
        # Didn't use the features of compelete binary tree.
        # return self.CountNodesCommon(rootNode)
        if rootNode is None:
            return 0
        left, right = rootNode.left, rootNode.right
        leftHeight, rightHeight = self.maxDepth(left), self.maxDepth(right)

        if leftHeight == rightHeight:
            return (1<<leftHeight) + self.countNodes(right)
        else:
            return (1<<rightHeight) + self.countNodes(left)

    def flatten(self, rootNode):
        '''
            Flatten a tree to a linked list.
            Don't return anything. Make it in-place modifying.
        '''
        pass


if __name__ == '__main__':
    order_list_1 = [3,9,20,None,None,15,7]
    order_list_2 = [1,2,2,3,4,4,3]
    p = construct_tree(order_list_1)
    q = construct_tree(order_list_2)
    tree_ops = TreeOps()

    # print(tree_ops.maxDepth(q))
    # print(tree_ops.isSymmetric(q))

    t = [1]
    tree = construct_tree(t)
    print(tree_ops.countNodes(tree))

