#include "tree_construct.h"
#include <queue>
#include "../binary_tree.h"

typedef std::vector<int>::iterator vec_it;
typedef std::vector<int>::const_iterator const_vec_it;

TreeNode* construct_from_inorder_postorder(std::vector<int>& inorder, std::vector<int>& postorder)
{
    if (inorder.empty())
        return nullptr;

    TreeNode* node = new TreeNode(postorder.back());
    postorder.pop_back();

    if (inorder.size() == 1)
        return node;

    size_t i_inorder = search(inorder, node->val);

    const_vec_it start = inorder.begin();
    const_vec_it left_last = inorder.begin() + i_inorder;
    const_vec_it right_last = inorder.end();

    std::vector<int> right_subtree(left_last + 1, right_last);
    std::vector<int> left_subtree(start, left_last);

    node->right = construct_from_inorder_postorder(right_subtree, postorder);
    node->left = construct_from_inorder_postorder(left_subtree, postorder);

    return node;
}

TreeNode* construct_from_preorder_inorder(std::vector<int>& inorder, std::vector<int>& postorder)
{
    if (inorder.empty())
        return nullptr;

    TreeNode* node = new TreeNode(postorder.front());
    postorder.erase(postorder.begin());

    if (inorder.size() == 1)
        return node;

    size_t i_inorder = search(inorder, node->val);

    const_vec_it start = inorder.begin();
    const_vec_it left_last = inorder.begin() + i_inorder;
    const_vec_it right_last = inorder.end();

    std::vector<int> right_subtree(left_last + 1, right_last);
    std::vector<int> left_subtree(start, left_last);

    node->left = construct_from_inorder_postorder(left_subtree, postorder);
    node->right = construct_from_inorder_postorder(right_subtree, postorder);

    return node;
}

TreeLinkNode* construct_level_order(int arr[], TreeLinkNode* root, int i, int n)
{
    if (i < n) {
        TreeLinkNode* temp = new TreeLinkNode(arr[i]);
        root = temp;

        root->left = construct_level_order(arr, root->left, i * 2 + 1, n);
        root->right = construct_level_order(arr, root->right, i * 2 + 2, n);
    }

    return root;
}

size_t search(std::vector<int> &v, int val)
{
    size_t index;
    for (vec_it it = v.begin(); it != v.end(); ++it) {
        if (*it == val) {
            index = static_cast<size_t >(it - v.begin());
            break;
        }
    }

    return index;
}