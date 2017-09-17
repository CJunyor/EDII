#include "Funcoes.h"

void ImprimeMenu(){
    cout("================================================");
    cout("          1 - Abrir uma Struct");
    cout("          2 - Criar Struct");
    cout("          3 - Sair");
    cout("================================================");
    cout<<">";
}

int DSize(no *x){
    if((x->dado).tipo=="int") return(sizeof(int));
    else if((x->dado).tipo=="char") return(sizeof(char));
    else if((x->dado).tipo=="float") return(sizeof(float));
    else if((x->dado).tipo=="double") return(sizeof(double));
    else if((x->dado).tipo=="string") return((*cstring(x->info)).size());
    else {
        cout("Tipo Errado Informado!!");
        return 0;
    }
}

void ImprimeSubMenu(){
    cout("================================================");
    cout("          1 - Atribuir Valores");
    cout("          2 - Mostrar Valores");
    cout("          3 - Salvar");
    cout("          4 - Voltar ao Menu");
    cout("================================================");
    cout<<">";
}

int Abrir(stc *STC){
    fstream fmd,fd;
    no x;
    string ax;
    cout("Digite o nome da Struct:");
    cin>>ax;
    fmd.open("M"+ax, ifstream::in);
    fd.open(ax, ifstream::in);
    if(!(fd.is_open()&&fmd.is_open())){
        cout("Nome Invalido");
        return 0;
    }
    while(!fmd.eof()){
        fmd>>x.dado.nome;
        fmd>>x.dado.tipo;
        if(fmd.eof()) break;
        cout(x.dado.tipo<<" "<<x.dado.nome<<";");
        if(!Malocar(&x)){
            cout("Nao foi possivel abrir a Struct");
            fd.close();
            fmd.close();
            return 0;
        }
        else if(x.dado.tipo=="int"){
            fd.read((char *)x.info, sizeof(int));
            STC->vars.push_back(x);
        }
        else if(x.dado.tipo=="char") {
            fd.read((char *)x.info, sizeof(char));
            STC->vars.push_back(x);
        }
        else if(x.dado.tipo=="float"){
            fd.read((char *)x.info, sizeof(float));
            STC->vars.push_back(x);
        }
        else if(x.dado.tipo=="double"){
            fd.read((char *)x.info, sizeof(double));
            STC->vars.push_back(x);
        }
        else if(x.dado.tipo=="string"){
            int tam;
            fmd>>tam;
            char s[tam+1];
            fd.read(s, tam);
            *cstring(x.info)=s;
            STC->vars.push_back(x);
        }
    }
    STC->nome=ax;
    fd.close();
    fmd.close();
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
    if((x->dado).tipo=="int")         x->info=new int;
    else if((x->dado).tipo=="char")   x->info=new char;
    else if((x->dado).tipo=="float")  x->info=new float;
    else if((x->dado).tipo=="double") x->info=new double;
    else if((x->dado).tipo=="string") x->info=new string;
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
    fstream fmd,fd;
    fmd.open("M"+STC->nome, ofstream::out);
    fd.open(STC->nome, ofstream::out);
    if(!(fd.is_open()&&fmd.is_open())) {
        cout("Nao foi possivel salvar");
        exit(1);
    }
    for(no i : STC->vars){
        fmd<<i.dado.nome;
        fmd<<" "+i.dado.tipo;
        if(i.dado.tipo=="int") {
            fd.write((char *)i.info, sizeof(int));
        }
        else if(i.dado.tipo=="char") {
            fd.write((char *)i.info, sizeof(char));
        }
        else if(i.dado.tipo=="float"){
            fd.write((char *)i.info, sizeof(float));
        }
        else if(i.dado.tipo=="double"){
            fd.write((char *)i.info, sizeof(double));
        }
        else if(i.dado.tipo=="string"){
            fd.write((char *)(*cstring(i.info)).c_str(), DSize(&i));
            fmd<<" "<<DSize(&i);
        }
        fmd<<"\n";
    }
    fd.close();
    fmd.close();
    cout("Salvo com sucesso");
}

int SubMenu(stc *STC){
    while(1){
        ImprimeSubMenu();
        char c;
        cin>>c;
        switch(c){
            case '1':
                ImprimeStruct(STC);
                Atribuir(STC);
                break;
            case '2':
                ImprimeValores(STC);
                break;
            case '3':
                Salvar(STC);
                break;
            case '4':
                delete STC;
                return 1;
        }
    }
    return 0;
}

int Iniciar(stc *STC){
    while(1){
        STC=new stc;
        ImprimeMenu();
        char c;
        cin>>c;
        switch(c){
            case '1':
                Abrir(STC);
                SubMenu(STC);
                break;
            case '2':
                CriarStruct(STC);
                SubMenu(STC);
                break;
            case '3':
                return 0;
                break;
        }
    }
    return 0;
}

