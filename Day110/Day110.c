//Problem: Two Sum
//Given an array and a target, find indices of two numbers that add up to target using a HashMap in O(n).
#include<stdio.h>

int main(){
    int a[]={2,7,11,15},n=4,target=9;
    int map[20001]={0}; // map[val+10000]=index+1
    for(int i=0;i<n;i++){
        int comp=target-a[i];
        if(comp>=-10000&&comp<=10000&&map[comp+10000]){
            printf("Indices: %d %d\n",map[comp+10000]-1,i);
            return 0;
        }
        map[a[i]+10000]=i+1;
    }
    printf("No solution\n");
}