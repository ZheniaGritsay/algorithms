#ifndef C_OTHER_H
#define C_OTHER_H

#include <string>
#include <vector>

struct TreeNode;
struct TreeLinkNode;


void populate_next_right_pointer(TreeLinkNode* root);

std::vector<std::string> split(std::string line, char delimiter);

std::vector<int> convert_to_int(std::vector<std::string> vec);

std::string serialize(TreeNode* root);

TreeNode* deserialize(std::string data);

#endif //C_OTHER_H
