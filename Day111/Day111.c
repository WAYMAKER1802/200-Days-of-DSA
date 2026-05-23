//Problem: Valid Parentheses
//Given a string, check if parentheses are valid using a Stack. Must handle (), [], {}.
#include<stdio.h>
#include<string.h>

int isValid(char*s){
    int n=strlen(s),top=-1;
    char stack[n+1];
    for(int i=0;i<n;i++){
        char c=s[i];
        if(c=='('||c=='{'||c=='[')
            stack[++top]=c;
        else{
            if(top==-1)return 0;
            char t=stack[top--];
            if(c==')'&&t!='(')return 0;
            if(c=='}'&&t!='{')return 0;
            if(c==']'&&t!='[')return 0;
        }
    }
    return top==-1;
}

int main(){
    char*tests[]={"()[]{}","([)]","{[]}",""};
    int n=4;
    for(int i=0;i<n;i++)
        printf("%s: %s\n",tests[i],isValid(tests[i])?"Valid":"Invalid");
}