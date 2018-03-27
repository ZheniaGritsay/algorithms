#ifndef C_OTHER_H
#define C_OTHER_H

struct TreeNode;
struct TreeLinkNode;

void populate_next_right_pointer(TreeLinkNode* root);

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

#endif //C_OTHER_H
