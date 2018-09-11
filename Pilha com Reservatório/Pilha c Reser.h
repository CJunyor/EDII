#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 200

typedef struct{
    int info,next;
}node;

typedef struct pilha{
    int top;
}pilha;

int avail=0;

node Reservatorio[MAXSIZE];

void iniciar(void);

int myalloc(void);

void myfree(int);

void push(pilha *, int);

int pop(pilha *);

int top(pilha *);

int isempty(pilha *);

int isfull(void);
