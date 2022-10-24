//
//  main.c
//  Ficha3Base_Pilhas
//
//  Created by Jorge Loureiro on 15/03/2020.
//  Copyright © 2020 Jorge Alexandre de Albuquerque Loureiro. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Ex. 1 */
typedef struct {
    int ano, mes, dia;
} Data;

typedef struct
{
    char conteudo[81];
    char origem[31];
    char destino[31];
    char cliente[81];
    Data dataEntrada;
    float tonelagem;
    char referencia[16];
} Contentor;

/* Ex. 2 */
typedef Contentor Informacao;

typedef struct nodo
{
    Informacao *Info;
    struct nodo* seguinte;
} Nodo, *ptELEMENTO;
typedef struct
{
    Nodo *Inicio;
    int Nel;
} Lista, Pilha, Fila;

/* Ex. 3 */
Data dataCalendario()
{
    Data data;
    time_t temp;
    struct tm* tinfo;
    time(&temp);
    tinfo = localtime(&temp);
    data.ano = tinfo->tm_year+1900;
    data.mes = tinfo->tm_mon+1;
    data.dia = tinfo->tm_mday;
    return data;
}

void limparTeclado(char * str)
{
    //fflush(stdin); //no Visual Studio
    gets(str);
}

Contentor *lerDados()
{
    char str[1];
    Contentor *contentor = (Contentor *)malloc(sizeof(Contentor));
    
    limparTeclado(str);
    printf("\nConteudo? ");
    //limparTeclado();
    gets(contentor->conteudo);
    printf("\nOrigem? ");
    //limparTeclado(str);
    gets(contentor->origem);
    printf("\nDestino? ");
    //limparTeclado(str);
    gets(contentor->destino);
    printf("\nCliente? ");
    //limparTeclado(str);
    gets(contentor->cliente);
    printf("\nTonelagem? ");
    //limparTeclado(str);
    scanf("%f", &( contentor->tonelagem));
    //limparTeclado(str);
    printf("\nReferencia? ");
    limparTeclado(str);
    gets(contentor->referencia);
    //limparTeclado(str);
    contentor->dataEntrada = dataCalendario();
    return contentor;
}


/* Ex. 4 */
void mostrarData(Data dtEntrada)
{
    printf("%d/%d/%d", dtEntrada.dia, dtEntrada.mes, dtEntrada.ano);
}
void mostrarContentor(Contentor *contentor)
{
    printf("\n\tConteudo: %s ", contentor->conteudo);
    printf("\n\tOrigem: %s", contentor->origem);
    printf("\n\tDestino: %s", contentor->destino);
    printf("\n\tCliente: %s", contentor->cliente);
    printf("\n\tData de entrada: ");
    mostrarData(contentor->dataEntrada);
    printf("\n\tTonelagem: %.2f ", contentor->tonelagem);
    printf("\n\tReferencia: %s", contentor->referencia);
}

void mostrarLista(Lista *L) {
    /* Inserir código */
}

void ListarPilha(Pilha *P)
{
    /* Inserir código */
}

/* Ex. 5 */

void inserir_elemento_inicio(Lista *L, ptELEMENTO E) { 
    /* Inserir código */
}


ptELEMENTO criar_elemento(Informacao *inf) { /* 5 criar um novo elemento (alocar e inicializar)*/
    /* Inserir código */
    return NULL;
}

void PushPilha(Pilha *P, Informacao *inf)
{
    /* Inserir código */
}

/* Ex. 6 */
Informacao* Pop(Pilha *P)
{
    if (!P) return NULL;
    if (!P->Inicio) return NULL;
    return NULL;
}
/* Ex. 7 */
int altura(Pilha *P)
{
    /* Inserir código */
    return 0;
}
/* Ex. 8 */
Informacao* fundo(Pilha *P)
{
    if (!P) return NULL;
    if (!P->Inicio) return NULL;
    /* Inserir código */
    return NULL;
}

/* Ex. 9 */

int elementos_iguais(ptELEMENTO A, char *B)
{
    if(strcmp(A->Info->referencia, B) == 0)
        return 1;
    else
        return 0;
}

