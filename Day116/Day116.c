//Problem: Maximum Depth of Binary TreeFind the maximum depth (height) of a binary tree using recursion.
#include<stdio.h>
#include<stdlib.h>

struct Node{int val;struct Node*left,*right;};

struct Node* newNode(int v){
    struct Node*n=(struct Node*)malloc(sizeof(struct Node));
    n->val=v;n->left=n->right=NULL;
    return n;
}

int maxDepth(struct Node*root){
    if(!root)return 0;
    int l=maxDepth(root->left);
    int r=maxDepth(root->right);
    return 1+(l>r?l:r);
}

int main(){
    struct Node*root=newNode(3);
    root->left=newNode(9);
    root->right=newNode(20);
    root->right->left=newNode(15);
    root->right->right=newNode(7);
    printf("Maximum Depth: %d\n",maxDepth(root));
}