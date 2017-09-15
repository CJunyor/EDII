#include "Funcoes.h"

void ImprimeMenu(){
    cout("================================================");
    cout("          1 - Abrir uma Struct");
    cout("          2 - Criar Struct");
    cout("          3 - Atribuir Valores");
    cout("          4 - Mostrar Valores");
    cout("          5 - Salvar");
    cout("          6 - Sair");
    cout("================================================");
}

int Abrir(stc *STC){
    int SIZE=sizeof(MTD);
    ifstream fp;
    no x;
    string ax;
    cout("Digite o nome da Struct:");
    cin>>ax;
    fp.open(ax.c_str(), ifstream::binary);
    if(!fp.is_open()){
        cout("Nome Invalido");
        return 0;
    }
    while(1){
        fp.read((char *)&x.dado, SIZE);
        if(fp.eof()) break;
        cout(x.dado.tipo<<" "<<x.dado.nome<<";");
        if(!Malocar(&x)){
            cout("Nao foi possivel abrir a Struct");
            fp.close();
            return 0;
        }
        else if(x.dado.tipo=="int"){
            fp.read((char *)x.info, sizeof(int));
            STC->vars.push_back(x);
        }
        else if(x.dado.tipo=="char") {
            fp.read((char *)x.info, sizeof(char));
            STC->vars.push_back(x);
        }
        else if(x.dado.tipo=="float"){
            fp.read((char *)x.info, sizeof(float));
            STC->vars.push_back(x);
        }
        else if(x.dado.tipo=="double"){
            fp.read((char *)x.info, sizeof(double));
            STC->vars.push_back(x);
        }
        else if(x.dado.tipo=="string"){
            fp.read((char *)x.info, sizeof(string));
            STC->vars.push_back(x);
        }
    }
    STC->nome=ax;
    fp.close();
    return 1;
}

void ImprimeStruct(stc* STC){
    cout("\n\nStruct "<<STC->nome<<" {");
    for(no i : STC->vars){
        cout("\t"<<i.dado.tipo<<" "<<i.dado.nome<<";");
    }
    cout("}");
}

void ImprimeValores(stc* STC){
    for(no i: STC->vars){
        if(i.dado.tipo=="int") cout(i.dado.nome<<": "<<*cint(i.info));
        else if(i.dado.tipo=="char") cout(i.dado.nome<<": "<<*cchar(i.info));
        else if(i.dado.tipo=="float") cout(i.dado.nome<<": "<<*cfloat(i.info));
        else if(i.dado.tipo=="double") cout(i.dado.nome<<": "<<*cdouble(i.info));
        else if(i.dado.tipo=="string") cout(i.dado.nome<<": "<<*cstring(i.info));
    }
}

int Malocar(no *x){
    if((x->dado).tipo=="int")
        x->info=new int;
    else if((x->dado).tipo=="char")
        x->info=new char;
    else if((x->dado).tipo=="float")
        x->info=new float;
    else if((x->dado).tipo=="double")
        x->info=new double;
    else if((x->dado).tipo=="string")
        x->info=new string;
    else {
        cout("Tipo Errado Informado!!");
        return 0;
    }
    return 1;
}

void CriarStruct(stc *STC){
    string ax;
    no x;
    cout("Digite o nome da struct:");
    cin>>ax;
    STC->nome=ax;
    ax="";
    while(ax!="-1"){
        cout("Digite o tipo da variavel:");
        cin>>ax;
        if(ax=="-1") break;
        x.dado.tipo=ax;
        cout("Digite o nome da variavel:");
        cin>>ax;
        x.dado.nome=ax;
        Malocar(&x);
        STC->vars.push_back(x);
    }
    ImprimeStruct(STC);
}

void Atribuir(stc *STC){
    string s;
    list<no>::iterator i;
    while(1){
        cout("Digite o nome do variavel que vc quer alterar:");
        cin>>s;
        for(i=STC->vars.begin();i!=STC->vars.end();i++) if((*i).dado.nome==s) break;
        if(i==STC->vars.end()) cout("Nome de variael invalido!");
        else break;
    }
    cout("Digite o valor:");
    if(i->dado.tipo=="int"){
        int x;
        cin>>x;
        *cint(i->info)=x;
    }
    else if(i->dado.tipo=="char"){
        char x;
        cin>>x;
        *cchar(i->info)=x;

    }
    else if(i->dado.tipo=="float"){
        float x;
        cin>>x;
        *cfloat(i->info)=x;
    }
    else if(i->dado.tipo=="double"){
        double x;
        cin>>x;
        *cdouble(i->info)=x;
    }
    else if(i->dado.tipo=="string"){
        string x;
        cin>>x;
        *cstring(i->info)=x;
    }
}

void Salvar(stc *STC){
    ofstream fp;
    fp.open(STC->nome.c_str(), ofstream::binary);
    if(!fp.is_open()) {
        cout("Nao foi possivel salvar");
        exit(1);
    }
    for(no i : STC->vars){
        fp.write((char *)&(i.dado), sizeof(MTD));
        if(i.dado.tipo=="int") {
            fp.write((char *)i.info, sizeof(int));
        }
        else if(i.dado.tipo=="char") {
            fp.write((char *)i.info, sizeof(char));
        }
        else if(i.dado.tipo=="float"){
            fp.write((char *)i.info, sizeof(float));
        }
        else if(i.dado.tipo=="double"){
            fp.write((char *)i.info, sizeof(double));
        }
        else if(i.dado.tipo=="string"){
            fp.write((char *)i.info, sizeof(string));
        }
    }
    fp.close();
}

int Iniciar(stc *STC){
    //stc *STC2=new stc;
    while(1){
        ImprimeMenu();
        char c;
        cin>>c;
        switch(c){
            case '1':
                Abrir(STC);
                //return 1;
                break;
            case '2':
                CriarStruct(STC);
                break;
            case '3':
                ImprimeStruct(STC);
                Atribuir(STC);
                break;
            case '4':
                ImprimeValores(STC);
                break;
            case '5':
                Salvar(STC);
                //return 2;
                break;
            case '6':
                exit(1);
                break;
        }
    }
    return 0;
}

