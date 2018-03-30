#include "other.h"
#include "../binary_tree.h"
#include "../construct/tree_construct.h"
#include <queue>
#include <sstream>
#include <iostream>

void populate_next_right_pointer(TreeLinkNode *root)
{
    if (!root)
        return;

    std::queue<TreeLinkNode *> node_queue;
    node_queue.push(root);
    while (1) {
        size_t node_count = node_queue.size();
        if (node_count == 0)
            break;
        int supplement = 0;
        while (node_count > 0 && supplement < 4) {
            TreeLinkNode *link_node = node_queue.front();
            node_queue.pop();

            if (node_count > 1)
                link_node->next = node_queue.front();

            if (link_node->left)
                node_queue.push(link_node->left);
            if (link_node->right)
                node_queue.push(link_node->right);

            node_count--;
        }
    }
}

std::vector<std::string> split(std::string line, char delimiter)
{
    std::vector<std::string> splitted;

    std::stringstream str_s(line);
    std::string str;
    while (std::getline(str_s, str, delimiter))
    {
        splitted.push_back(str);
    }

    return splitted;
}

TreeNode *lvl_order_deser(std::vector<std::string> vals, TreeNode *root, int i, int n)
{
    if (i < n)
    {
        std::string s = vals[i];
        int v = std::stoi(s);

        TreeNode *tmp = new TreeNode(v);
        root = tmp;

        TreeNode* left_node = nullptr;
        TreeNode* right_node = nullptr;
        int ileft = i * 2 + 1;
        int iright = ileft + 1;

        if (ileft < n && vals[ileft] != "null")
        {
            left_node = lvl_order_deser(vals, root->left, ileft, n);
        }
        if (iright < n && vals[iright] != "null")
        {
            right_node = lvl_order_deser(vals, root->right, iright, n);
        }

        root->left = left_node;
        root->right = right_node;
    }

    return root;
}

std::string lvl_order_ser(TreeNode *root)
{
    std::vector<std::string> node_vals;
    std::queue<TreeNode *> node_queue;
    node_queue.push(root);

    while (1)
    {
        size_t node_count = node_queue.size();
        if (node_count == 0)
            break;

        for (;node_count > 0; --node_count)
        {
            TreeNode *curr = node_queue.front();
            node_queue.pop();

            if (curr)
                node_vals.push_back(std::to_string(curr->val));
            else
            {
                node_vals.push_back("null");
                continue;
            }

            node_queue.push(curr->left);
            node_queue.push(curr->right);
        }
    }

    std::string serialized = "[";

    for (auto it = node_vals.begin(); it != (node_vals.end() - 4); it++)
    {
        serialized += (*it);
        if (it != (node_vals.end() - 5))
            serialized += ",";
    }

    serialized += "]";

    return serialized;
}

std::string serialize(TreeNode *root)
{
    if (root == nullptr)
        return "[]";

    return lvl_order_ser(root);
}

TreeNode *deserialize(std::string data)
{
    if (data.size() == 0)
        return nullptr;

    std::vector<std::string> splitted = split(data.substr(1, data.length() - 2), ',');
    TreeNode *root = lvl_order_deser(splitted, root, 0, splitted.size());

    return root;
}