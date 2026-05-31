//Problem: Lowest Common Ancestor of BST
//Find the LCA of two nodes in a BST.
#include<stdio.h>
#include<stdlib.h>

struct Node{int val;struct Node*left,*right;};

struct Node* newNode(int v){
    struct Node*n=(struct Node*)malloc(sizeof(struct Node));
    n->val=v;n->left=n->right=NULL;
    return n;
}
struct Node* insert(struct Node*root,int v){
    if(!root)return newNode(v);
    if(v<root->val)root->left=insert(root->left,v);
    else root->right=insert(root->right,v);
    return root;
}

struct Node* lca(struct Node*root,int p,int q){
    if(!root)return NULL;
    if(p<root->val&&q<root->val)
        return lca(root->left,p,q);
    if(p>root->val&&q>root->val)
        return lca(root->right,p,q);
    return root;
}

int main(){
    struct Node*root=NULL;
    int a[]={6,2,8,0,4,7,9,3,5},n=9;
    for(int i=0;i<n;i++)root=insert(root,a[i]);

    printf("LCA(2,8): %d\n",lca(root,2,8)->val);
    printf("LCA(2,4): %d\n",lca(root,2,4)->val);
}