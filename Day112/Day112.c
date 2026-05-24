//Problem: Level Order Traversal of Binary Tree
//Print nodes of a binary tree level by level using BFS/Queue.
#include<stdio.h>
#include<stdlib.h>

struct Node{int val;struct Node*left,*right;};

struct Node* newNode(int v){
    struct Node*n=(struct Node*)malloc(sizeof(struct Node));
    n->val=v;n->left=n->right=NULL;
    return n;
}

void levelOrder(struct Node*root){
    if(!root)return;
    struct Node*q[100];
    int f=0,r=0,level=1;
    q[r++]=root;
    while(f<r){
        int sz=r-f;
        printf("Level %d: ",level++);
        for(int i=0;i<sz;i++){
            struct Node*cur=q[f++];
            printf("%d ",cur->val);
            if(cur->left)q[r++]=cur->left;
            if(cur->right)q[r++]=cur->right;
        }
        printf("\n");
    }
}

int main(){
    struct Node*root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    levelOrder(root);
}