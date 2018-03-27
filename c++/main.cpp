#include <iostream>
#include "binary-tree/other/other.h"
#include "binary-tree/construct/tree_construct.h"
#include "binary-tree/binary_tree.h"

int main() {

    int tree[] = {1, 2, 3, 4, 5, 6, 7};
    size_t  length = sizeof(tree) / sizeof(tree[0]);

    TreeLinkNode* root = construct_level_order(tree, root, 0, length);
    root->next = nullptr;

    populate_next_right_pointer(root);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}