#include "Pilha c Reser.h"

void iniciar(void){
    for(int i=0;i<MAXSIZE;i++)
        Reservatorio[i].next=i+1;
    Reservatorio[MAXSIZE-1].next=-1;
}

int myalloc(void){
    int x=avail;
    avail=Reservatorio[avail].next;
    return (x);
}

void myfree(int x){
    Reservatorio[x].next=avail;
    avail=x;
}

void push(pilha *x,int y){
    int k=myalloc();
    Reservatorio[k].next=(x->top);
    Reservatorio[k].info=y;
    (x->top)=k;
}

int pop(pilha *x){
    int y,k=Reservatorio[x->top].info;
    y=(x->top);
    (x->top)=Reservatorio[x->top].next;
    myfree(y);
    return(k);
}

int top(pilha *x){
    return(Reservatorio[x->top].info);
}

int isempty(pilha *x){
    return(x->top==-1);
}

int isfull(void){
    return(avail==-1);
}