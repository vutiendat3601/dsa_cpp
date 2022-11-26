#include <iostream>

/*
 Binary Tree
*/

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
};

void insertNode(TreeNode **, int);
void deleteNode(TreeNode **, int);

void preorderRecursive(TreeNode *);
void inorderRecursive(TreeNode *);
void postorderRecursive(TreeNode *);

void preorderStack(TreeNode *);
void inorderStack(TreeNode *);
void postorderStack(TreeNode *);
