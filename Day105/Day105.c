//Problem: Balanced Parentheses Checker
//Given a string with (, ), {, }, [, ], check if it is balanced using a Stack.
#include<stdio.h>
#include<string.h>

char stack[1000];
int top=-1;

void push(char c){stack[++top]=c;}
char pop(){return stack[top--];}
int isEmpty(){return top==-1;}

int isBalanced(char*s){
    top=-1;
    for(int i=0;i<strlen(s);i++){
        char c=s[i];
        if(c=='('||c=='{'||c=='[')push(c);
        else{
            if(isEmpty())return 0;
            char t=pop();
            if(c==')'&&t!='(')return 0;
            if(c=='}'&&t!='{')return 0;
            if(c==']'&&t!='[')return 0;
        }
    }
    return isEmpty();
}

int main(){
    char*tests[]={"{[()]}","{[(])}","((("};
    int n=3;
    for(int i=0;i<n;i++)
        printf("%s: %s\n",tests[i],isBalanced(tests[i])?"Balanced":"Not Balanced");
}