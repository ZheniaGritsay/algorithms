#include "other.h"
#include "../binary_tree.h"
#include <queue>

void populate_next_right_pointer(TreeLinkNode* root)
{
    if (!root)
        return;

    std::queue<TreeLinkNode*> node_queue;
    node_queue.push(root);
    while (1)
    {
        size_t node_count = node_queue.size();
        if (node_count == 0)
            break;
        int supplement = 0;
        while (node_count > 0 && supplement < 4)
        {
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