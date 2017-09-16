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
    //Iniciar(STC);
    int SIZE=sizeof(MTD);
    ifstream fp;
    string ax;
    cout("Digite o nome da Struct:");
    cin>>ax;
    fp.open(ax.c_str(), ifstream::binary);
    if(!fp.is_open()){
        cout("Nome Invalido");
        return 0;
    }
    while(1){
        fp.read((char *)&k.dado, SIZE);
        if(fp.eof()) break;
        cout(k.dado.tipo<<" "<<k.dado.nome<<";");
        if(!Malocar(&k)){
            cout("Nao foi possivel abrir a Struct");
            fp.close();
            return 0;
        }
        else if(k.dado.tipo=="int"){
                fp.read((char *)k.info, sizeof(int));
                STC->vars.push_back(k);
        }
        else if(k.dado.tipo=="char") {
            fp.read((char *)k.info, sizeof(char));
            STC->vars.push_back(k);
        }
        else if(k.dado.tipo=="float"){
            fp.read((char *)k.info, sizeof(float));
            STC->vars.push_back(k);
        }
        else if(k.dado.tipo=="double"){
            fp.read((char *)k.info, sizeof(double));
            STC->vars.push_back(k);
        }
        else if(k.dado.tipo=="string"){
            fp.read((char *)k.info, sizeof(string));
            STC->vars.push_back(k);
        }
    }
    STC->nome=ax;
    fp.close();
    return 0;
}
