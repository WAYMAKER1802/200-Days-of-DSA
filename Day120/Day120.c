//Problem: Maximum Subarray (Kadane's Algorithm)
//Find the contiguous subarray with the largest sum.
#include<stdio.h>

int main(){
    int a[]={-2,1,-3,4,-1,2,1,-5,4},n=9;
    int maxSum=a[0],curSum=a[0];
    int start=0,end=0,tempStart=0;
    for(int i=1;i<n;i++){
        if(a[i]>curSum+a[i]){
            curSum=a[i];
            tempStart=i;
        } else curSum+=a[i];
        if(curSum>maxSum){
            maxSum=curSum;
            start=tempStart;
            end=i;
        }
    }
    printf("Maximum Subarray Sum: %d\n",maxSum);
    printf("Subarray: ");
    for(int i=start;i<=end;i++)printf("%d ",a[i]);
}