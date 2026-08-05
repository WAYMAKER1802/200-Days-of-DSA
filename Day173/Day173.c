//Problem : Given a binary tree, find the Lowest Common Ancestor (LCA) of two given nodes


#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* buildTree()
{
    int val;
    scanf("%d", &val);

    if(val == -1)
        return NULL;

    struct Node* root = createNode(val);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

struct Node* lowestCommonAncestor(struct Node* root, int n1, int n2)
{
    if(root == NULL)
        return NULL;

    if(root->data == n1 || root->data == n2)
        return root;

    struct Node* left = lowestCommonAncestor(root->left, n1, n2);
    struct Node* right = lowestCommonAncestor(root->right, n1, n2);

    if(left != NULL && right != NULL)
        return root;

    if(left != NULL)
        return left;

    return right;
}

int main()
{
    printf("Enter tree in preorder (-1 for NULL):\n");

    struct Node* root = buildTree();

    int n1, n2;

    printf("Enter two node values: ");
    scanf("%d %d", &n1, &n2);

    struct Node* ans = lowestCommonAncestor(root, n1, n2);

    if(ans != NULL)
        printf("Lowest Common Ancestor = %d\n", ans->data);
    else
        printf("Nodes not found.\n");

    return 0;
}