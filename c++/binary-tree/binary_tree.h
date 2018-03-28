#ifndef C_BINARY_TREE_H
#define C_BINARY_TREE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;

    TreeLinkNode(int v) : val(v), left(nullptr), right(nullptr), next(nullptr) {}
};

#endif //C_BINARY_TREE_H
