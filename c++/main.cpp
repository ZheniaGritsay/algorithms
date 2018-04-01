#include <iostream>
#include "binary-tree/other/other.h"
#include "binary-tree/construct/tree_construct.h"
#include "binary-tree/binary_tree.h"


int main() {

//    std::string str = "[1,2,3,null,null,4,5]";
    std::string str = "[5,2,3,null,null,2,4,3,1]";
    int arr_tree[] = {5, 2, 3, 2, 4, 3, 1};
    int len = sizeof(arr_tree) / sizeof(arr_tree[0]);
    TreeNode* root = ser_level_order(arr_tree, len);
//    TreeNode *root = deserialize(str);
    /*
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);
    root->right->left->left = new TreeNode(3);
    root->right->left->right = new TreeNode(1);
    */
//    std::string ser = serialize(root);

//    std::cout << ser << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}