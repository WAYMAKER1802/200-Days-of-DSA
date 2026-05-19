//Problem: Validate BST & Find Kth SmallestGiven a BST, 
// check if it is valid and find the Kth smallest element using inorder traversal.
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

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

// Validate BST
int isValid(struct Node*root,long mn,long mx){
    if(!root)return 1;
    if(root->val<=mn||root->val>=mx)return 0;
    return isValid(root->left,mn,root->val)&&
           isValid(root->right,root->val,mx);
}

// Kth smallest using inorder
int cnt=0,res=-1;
void kthSmallest(struct Node*root,int k){
    if(!root||res!=-1)return;
    kthSmallest(root->left,k);
    if(++cnt==k){res=root->val;return;}
    kthSmallest(root->right,k);
}

int main(){
    struct Node*root=NULL;
    int a[]={5,3,7,2,4,6,8},n=7;
    for(int i=0;i<n;i++)root=insert(root,a[i]);

    printf("Is Valid BST: %s\n",
        isValid(root,LONG_MIN,LONG_MAX)?"Yes":"No");

    int k=3;
    cnt=0;res=-1;
    kthSmallest(root,k);
    printf("Kth Smallest (k=%d): %d\n",k,res);
}