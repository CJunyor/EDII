#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 200
typedef struct{
        int top;
        char info[MAXSIZE];
}pilha;
void push(pilha *x,char c){
    if(x->top<MAXSIZE-1)
        x->info[++x->top]=c;
    else{
        printf("pilha cheia");
        exit(1);
    }

}
int pop(pilha *x){
    if((x->top)>-1)
        return(x->info[x->top--]);
    else{
        printf("pilha vazia");
        exit(1);
    }
}
int top(pilha *x){
    if(x->top==-1){
        printf("pilha vazia");
        return 0;
    }
    else
        return(x->info[x->top]);
}
int isempty(pilha *x){
    return(x->top==-1);
}
int isfull(pilha *x){
    return(x->top==MAXSIZE-1);
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
