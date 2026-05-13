//Given a 2D array where each row is {student_id, grade1, grade2}, sort students by grade2 in descending order using Quick Sort. 
// Print sorted student IDs with their grade2.
#include<stdio.h>
void swap(int a[][3],int i,int j){
    int t[3]={a[i][0],a[i][1],a[i][2]};
    a[i][0]=a[j][0];a[i][1]=a[j][1];a[i][2]=a[j][2];
    a[j][0]=t[0];a[j][1]=t[1];a[j][2]=t[2];
}
int part(int a[][3],int l,int r){
    int p=a[r][2],i=l-1;
    for(int j=l;j<r;j++)
        if(a[j][2]>=p)swap(a,++i,j);
    swap(a,i+1,r);
    return i+1;
}
void qs(int a[][3],int l,int r){
    if(l<r){int p=part(a,l,r);qs(a,l,p-1);qs(a,p+1,r);}
}
int main(){
    int a[][3]={{1,85,92},{2,78,88},{3,95,76},{4,88,95},{5,70,88}};
    int n=5;
    qs(a,0,n-1);
    for(int i=0;i<n;i++)
        printf("Student %d: %d\n",a[i][0],a[i][2]);
}