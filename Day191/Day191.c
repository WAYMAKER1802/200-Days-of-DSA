//Question : Given the root of a binary tree, find its minimum depth.
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node. A leaf is a node with no children.
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create a new node
struct TreeNode* createNode(int value)
{
    struct TreeNode* newNode =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Find minimum depth
int minDepth(struct TreeNode* root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL)
        return 1 + minDepth(root->right);

    if (root->right == NULL)
        return 1 + minDepth(root->left);

    int left = minDepth(root->left);
    int right = minDepth(root->right);

    if (left < right)
        return 1 + left;
    else
        return 1 + right;
}

int main()
{
    /*
          3
         / \
        9   20
           /  \
          15   7
    */

    struct TreeNode* root = createNode(3);

    root->left = createNode(9);
    root->right = createNode(20);

    root->right->left = createNode(15);
    root->right->right = createNode(7);

    int answer = minDepth(root);

    printf("Minimum Depth = %d\n", answer);

    return 0;
}