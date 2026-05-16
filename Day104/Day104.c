//Problem: Insert, Search & Delete in BST
//Implement a BST with insert, search, and delete operations. Print inorder traversal after each operation.
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
struct Node* minNode(struct Node*root){
    while(root->left)root=root->left;
    return root;
}
struct Node* delete(struct Node*root,int v){
    if(!root)return NULL;
    if(v<root->val)root->left=delete(root->left,v);
    else if(v>root->val)root->right=delete(root->right,v);
    else{
        if(!root->left)return root->right;
        if(!root->right)return root->left;
        struct Node*mn=minNode(root->right);
        root->val=mn->val;
        root->right=delete(root->right,mn->val);
    }
    return root;
}
int search(struct Node*root,int v){
    if(!root)return 0;
    if(root->val==v)return 1;
    return v<root->val?search(root->left,v):search(root->right,v);
}
void inorder(struct Node*root){
    if(!root)return;
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}
int main(){
    struct Node*root=NULL;
    int a[]={50,30,70,20,40,60,80},n=7;
    for(int i=0;i<n;i++)root=insert(root,a[i]);
    printf("Inorder after insert: ");inorder(root);
    root=delete(root,30);
    printf("\nInorder after delete 30: ");inorder(root);
    printf("\nSearch 40: %s\n",search(root,40)?"Found":"Not Found");
}