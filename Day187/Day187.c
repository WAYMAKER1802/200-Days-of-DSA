//Question: Path Sum
//Given a binary tree and an integer targetSum, determine whether the tree has a root-to-leaf path such that the sum of all node values along the path is equal to 
// targetSum. A leaf is a node that has no left or right child.
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int value)
{
    struct TreeNode *newNode =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct TreeNode* buildTree(int arr[], int n)
{
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct TreeNode *root = createNode(arr[0]);

    struct TreeNode **queue =
        (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));

    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    int i = 1;

    while (i < n && front < rear)
    {
        struct TreeNode *current = queue[front++];

        // Left child
        if (i < n && arr[i] != -1)
        {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1)
        {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    free(queue);

    return root;
}

int hasPathSum(struct TreeNode *root, int targetSum)
{
    if (root == NULL)
        return 0;

    // If leaf node
    if (root->left == NULL && root->right == NULL)
    {
        return targetSum == root->val;
    }

    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter tree elements (-1 for NULL):\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int targetSum;

    printf("Enter target sum: ");
    scanf("%d", &targetSum);

    struct TreeNode *root = buildTree(arr, n);

    if (hasPathSum(root, targetSum))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}