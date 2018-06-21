#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,n,tam,k;
    a=3,b=5,n=10;
    tam=n*((a+b)-1) - (((b*(b-1))/2)+((a*(a-1))/2));
    int V[tam];
    int M[n][n];
    //imprime matriz
    printf("Matriz: \n");
    printf("______________________________________________________________________________________________\n\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j<(a+i)&&j>i-b){
                printf("  [%2.1i]  ",M[i][j]%10);
            }
            else
                printf("   %2.1i   ",0);
        }
        printf("\n\n");
    }
    printf("\n\n");
    printf("______________________________________________________________________________________________\n\n");
   printf("Matriz enumerada:\n");
   printf("______________________________________________________________________________________________\n\n");
   for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j<(a+i)&&j>i-b)
               printf("  [%2.1i]  ", ((n-i)-((i-j)*(i-j)-(i-j)))*((j-i)<0)  +  ((j-i>=0)*(n-j))  +  (n*(a-(j-i)-1))  -  (((((j-i)+1)+(a-1))*(a-((j-i)+1)))/2));
            else
                printf("   %2.1i   ",0);
        }
        printf("\n\n");
    }
     printf("______________________________________________________________________________________________\n\n");
    //atribui ao vetor
    printf("Vetor:\n");
    printf("______________________________________________________________________________________________\n\n");
   for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j<(a+i)&&j>i-b){
                k=( ((n-i)-((i-j)*(i-j)-(i-j)))*((j-i)<0)  +  ((j-i>=0)*(n-j))  +  (n*(a-(j-i)-1))  -  (((((j-i)+1)+(a-1))*(a-((j-i)+1)))/2) )-1;
                V[k]=M[i][j]%10;
            }
        }
    }
    //imprime vetor
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j<(a+i)&&j>i-b){
               k=( ((n-i)-((i-j)*(i-j)-(i-j)))*((j-i)<0)  +  ((j-i>=0)*(n-j))  +  (n*(a-(j-i)-1))  -  (((((j-i)+1)+(a-1))*(a-((j-i)+1)))/2) )-1;
               printf("  [%2.1i]  ",V[k]);
            }
            else
                printf("   %2.1i   ", 0);
        }
        printf("\n\n");
    }
    return 0;
}
