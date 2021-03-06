#include "tree_traversal.h"
#include <stack>
#include <queue>
#include "../binary_tree.h"

using namespace std;

vector<int> inorder_traversal(TreeNode* root)
{
    vector<int> node_vals;
    stack<TreeNode*> node_stack;
    TreeNode* curr = root;
    bool done = false;

    while (!done) {
        if (curr != nullptr) {
            node_stack.push(curr);
            curr = curr->left;
        } else {
            if (!node_stack.empty()) {
                TreeNode* top = node_stack.top();
                node_stack.pop();
                node_vals.push_back(top->val);
                curr = top->right;
            } else {
                done = true;
            }
        }
    }

    return node_vals;
}

vector<int> preorder_traversal(TreeNode* root)
{
    vector<int> node_vals;
    stack<TreeNode*> node_stack;
    node_stack.push(root);

    while (!node_stack.empty()) {
        TreeNode* top = node_stack.top();
        node_stack.pop();
        node_vals.push_back(top->val);

        if (top->right)
            node_stack.push(top->right);
        if (top->left)
            node_stack.push(top->left);
    }

    return node_vals;
}

vector<int> postorder_traversal(TreeNode* root)
{
    vector<int> node_vals;
    stack<TreeNode*> node_stack;
    TreeNode* curr = root;
    bool done = false;

    while (!done) {
        if (curr != nullptr) {
            if (curr->right)
                node_stack.push(curr->right);

            node_stack.push(curr);

            curr = curr->left;
        } else {
            if (!node_stack.empty()) {
                TreeNode* top = node_stack.top();
                node_stack.pop();
                if (top->right && !node_stack.empty() && top->right == node_stack.top()) {
                    TreeNode* right_child = node_stack.top();
                    node_stack.pop();
                    node_stack.push(top);
                    curr = right_child;
                } else {
                    node_vals.push_back(top->val);
                    curr = nullptr;
                }
            } else {
                done = true;
            }
        }
    }

    return node_vals;
}


void level_order_traversal(TreeNode* root)
{
    vector<vector<int>> node_vals;
    queue<TreeNode*> node_queue;
    node_queue.push(root);

    while (1) {
        size_t node_count = node_queue.size();
        if (node_count == 0)
            break;

        vector<int> lvl_vals;
        while (node_count > 0) {
            TreeNode* node = node_queue.front();
            node_queue.pop();
            lvl_vals.push_back(node->val);

            if (node->left)
                node_queue.push(node->left);
            if (node->right)
                node_queue.push(node->right);

            node_count--;
        }

        node_vals.push_back(lvl_vals);
    }

//    return node_vals;
}

vector<int> morris_inorder_traversal(TreeNode* root)
{
    vector<int> node_vals;

    if (!root)
        return node_vals;

    TreeNode* curr = root;
    while (curr != nullptr) {
        if (curr->left == nullptr) {
            node_vals.push_back(curr->val);
            curr = curr->right;
        } else {
            TreeNode* predecessor = curr->left;
            while (predecessor->right != nullptr && predecessor->right != curr)
                predecessor = predecessor->right;

            if (predecessor->right == nullptr) {
                predecessor->right = curr;
                curr = curr->left;
            } else {
                node_vals.push_back(curr->val);
                predecessor->right = nullptr;
                curr = curr->right;
            }
        }
    }

    return node_vals;
}

vector<int> morris_preorder_traversal(TreeNode* root)
{
    vector<int> node_vals;

    if (!root)
        return node_vals;

    TreeNode* curr = root;
    while (curr) {
        if (curr->left == nullptr) {
            node_vals.push_back(curr->val);
            curr = curr->right;
        } else {
            TreeNode* predecessor = curr->left;
            while (predecessor->right && predecessor->right != curr)
                predecessor = predecessor->right;

            if (predecessor->right == curr) {
                predecessor->right = nullptr;
                curr = curr->right;
            } else {
                node_vals.push_back(curr->val);
                predecessor->right = curr;
                curr = curr->left;
            }
        }
    }

    return node_vals;
}