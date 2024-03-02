#ifndef __TREE_HH_
#define __TREE_HH_

#include <vector>
#include <queue>
#include <climits> // For INT_MIN
#include <iostream>
#include <stdbool.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Tree_ops
{
    public:
    int maxDepth(TreeNode *rootNode) {
        if (!rootNode)
            return 0;

        TreeNode *left = rootNode->left;
        TreeNode *right = rootNode->right;

        return (maxDepth(left), maxDepth(right)) + 1;
    }

    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q)
            return true;

        else if (!p || !q)
            return false;

        return (p->val == q->val && isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right));
    }
};

#endif