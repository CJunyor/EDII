#include <stdio.h>
#include <stdlib.h>
typedef struct NO{
    int info;
    struct NO *next;
}Node;
typedef struct Pilha{
    Node *TOP;
}stack;
int empty(stack *x){
    return (x->TOP==NULL);
}
int pop(stack *x){
    if(!empty(x)){
        Node *q=(x->TOP);
        int p=(x->TOP)->info;
        x->TOP=(x->TOP)->next;
        free(q);
        return(p);
        }
    else{
        printf("Pilha Vazia");
        exit(0);
    }
}
int top(stack *x){
    if(!empty(x))
        return ((x->TOP)->info);
    else{
        printf("Pilha Vazia");
        return 0;
    }
}
void push(stack *x,int y){
    Node *p;
    p=(Node *)malloc(sizeof(Node));
    if(p!=NULL){
        p->info=y;
        p->next=x->TOP;
        x->TOP=p;
    }
    else
        printf("Memoria Insuficiente");
}

int main (){
    return 0;
}
