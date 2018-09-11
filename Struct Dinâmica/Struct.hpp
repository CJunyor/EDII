#include <iostream>

typedef struct{
    string tipo;
    string nome;
    void *info;
}no;

typedef struct{
    string nome;
    list<no>vars;
}stc;

void CriarStruct(stc *);

void ImprimeMenu(){
    cout("================================================");
    //cout("          1 - Abrir uma Struct");
    cout("          1 - Criar Struct");
    cout("          2 - Atribuir Valores");
    cout("          3 - Mostrar Valores");
    cout("          4 - Sair");
    cout("================================================");
}

void ImprimeStruct(stc* STC){
    cout("\n\nStruct "<<STC->nome<<" {");
    for(list<no>::iterator i=STC->vars.begin();i!=STC->vars.end();i++){
        cout("\t"<<(*i).tipo<<" "<<(*i).nome<<";");
    }
    cout("}");
}

void Atribuir(stc *STC){
    string s;
    list<no>::iterator i;
    while(1){
        cout("Digite o nome do variavel que vc quer alterar:");
        cin>>s;
        for(i=STC->vars.begin();i!=STC->vars.end();i++) if((*i).nome==s) break;
        if(i==STC->vars.end()) cout("Nome de variael invalido!");
        else break;
    }
    cout("Digite o valor:");
    if(i->tipo=="int"){
        int x;
        cin>>x;
        *cint(i->info)=x;
    }
    else if(i->tipo=="char"){
        char x;
        cin>>x;
        *cchar(i->info)=x;

    }
    else if(i->tipo=="float"){
        float x;
        cin>>x;
        cin>>x;
        *cfloat(i->info)=x;
    }
    else if(i->tipo=="double"){
        double x;
        cin>>x;
        *cdouble(i->info)=x;
    }
    else if(i->tipo=="string"){
        string x;
        cin>>x;
        *cstring(i->info)=x;
    }
}

void Iniciar(){
    stc STC;
    while(1){
        ImprimeMenu();
        char c;
        cin>>c;
        switch(c){
            //case '1':
              //  cout("Amoeba");
                //break;
            case'1':
                CriarStruct(&STC);
                break;
            case '2':
                ImprimeStruct(&STC);
                Atribuir(&STC);
                break;
            case'3':
                for(list<no>::iterator i=STC.vars.begin();i!=STC.vars.end();i++){
                    if(i->tipo=="int") cout(i->nome<<": "<<*cint(i->info));
                    else if(i->tipo=="char") cout(i->nome<<": "<<*cchar(i->info));
                    else if(i->tipo=="float") cout(i->nome<<": "<<*cfloat(i->info));
                    else if(i->tipo=="double") cout(i->nome<<": "<<*cdouble(i->info));
                    else if(i->tipo=="string") cout(i->nome<<": "<<*cstring(i->info));
                }
                break;
            case '4':
                exit(1);
                break;
        }
    }
}

void Malocar(no *x){
    if(x->tipo=="int")
        x->info=new int;
    else if(x->tipo=="char")
        x->info=new char;
    else if(x->tipo=="float")
        x->info=new float;
    else if(x->tipo=="double")
        x->info=new double;
    else if(x->tipo=="string")
        x->info=new string;
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
        x.tipo=ax;
        cout("Digite o nome da variavel:");
        cin>>ax;
        x.nome=ax;
        Malocar(&x);
        STC->vars.push_back(x);
    }
    ImprimeStruct(STC);
}