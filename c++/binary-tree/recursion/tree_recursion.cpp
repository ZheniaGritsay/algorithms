#include "tree_recursion.h"
#include "../binary_tree.h"

TreeNode *find_lca(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
        return nullptr;

    if (root->val == p->val || root->val == q->val)
        return root;

    TreeNode *left_lca = find_lca(root->left, p, q);
    TreeNode *right_lca = find_lca(root->right, p, q);

    if (left_lca && right_lca)
        return root;

    return (left_lca != nullptr) ? left_lca : right_lca;
}