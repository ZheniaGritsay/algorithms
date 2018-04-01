#include <queue>
#include <climits>

#include "tree_construct.h"
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

// FIXME
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

TreeNode* ser_level_order(int arr[], int n)
{
    if (n == 0)
        return NULL;

    TreeNode* root;

    std::queue<NodeDetails> q;

    int i = 0;

    NodeDetails newNode;
    newNode.ptr = new TreeNode(arr[i++]);
    newNode.min = INT_MIN;
    newNode.max = INT_MAX;
    q.push(newNode);

    root = newNode.ptr;

    // 5, 2, 3, 2, 4, 3, 1

    while (i != n)
    {
        NodeDetails temp = q.front();
        q.pop();

        if (i < n && (arr[i] < temp.ptr->val &&
                      arr[i] > temp.min))
        {
            newNode.ptr = new TreeNode(arr[i++]);
            newNode.min = temp.min;
            newNode.max = temp.ptr->val;
            q.push(newNode);

            temp.ptr->left = newNode.ptr;
        }

        if (i < n && (arr[i] > temp.ptr->val &&
                      arr[i] < temp.max))
        {
            newNode.ptr = new TreeNode(arr[i++]);
            newNode.min = temp.ptr->val;
            newNode.max = temp.max;
            q.push(newNode);

            temp.ptr->right = newNode.ptr;
        }
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