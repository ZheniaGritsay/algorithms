#include "other.h"
#include <queue>
#include <sstream>
#include "../binary_tree.h"
#include "../construct/tree_construct.h"


void populate_next_right_pointer(TreeLinkNode* root)
{
    if (!root)
        return;

    std::queue<TreeLinkNode*> node_queue;
    node_queue.push(root);
    while (1) {
        size_t node_count = node_queue.size();
        if (node_count == 0)
            break;
        int supplement = 0;
        while (node_count > 0 && supplement < 4) {
            TreeLinkNode* link_node = node_queue.front();
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

std::string serialize(TreeNode* root)
{
    if (root == nullptr)
        return "[]";

    std::vector<std::string> node_vals;
    std::queue<TreeNode*> node_queue;
    node_queue.push(root);

    while (1)
    {
        size_t node_count = node_queue.size();
        if (node_count == 0)
            break;

        for (;node_count > 0; --node_count)
        {
            TreeNode* curr = node_queue.front();
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

    while (node_vals.back() == "null")
        node_vals.pop_back();

    for (auto it = node_vals.begin(); it != node_vals.end(); it++)
    {
        serialized += (*it);
        if (it != node_vals.end() - 1)
            serialized += ",";
    }

    serialized += "]";

    return serialized;
}

TreeNode* deserialize(std::string data)
{
    if (data.length() == 2)
        return nullptr;

    std::vector<std::string> splitted = split(data.substr(1, data.length() - 2), ',');

    std::queue<TreeNode*> node_queue;
    int v = std::stoi(splitted[0]);
    TreeNode* root = new TreeNode(v);
    node_queue.push(root);
    for (int i = 1; i < splitted.size(); i += 2)
    {
        TreeNode* curr = node_queue.front();
        node_queue.pop();

        if (splitted[i] != "null")
        {
            v = std::stoi(splitted[i]);
            TreeNode* left = new TreeNode(v);
            curr->left = left;
            node_queue.push(left);
        }

        if (i + 1 < splitted.size() && splitted[i + 1] != "null")
        {
            v = std::stoi(splitted[i + 1]);
            TreeNode* right = new TreeNode(v);
            curr->right = right;
            node_queue.push(right);
        }
    }

    return root;
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