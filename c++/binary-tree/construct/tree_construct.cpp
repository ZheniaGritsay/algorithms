#include "tree_construct.h"
#include "../binary_tree.h"

TreeLinkNode* construct_level_order(int arr[], TreeLinkNode* root, int i, int n)
{
    if (i < n)
    {
        TreeLinkNode* temp = new TreeLinkNode(arr[i]);
        root = temp;

        root->left = construct_level_order(arr, root->left, i * 2 + 1, n);
        root->right = construct_level_order(arr, root->right, i * 2 + 2, n);
    }

    return root;
}