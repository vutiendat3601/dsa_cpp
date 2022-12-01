#include <iostream>
#include <algorithm>
#include <vector>

#include "../tree/TreeNode.h"

int oldRes = 0;

int rob(TreeNode *root)
{
    std::vector<int> res = process(root);
    return res[0];
}

std::vector<int> process(TreeNode *root)
{
    if (root == nullptr)
    {
        return std::vector<int>{0, 0};
    }
    if (!root->left && !root->right)
    {
        return std::vector<int>{root->value, 0};
    }
    std::vector<int> left = process(root->left);
    std::vector<int> right = process(root->right);
    int temp = left[0] + right[0];
    int oldRes = left[1] + right[1];
    int res = std::max(root->value + oldRes, temp);
    oldRes = temp;
    return std::vector<int>{res, oldRes};
}

int main()
{
    TreeNode *root = new TreeNode{1, nullptr, nullptr};
    root->left = new TreeNode{4, nullptr, nullptr};
    root->right = new TreeNode{5, nullptr, nullptr};

    root->left->left = new TreeNode{1, nullptr, nullptr};
    root->left->right = new TreeNode{3, nullptr, nullptr};
    root->right->right = new TreeNode{1, nullptr, nullptr};

    int res = rob(root);
    std::cout << res << std::endl;
}