ptELEMENTO pesquisar_iterativo_Pilha(Lista *L, char *ele_pesquisa) {
    if (!ele_pesquisa || !L)
        return NULL;
    
    return NULL;
}

/* Ex. 10 */

ptELEMENTO pesquisar_recursivo_elemento(ptELEMENTO L, char *ref) {
    if (!L)
        return NULL;
    /* Inserir código */
    return NULL;
}

ptELEMENTO pesquisar_recursivo_Pilha(Lista *L, char *ref) {
    if (!L || !ref)
        return NULL;
    return NULL;
}

/* Ex. 11 */
int menu()
{
    int opcao;
    printf("\n\n");
    //system("pause");
    printf("\n\n");
    printf("\n   #--------------------------------------------#");
    printf("\n   |   Inserir Contentor (no topo)________(1)   |");
    printf("\n   |   Retirar Contentor (do topo)________(2)   |");
    printf("\n   |   Mostrar contentores da Pilha_______(3)   |");
    printf("\n   |   Informar/altura da Pilha___________(4)   |");
    printf("\n   |   Visualizar contentor do fundo______(5)   |");
    printf("\n   |   Pesquisar contentor p/Ref (iter)___(6)   |");
    printf("\n   |   Pesquisar contentor p/Ref (rec)____(7)   |");
    printf("\n   |   SAIR_______________________________(0)   |");
    printf("\n   #--------------------------------------------#\n");
    //limparTeclado();
    do {
        printf("\n  Qual a sua opcao ? ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 7);
    return opcao;
}

// Funções adicioinais necessárias ao funcionamento da aplicação

Lista *criar_lista(){
    Lista *L;
    L = (Lista *)malloc(sizeof(Lista));
    L->Inicio = NULL;
    L->Nel = 0;
    return L;
}

Pilha *CriarPilha() // função que permite criar a pilha, invocando a função criaar_lista,
                    // pois que a estrutur é identica à da lista
{
    return criar_lista();
}

void libertar_elemento(ptELEMENTO ele_libertar) {  // usa a função relativa à lista
    free(ele_libertar->Info);  // Destroi a informacao
    free(ele_libertar);       // Destroi o elemento
}

void destruir(Lista *L) { // função destruir relativa à lista, pois que estrutura identica
    if (!L)
        return;
    // Destroi a Lista e toda a informação que ela contêm
    ptELEMENTO p = L->Inicio;
    while (p) {
        ptELEMENTO ant = p;
        p = p->seguinte;
        libertar_elemento(ant);
    }
    L->Inicio = NULL;
    L->Nel = 0;
}

void DestruirPilha(Pilha *P)
{
    destruir(P); // usa a correspondente função relativa à lista
}


int main(int argc, const char * argv[]) {
    {
        int opcao;
        Contentor *contentor;
        Pilha *P = CriarPilha();
        // char refCont[16]="";
        
        do {
            opcao = menu();
            switch (opcao)
            {
                case 1: contentor = lerDados();
                    PushPilha(P, contentor);
                    break;
                case 2:
                {
                    Informacao *EL = Pop(P);
                    mostrarContentor(EL);
                    free(EL);
                }
                    break;
                case 3: ListarPilha(P);
                    break;
                case 4: printf("\nAltura da pilha de contentores: %d",altura(P));
                    break;
                case 5:
                {
                    Informacao *EL = fundo(P);
                    mostrarContentor(EL);
                }
                    break;
                case 6:
                {
                    char ref[16];
                    printf("Qual a referência do contentor? ");
                    scanf("%s", ref);
                    ptELEMENTO EL;
                    EL = pesquisar_iterativo_Pilha(P, ref);
                    mostrarContentor(EL->Info);
                }
                    break;
                case 7:
                {
                    char ref[16];
                    printf("Qual a referência do contentor? ");
                    scanf("%s", ref);
                    ptELEMENTO EL;
                    EL = pesquisar_recursivo_Pilha(P, ref);
                    mostrarContentor(EL->Info);
                }
                    break;
                case 0:  printf("\n\nFIM\n"); system("pause");
            }
        }  while (opcao != 0);
        DestruirPilha(P);
    }
}
