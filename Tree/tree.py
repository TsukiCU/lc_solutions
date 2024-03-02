class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def construct_tree(o_list):
    if o_list is None or o_list[0] is None:
        return None
    i=1

    root = TreeNode(o_list[0])
    queue = [root]
    while i<len(o_list):
        cur = queue.pop(0)
        if o_list[i] is not None:
            cur.left = TreeNode(o_list[i])
            queue.append(cur.left)
        i+=1
        if o_list[i] is not None and i<len(o_list):
            cur.right = TreeNode(o_list[i])
            queue.append(cur.right)
        i+=1

    return root

if __name__ == '__main__':
    # To construct a tree, we need a explicit list
    # for example, [3,9,20,null,null,15,7]
    # Tree level traversal
    order_list = [3,9,20,None,None,15,7]
    tree = construct_tree(order_list)

