#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 200
#define SIZE 100
typedef struct{
    int top;
    char itens[MAXSIZE];
}pilha;
void push (pilha *x,char y){
    x->itens[++x->top]=y;
}
char pop(pilha *x){
    return(x->itens[x->top--]);
}
int main()
{
    pilha opr;
    int j=0;
    opr.top=-1;
    char expr[SIZE],resl[SIZE];
    printf("Digite a expressao: \n\n ");
    gets(expr);
    for(int i=0;expr[i]!='\0';i++){
        if(expr[i]=='+'||expr[i]=='-'||expr[i]=='*'||expr[i]=='/'||expr[i]=='^'||expr[i]=='('){
            push(&opr,expr[i]);
            continue;
        }
        if(expr[i]==')'){
            while(opr.itens[opr.top]!='('){
                    resl[j]=pop(&opr);
                    j++;
            }
            pop(&opr);
            continue;
        }
        if(expr[i]!=' ') {
            resl[j]=expr[i];
            j++;
        }
    }
    while(opr.itens[opr.top] > -1){
        resl[j]=pop(&opr);
        j++;
    }
    resl[j]='\0';
    printf("\nA posfixa e: \n %s\n\n",resl);
    return 0;
}
