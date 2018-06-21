#include "Pilha c Reser.h"
int main()
{
    iniciar();
    int x;
    pilha y;
    y.top=-1;
    for(int i=0;i<MAXSIZE;i++){
        printf("digite um numero:\n");
        scanf("%i",&x);
        if (x==-1)
            break;
        push(&y,x);
    }
    while(y.top!=-1)
        printf("\n%i\n",pop(&y));
    return 0;
}
