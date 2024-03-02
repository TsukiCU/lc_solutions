#include "tree.h"

TreeNode* ConstructTree(const vector<int>& order)
{
    if (order.empty() || order[0] == INT_MIN) return nullptr;

    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(order[0]);
    q.push(root);
    int i = 1;

    while (!q.empty() && i < order.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < order.size() && order[i] != INT_MIN) {
            current->left = new TreeNode(order[i]);
            q.push(current->left);
        }
        i++;

        if (i < order.size() && order[i] != INT_MIN) {
            current->right = new TreeNode(order[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int main()
{
    vector<int> list_1 = {3,9,20,NULL,NULL,15,7};
    vector<int> list_2 = {1,2,2,3,4,4,3};
    TreeNode *p = ConstructTree(list_1);
    TreeNode *q = ConstructTree(list_2);

    Tree_ops ops;
    cout << "Max depth of tree p is: " << ops.maxDepth(p) << endl;
}