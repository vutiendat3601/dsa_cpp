#include <stack>
#include "TreeNode.h"

int main()
{
    // TreeNode *root = new TreeNode{1, nullptr, nullptr};
    // root->left = new TreeNode{2, nullptr, nullptr};
    // root->right = new TreeNode{3, nullptr, nullptr};
    // root->left->left = new TreeNode{4, nullptr, nullptr};
    // root->left->right = new TreeNode{5, nullptr, nullptr};
    TreeNode *root = new TreeNode{3, nullptr, nullptr};
    root->left = new TreeNode{2, nullptr, nullptr};
    root->right = new TreeNode{4, nullptr, nullptr};
    root->right->left = new TreeNode{1, nullptr, nullptr};
    inorderRecursive(root);
    // preorderRecursive(root);
    // postorderRecursive(root);
    // postorderStack(root);
    // preorderStack(root);
    inorderStack(root);
    std::cout << "End program." << std::endl;
}

/*
 * Operations
 */

void insertNode(TreeNode **root, int value)
{
    if (*root == nullptr)
    {
        TreeNode *node = new TreeNode{value, nullptr, nullptr};
        *root = node;
    }
    else
    {
        if (value < (*root)->value)
        {
            insertNode(&(*root)->left, value);
        }
        else if (value > (*root)->value)
        {
            insertNode(&(*root)->right, value);
        }
        else
        {
            std::cout << "Node is existed!" << std::endl;
        }
    }
}

TreeNode *findDeepestLeftNode(TreeNode *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

void deleteNode(TreeNode **root, int key)
{
    if (*root != nullptr)
    {
        if (key < (*root)->value)
        {
            deleteNode(&(*root)->left, key);
        }
        else if (key > (*root)->value)
        {
            deleteNode(&(*root)->right, key);
        }
        else
        {
            if ((*root)->left == nullptr)
            {
                *root = (*root)->right;
            }
            else if ((*root)->right == nullptr)
            {
                *root = (*root)->left;
            }
            else
            {
                TreeNode *target = findDeepestLeftNode((*root)->right);
                (*root)->value = target->value;
                deleteNode(&(*root)->right, target->value);
            }
        }
    }
}

/*
 * Traversals
 */

void performInorderRecursive(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    // visit left
    performInorderRecursive(root->left);

    // visit root
    std::cout << root->value << " ";

    // visit right
    performInorderRecursive(root->right);
}

void performPreorderRecursive(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    // visit root
    std::cout << root->value << " ";

    // visit left
    performPreorderRecursive(root->left);

    // visit right
    performPreorderRecursive(root->right);
}

void performPostorderRecursive(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    // visit left
    performPostorderRecursive(root->left);

    // visit right
    performPostorderRecursive(root->right);

    // visit root
    std::cout << root->value << " ";
}

void performPreorderStack(TreeNode *root)
{
    std::stack<TreeNode *> s;
    s.push(root);
    while (!s.empty())
    {
        TreeNode *curNode = s.top();
        std::cout << curNode->value << " ";
        s.pop();

        if (curNode->right)
        {
            s.push(curNode->right);
        }
        if (curNode->left)
        {
            s.push(curNode->left);
        }
    }
}

void performInorderStack(TreeNode *root)
{
    std::stack<TreeNode *> s;
    s.push(root);
    TreeNode *preNode = new TreeNode{-1, root, nullptr};
    while (!s.empty())
    {
        TreeNode *curNode = s.top();
        s.pop();
        if (preNode->left == curNode || preNode->right == curNode)
        {
            if (curNode->right)
            {
                s.push(curNode->right);
            }
            s.push(curNode);
            if (curNode->left)
            {
                s.push(curNode->left);
            }
        }
        else
        {
            std::cout << curNode->value << " ";
        }
        preNode = curNode;
    }
}

void performPostorderStack(TreeNode *root)
{
    std::stack<TreeNode *> s;
    s.push(root);
    TreeNode *preNode = nullptr;

    while (!s.empty())
    {
        TreeNode *curNode = s.top();
        // From Top to down
        if (preNode == nullptr || preNode->left == curNode || preNode->right == curNode)
        {
            if (curNode->left)
            {
                s.push(curNode->left);
            }
            else if (curNode->right)
            {
                s.push(curNode->right);
            }
            else
            {
                s.pop();
                std::cout << curNode->value << " ";
            }
        }
        // From deepest left to right
        else if (curNode->left == preNode)
        {
            if (curNode->right)
            {
                s.push(curNode->right);
            }
            else
            {
                s.pop();
                std::cout << curNode->value << " ";
            }
        }
        // From deepest right to node
        else if (curNode->right == preNode)
        {
            s.pop();
            std::cout << curNode->value << " ";
        }
        preNode = curNode;
    }
}

/*
 * Traversal APIs
 */

// Recursive

void preorderRecursive(TreeNode *root)
{
    std::cout << "Preorder recursive: ";
    performPreorderRecursive(root);
    std::cout << std::endl;
}

void inorderRecursive(TreeNode *root)
{
    std::cout << "Inorder recursive: ";
    performInorderRecursive(root);
    std::cout << std::endl;
}

void postorderRecursive(TreeNode *root)
{
    std::cout << "Postorder recursive: ";
    performPostorderRecursive(root);
    std::cout << std::endl;
}

// Stack

void postorderStack(TreeNode *root)
{
    std::cout << "Postorder stack: ";
    performPostorderStack(root);
    std::cout << std::endl;
}

void inorderStack(TreeNode *root)
{
    std::cout << "Inorder stack: ";
    performInorderStack(root);
    std::cout << std::endl;
}

void preorderStack(TreeNode *root)
{
    std::cout << "Preorder stack: ";
    performPreorderStack(root);
    std::cout << std::endl;
}