#ifndef C_TREE_TRAVERSAL_H
#define C_TREE_TRAVERSAL_H

#include <vector>

struct TreeNode;


std::vector<int> inorder_traversal(TreeNode* root);

std::vector<int> preorder_traversal(TreeNode* root);

std::vector<int> postorder_traversal(TreeNode* root);

// TODO: make return type vector<vector<int>>
void level_order_traversal(TreeNode* root);

std::vector<int> morris_inorder_traversal(TreeNode* root);

std::vector<int> morris_preorder_traversal(TreeNode* root);

#endif //C_TREE_TRAVERSAL_H
