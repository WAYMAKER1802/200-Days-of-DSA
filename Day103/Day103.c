//Problem: Find K Most Frequent Elements
//Given an array of integers, find the K most frequent elements using a Min-Heap.
#include<stdio.h>

int freq[1000],vals[1000],vn=0;

void swap(int i,int j){
    int t=freq[i];freq[i]=freq[j];freq[j]=t;
    t=vals[i];vals[i]=vals[j];vals[j]=t;
}
void push(int f,int v){
    freq[vn]=f;vals[vn]=v;
    int i=vn++;
    while(i>0&&freq[(i-1)/2]>freq[i]){
        swap(i,(i-1)/2);i=(i-1)/2;
    }
}
void pop(){
    freq[0]=freq[--vn];vals[0]=vals[vn];
    int i=0;
    while(1){
        int s=i,l=2*i+1,r=2*i+2;
        if(l<vn&&freq[l]<freq[s])s=l;
        if(r<vn&&freq[r]<freq[s])s=r;
        if(s==i)break;
        swap(i,s);i=s;
    }
}

int main(){
    int a[]={1,1,1,2,2,3,3,3,3,4},n=10,k=2;
    int cnt[1000]={0},seen[1000],sn=0;
    for(int i=0;i<n;i++){
        if(cnt[a[i]]==0)seen[sn++]=a[i];
        cnt[a[i]]++;
    }
    vn=0;
    for(int i=0;i<sn;i++){
        push(cnt[seen[i]],seen[i]);
        if(vn>k)pop();
    }
    for(int i=0;i<vn;i++)printf("%d ",vals[i]);
}