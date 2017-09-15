#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <fstream>
#include <cstring>
#include <string>
#include <list>
#define cout(x) cout<<x<<endl
#define cint(x) (int *) x
#define cchar(x) (char *) x
#define cstring(x) (string *) x
#define cfloat(x) (float *) x
#define cdouble(x) (double *) x

using namespace std;

typedef struct{
    string tipo;
    string nome;
}MTD;

typedef struct{
    MTD dado;
    void *info;
}no;

typedef struct{
    string nome;
    list<no>vars;
}stc;

void ImprimeMenu();
void ImprimeValores(stc*);
void ImprimeStruct(stc*);
int Malocar(no *);
void CriarStruct(stc *);
void Atribuir(stc *);
void Salvar(stc *);
int Abrir(stc *);
int Iniciar(stc *);
