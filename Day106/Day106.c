//Problem: Hot Potato Simulation
//Given n people standing in a circle, eliminate every kth person using a Queue. Print the order of elimination and the winner.
#include<stdio.h>

int q[100],front=0,rear=0,sz=0;

void enqueue(int x){q[rear++]=x;sz++;}
int dequeue(){sz--;return q[front++];}

int main(){
    int people[]={1,2,3,4,5,6},n=6,k=3;
    for(int i=0;i<n;i++)enqueue(people[i]);
    while(sz>1){

        for(int i=0;i<k-1;i++)
            enqueue(dequeue());
        printf("Eliminated: %d\n",dequeue());
    }
    printf("Winner: %d\n",dequeue());
}