#ifndef C_TREE_CONSTRUCT_H
#define C_TREE_CONSTRUCT_H

#include <vector>
#include <cstddef>

struct TreeNode;
struct TreeLinkNode;

size_t search(std::vector<int>& v, int val);

TreeNode* construct_from_inorder_postorder(std::vector<int>& inorder, std::vector<int>& postorder);

TreeNode* construct_from_preorder_inorder(std::vector<int>& preorder, std::vector<int>& inorder);

TreeLinkNode* construct_level_order(int arr[], TreeLinkNode* root, int i, int n);

#endif //C_TREE_CONSTRUCT_H
