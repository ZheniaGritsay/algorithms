#ifndef C_TREE_RECURSION_H
#define C_TREE_RECURSION_H

struct TreeNode;

int max_depth(TreeNode* root);

bool is_symmetric_tree(TreeNode* root);

bool has_path_sum(int sum);

TreeNode* find_lca(TreeNode* root, TreeNode* p, TreeNode* q);

#endif //C_TREE_RECURSION_H
