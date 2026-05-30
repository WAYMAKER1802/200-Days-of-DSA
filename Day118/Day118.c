//Problem: Binary Tree Path Sum
//Given a binary tree and a target sum, check if there exists a root-to-leaf path whose sum equals target.
#include<stdio.h>
#include<stdlib.h>

struct Node{int val;struct Node*left,*right;};

struct Node* newNode(int v){
    struct Node*n=(struct Node*)malloc(sizeof(struct Node));
    n->val=v;n->left=n->right=NULL;
    return n;
}

int hasPath(struct Node*root,int target){
    if(!root)return 0;
    target-=root->val;
    if(!root->left&&!root->right)return target==0;
    return hasPath(root->left,target)||
           hasPath(root->right,target);
}

int main(){
    struct Node*root=newNode(5);
    root->left=newNode(4);
    root->right=newNode(8);
    root->left->left=newNode(11);
    root->right->left=newNode(13);
    root->right->right=newNode(4);
    root->left->left->left=newNode(7);
    root->left->left->right=newNode(2);
    root->right->right->right=newNode(1);

    printf("Target=22: %s\n",hasPath(root,22)?"Yes":"No");
    printf("Target=27: %s\n",hasPath(root,27)?"Yes":"No");
}