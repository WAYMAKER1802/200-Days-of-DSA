//Problem: Symmetric Tree
//Check if a binary tree is mirror of itself (symmetric around center).
#include<stdio.h>
#include<stdlib.h>

struct Node{int val;struct Node*left,*right;};

struct Node* newNode(int v){
    struct Node*n=(struct Node*)malloc(sizeof(struct Node));
    n->val=v;n->left=n->right=NULL;
    return n;
}

int isMirror(struct Node*l,struct Node*r){
    if(!l&&!r)return 1;
    if(!l||!r)return 0;
    return l->val==r->val&&
           isMirror(l->left,r->right)&&
           isMirror(l->right,r->left);
}

int isSymmetric(struct Node*root){
    if(!root)return 1;
    return isMirror(root->left,root->right);
}

int main(){
    // Tree 1: symmetric
    struct Node*r1=newNode(1);
    r1->left=newNode(2);r1->right=newNode(2);
    r1->left->left=newNode(3);r1->left->right=newNode(4);
    r1->right->left=newNode(4);r1->right->right=newNode(3);
    printf("Tree 1: %s\n",isSymmetric(r1)?"Symmetric":"Not Symmetric");

    // Tree 2: not symmetric
    struct Node*r2=newNode(1);
    r2->left=newNode(2);r2->right=newNode(2);
    r2->left->right=newNode(3);r2->right->right=newNode(3);
    printf("Tree 2: %s\n",isSymmetric(r2)?"Symmetric":"Not Symmetric");
}