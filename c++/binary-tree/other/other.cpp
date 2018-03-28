#include "other.h"
#include "../binary_tree.h"
#include "../construct/tree_construct.h"
#include <queue>
#include <sstream>

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

std::vector<int> convert_to_int(std::vector<std::string> vec)
{

    std::vector<int> converted;
    int val;
    for (std::string& s : vec)
    {
        std::stringstream ss(s);

        ss >> val;
        converted.push_back(val);
    }

    return converted;
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

TreeNode *lvl_order(int arr[], TreeNode *root, int i, int n)
{
    if (i < n)
    {
        TreeNode *tmp = new TreeNode(arr[i]);
        root = tmp;

        root->left = lvl_order(arr, root->left, i * 2 + 1, n);
        root->right = lvl_order(arr, root->right, i * 2 + 2, n);
    }

    return root;
}

std::string serialize(TreeNode *root)
{

}

TreeNode *deserialize(std::string data)
{
    std::vector<std::string> splitted = split(data, ',');
    std::vector<int> nums = convert_to_int(splitted);

    TreeNode *root = lvl_order(&nums[0], root, 0, nums.size());

    return root;
}