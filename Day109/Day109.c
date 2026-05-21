//Problem: Longest Consecutive Sequence
//Given an unsorted array, find the length of the longest consecutive elements sequence in O(n) using a HashSet.
#include<stdio.h>

int main(){
    int a[]={100,4,200,1,3,2},n=6;
    int mx=0;
    // use visited array as hash
    int hash[1001]={0};
    for(int i=0;i<n;i++)if(a[i]<=1000)hash[a[i]]=1;
    for(int i=0;i<n;i++){
        // only start counting if a[i]-1 not present
        if(a[i]>0&&!hash[a[i]-1]){
            int cur=a[i],len=1;
            while(cur+1<=1000&&hash[cur+1]){cur++;len++;}
            if(len>mx)mx=len;
        }
    }
    printf("Longest Consecutive Sequence: %d\n",mx);
}