#ifndef C_TREE_TRAVERSAL_H
#define C_TREE_TRAVERSAL_H

#include <vector>

struct TreeNode;


std::vector<int> in_order_traversal(TreeNode* root);

std::vector<int> pre_order_traversal(TreeNode* root);

std::vector<int> post_order_traversal(TreeNode* root);

template <typename vector>
std::vector<vector<int>> level_order_traversal(TreeNode* root);

std::vector<int> morris_in_order_traversal(TreeNode* root);

std::vector<int> morris_pre_order_traversal(TreeNode* root);

#endif //C_TREE_TRAVERSAL_H
