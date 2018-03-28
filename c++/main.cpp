#include <iostream>
#include "binary-tree/other/other.h"
#include "binary-tree/construct/tree_construct.h"
#include "binary-tree/binary_tree.h"
#include "binary-tree/other/other.h"

int main() {

//    int tree[] = {1, 2, 3, 4, 5, 6, 7};
//    size_t  length = sizeof(tree) / sizeof(tree[0]);
//
//    TreeLinkNode* root = construct_level_order(tree, root, 0, length);
//    root->next = nullptr;
//
//    populate_next_right_pointer(root);

    std::string str = "1,2,3,5,7,4,5";

    deserialize(str);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}