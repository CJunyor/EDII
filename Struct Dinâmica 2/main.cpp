#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <fstream>
#include <cstring>
#include <string>
#include <list>
#include "Funcoes.h"

using namespace std;

int main()
{
    no k;
    k.dado.nome="teste";
    k.dado.tipo="int";
    k.info=new int;
    *cint(k.info)=900;
    ofstream fn;
    fn.open("Teste", ofstream::binary);
    if(!fn.is_open()) {
        cout("Nome errado");
        return 0;
    }
    fn.write((char *)&k.dado, sizeof(MTD));
    fn.write((char *)k.info, sizeof(int));
    fn.close();
    stc *STC=new stc;
    Iniciar(STC);
    return 0;
}
