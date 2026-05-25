//Problem: Diameter of Binary Tree
//Find the longest path between any two nodes in a binary tree.
#include<stdio.h>
#include<stdlib.h>

struct Node{int val;struct Node*left,*right;};

struct Node* newNode(int v){
    struct Node*n=(struct Node*)malloc(sizeof(struct Node));
    n->val=v;n->left=n->right=NULL;
    return n;
}

int dia=0;

int height(struct Node*root){
    if(!root)return 0;
    int l=height(root->left);
    int r=height(root->right);
    if(l+r>dia)dia=l+r;
    return 1+(l>r?l:r);
}

int main(){
    struct Node*root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    dia=0;
    height(root);
    printf("Diameter: %d\n",dia);
}