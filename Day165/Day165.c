//Problem Statement : Given the root of a Binary Search Tree (BST) and an integer val, search for the node whose value is equal to val.
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* insert(struct TreeNode *root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);

    return root;
}

struct TreeNode* searchBST(struct TreeNode *root, int val) {
    if (root == NULL || root->val == val)
        return root;

    if (val < root->val)
        return searchBST(root->left, val);

    return searchBST(root->right, val);
}

int main() {
    struct TreeNode *root = NULL;

    root = insert(root, 4);
    insert(root, 2);
    insert(root, 7);
    insert(root, 1);
    insert(root, 3);

    int key;
    printf("Enter value to search: ");
    scanf("%d", &key);

    struct TreeNode *result = searchBST(root, key);

    if (result != NULL)
        printf("Node found: %d\n", result->val);
    else
        printf("Node not found.\n");

    return 0;
}