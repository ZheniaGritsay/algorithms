#include <iostream>
#include "binary-tree/other/other.h"

int main() {

    std::string str = "[1,2,3,null,null,4,5]";

    TreeNode *root = deserialize(str);

    std::string ser = serialize(root);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}