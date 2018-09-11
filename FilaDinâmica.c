#include <stdio.h>
#include <stdlib.h>
typedef struct NO{
    int info;
    struct NO *next;
}Node;
typedef struct FILA{
    Node *front,*rear;
}Fila;
int EMPTY(Fila *x){
    return((x->front)==NULL);
}
int REMOVE(Fila *x){
    int y;
    if(!EMPTY(x)){
        Node *p;
        y=x->front->info;
        p=x->front;
        x->front=x->front->next;
        free(p);
        return(y);
    }
    else
        printf("fila vazia desgraca!!");
    return(-1);
}
int REEND(Fila *x){
    int y;
    if(!EMPTY(x)){
        Node *p,*q;
        y=x->rear->info;
        p=x->rear;
        for(q=x->front;(q->next)!=(x->rear);q=(q->next));
        x->rear=q;
        x->rear=NULL;
        free(p);
        return(y);
    }
    else
        printf("fila vazia desgraca!!");
    return(-1);
}
void INSERT(Fila *x,int y){
    Node *p = (Node*) malloc(sizeof(Node));
    if(p!=NULL){
        if(!EMPTY(x)){
            p->info=y;
            p->next=NULL;
            x->rear->next=p;
            x->rear=p;
        }
        else{
            p->info=y;
            p->next=NULL;
            x->front=x->rear=p;
        }
    }
    else
        printf("Memoria insuficiente");
}
void INSFRONT(Fila *x,int y){
    Node *p = (Node*) malloc(sizeof(Node));
    if(p!=NULL){
        if(!EMPTY(x)){
            p->info=y;
            p->next=x->front;
            x->front=p;
        }
        else{
            p->info=y;
            p->next=NULL;
            x->front=x->rear=p;
        }
    }
    else
        printf("Memoria insuficiente");
}
int main()
{

    return 0;
}
