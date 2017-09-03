#include <bits/stdc++.h>
#include "Funcoes.h"

using namespace std;

int main()
{
    int y;
    no k;
    k.dado.nome="rola";
    k.dado.tipo="int";
    k.info=new int;
    *cint(k.info)=900;
    FILE *fn;
    fn=fopen("Teste", "wb");
    fwrite(&k.dado, sizeof(MTD), 1, fn);
    fwrite(k.info, sizeof(int), 1, fn);
    fclose(fn);
    stc *STC=new stc;
    Iniciar(STC);
    return 0;
}
