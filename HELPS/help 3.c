//
//  main.c
//  ListaLigada_Parcial
//
//  Created by Jorge Loureiro on 13/03/2020.
//  Copyright © 2020 Jorge Alexandre de Albuquerque Loureiro. All rights reserved.
//

/* Nesta implementação, uma lista é definida usando uma estrutura com 3 campos:
    - string com o código da língua (2 caraceteres);
    - nº de elementos actualmente na lista;
    - ponteiro para o primeiro elemento da lista.
 Cada elemento da lista contém dois campos:
  - apontador para uma estrutura com os dados do elemento (ptPALAVRA ou *Palavra)
  - apontador para o próximo da lista        */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_PALAVRA 50 // Tamanho maximo para o nome
#define MAX_LINGUA 3
#define LINGUA "PT"
#define NOME_FICHEIRO "PT.txt"

/** 1 */
typedef struct Palavra {
  char texto[MAX_PALAVRA];
} *ptPALAVRA;
/** 2 */
typedef struct Elemento {
   ptPALAVRA inf;
   struct Elemento *seg;
} *ptELEMENTO;
/** 3 */
typedef struct Lista {
   char lingua[MAX_LINGUA];  /** a) */
   int nelementos;          /** b */
   ptELEMENTO inicio;       /** c */
} *ptLISTA;

/** 4 criar (alocar e inicializar) uma lista de elementos */
ptLISTA criar_lista(){
      // COMPLETAR
   return NULL;
}

/** 5 criar um novo elemento (alocar e inicializar)*/
ptELEMENTO criar_elemento() {
      // COMPLETAR
   return NULL;
}

/** 6 */
int validar_elemento(ptELEMENTO E) {
      // COMPLETAR
  return 1;
}

/** 7 registar e validar dados de um elemento*/
void ler_elemento(ptELEMENTO E) {
      // COMPLETAR
}

/** 10 */
int comparar_elementos(ptELEMENTO A, ptELEMENTO B) {
      // COMPLETAR
  return 1;
}

/** 11 */
int elementos_iguais(ptELEMENTO A, ptELEMENTO B) {
      // COMPLETAR
  return 1;
}

/** 12 */
void inserir_elemento_ordenado(ptLISTA L, ptELEMENTO ele_novo) {
      // COMPLETAR
    L->nelementos++;   // mais um elemento na lista
}

/** 13 verificar se um determinado elemento pertence à lista (abordagem iterativa)*/
ptELEMENTO pesquisar_iterativo(ptLISTA L, ptELEMENTO ele_pesquisa) {
      // COMPLETAR
  return NULL;
}

/** 14 verificar se um determinado elemento pertence à lista (abordagem recursiva)*/
ptELEMENTO pesquisar_recursivo_elemento(ptELEMENTO C, ptELEMENTO ele_pesquisa) {
      // COMPLETAR
  return NULL;
}

ptELEMENTO pesquisar_recursivo(ptLISTA L, ptELEMENTO ele_pesquisa) {
      // COMPLETAR
  return NULL;
}

/** 15 verificar se existem elementos repetidos*/
int elementos_repetidos(ptLISTA L) {
      // COMPLETAR
  return 0; // bastava comparar elementos adjacentes... entre dois
}           // elementos iguais não pode haver 1 diferente deles.

int elementos_repetidos_v2(ptLISTA L) { /* 15 de forma mais eficiente*/
      // COMPLETAR
  return 0;
}

/** 16 */
void libertar_elemento(ptELEMENTO ele_libertar) {
      // COMPLETAR
}

/** 17 */
ptELEMENTO remover_elemento(ptLISTA L, ptELEMENTO ele_remover) {
      // COMPLETAR
  return NULL;
}

/** 18 */
ptELEMENTO remover_primeiro(ptLISTA L) {
      // COMPLETAR
  return NULL;
}

/** 19 */
ptELEMENTO remover_ultimo(ptLISTA L) {
      // COMPLETAR
  return NULL;
}

/** 20 */
void mostrar_elemento(ptELEMENTO ele_mostrar) {
      // COMPLETAR
}

/** 21 */
void mostrar_ordenado(ptLISTA L) {
      // COMPLETAR
}
/** 22 mostrar dados de todos os elementos da lista pela ordem inversa*/
void mostrar_ordenado_inversa(ptELEMENTO p) { // recursivo
      // COMPLETAR
}

void mostrar_inversa_v1(ptLISTA L) {
      // COMPLETAR
}
void mostrar_inversa_v2(ptLISTA L) { // iterativo
      // COMPLETAR
}

/** 23 destruir lista (remove e liberta todos os elementos*/
void destruir(ptLISTA L) {
      // COMPLETAR
  L->inicio = NULL;
  L->nelementos = 0;
}

/** 24 */
void exportar_ficheiro(ptLISTA L, char *nome_ficheiro) {
      // COMPLETAR
}

/** 25 */
void importar_ficheiro(ptLISTA L, char *nome_ficheiro) {
      // COMPLETAR

  //printf("\n % d elementos importados com sucesso!\n",nelementos);
}

/** 26 */
int menu_principal() {
  int x;
  printf("\n\n   # MENU PRINCIPAL -------------------------------------------#");
  printf("\n   | (1) Inserir um novo elemento na lista                     |");
  printf("\n   | (2) Retirar elementos da lista ( ir para o sub menu)      |");
  printf("\n   | (3) Mostrar os elementos pela ordem actual                |");
  printf("\n   | (4) Mostrar os elementos pela ordem inversa               |");
  printf("\n   | (5) Mostrar o numero de elementos da lista                |");
  printf("\n   | (6) Pesquisar por um elemento da lista                    |");
  printf("\n   | (7) Verificar se existem elementos repetidas na lista     |");
  printf("\n   | (8) Exportar elementos para um ficheiro de texto          |");
  printf("\n   | (9) Importar elementos de um ficheiro de texto            |");
  printf("\n   | -----------------------------------------------------     |");
  printf("\n   | (0) SAIR                                                  |");
  printf("\n   #-----------------------------------------------------------#\n");
  fflush(stdin);
  do {
    printf("\n  Qual a sua opcao ? ");
    fflush(stdin);
    scanf("%d",&x);
  } while (x<0 || x>9);
  return x;
}

/** 27 */
int menu_remover() {
  int x;
  printf("\n        # RETIRAR ELEMENTOS DA LISTA --------------------------#");
  printf("\n        | (1) Retirar o primeiro elemento                      |");
  printf("\n        | (2) Retirar um elemento especificado pelo utilizador |");
  printf("\n        | (3) Retirar o ultimo elemento                        |");
  printf("\n        | (4) Retirar todos os elementos da lista              |");
  printf("\n        | ---------------------------------------------------- |");
  printf("\n        | (0) VOLTAR ao Menu Principal                         |");
  printf("\n        #------------------------------------------------------#\n");
  fflush(stdin);
  do {
    printf("\n  Qual a sua opcao ? ");
    fflush(stdin);
    scanf("%d",&x);
  } while (x<0 || x>4);
  return x;
}

/** 28 Programa Principal*/
int main() {

    char nomefic[100];
    strcpy(nomefic,NOME_FICHEIRO);
    char resp;
    ptELEMENTO ele_remover, ele_removido, ele_pesquisar, ele_novo;

    ptLISTA lista = criar_lista();    // Criar a lista
    strcpy(lista->lingua, LINGUA);    // Associar a lingua à lista

    for(;;) {
    //system("cls");
        switch (menu_principal()) {
            case 1:
                ele_novo = criar_elemento();
                ler_elemento(ele_novo);
                inserir_elemento_ordenado(lista, ele_novo);
                break;
            case 2:
                switch (menu_remover()) {
                    case 1:
                        ele_removido = remover_primeiro(lista);
                        if (ele_removido) {
                          printf("Foi removido o primeiro elemento");
                          mostrar_elemento(ele_removido);
                          libertar_elemento(ele_removido);
                        }
                        else
                          printf("Não foi encontrado nenhum elemento!\n");
                        break;
                    case 2:
                        ele_remover = criar_elemento();
                        ler_elemento(ele_remover);
                        ele_removido = remover_elemento(lista, ele_remover);
                        if (ele_removido) {
                          printf("O elemento foi removido!\n");
                          mostrar_elemento(ele_removido);
                          libertar_elemento(ele_removido);
                        }
                        else
                          printf("Não foi encontrado nenhum elemento!\n");
                        break;
                    case 3:
                        ele_removido = remover_ultimo(lista);
                        if (ele_removido) {
                          printf("Foi removido o ultimo elemento\n");
                          mostrar_elemento(ele_removido);
                          libertar_elemento(ele_removido);
                        }
                        else
                          printf("Não foi encontrado nenhum elemento!\n");
                        break;
                    case 4:
                        destruir(lista);
                        break;
                } //END switch (menu_remover())
                break; //END case 2:
            case 3:
                if (lista->nelementos == 0)
                  printf("Nao existem elementos na lista!\n");
                else
                  mostrar_ordenado(lista);
                break;
            case 4:
                if (lista->nelementos == 0)
                    printf("Nao existem elementos na lista!\n");
                else
                {
                    do{
                    printf("\nUsar função <r>ecursiva ou <i>terativa? ");
                    scanf(" %c", &resp);
                    } while (resp!='r' && resp !='i');
                    if(resp=='r')
                        mostrar_inversa_v1(lista);
                    else
                        mostrar_inversa_v2(lista);
                }
                break;
            case 5:
                printf("Numero de elementos da lista: %d\n", lista->nelementos);
                break;
            case 6:
                ele_pesquisar = criar_elemento();
                ler_elemento(ele_pesquisar);
                printf("Pesquisar iterativo\n");
                if (pesquisar_iterativo(lista, ele_pesquisar))
                    printf("O elemento introduzido existe na lista!\n");
                else
                    printf("O elemento introduzido nao existe na lista!\n");
            
                printf("Pesquisar recursivo\n");
                if (pesquisar_recursivo(lista, ele_pesquisar))
                    printf("O elemento introduzido existe na lista!\n");
                else
                    printf("O elemento introduzido nao existe na lista!\n");
                break;
            case 7:
                if (lista->nelementos == 0)
                    printf("Nao existem elementos na lista!\n");
                else
                {
                    do{
                        printf("\nUsar função <s>imples ou <e>ficiente? ");
                        scanf(" %c", &resp);
                    } while (resp!='s' && resp !='e');
                    if(resp=='s')
                    {
                         if (elementos_repetidos(lista))
                            printf("Existem elementos repetidos na lista!\n");
                         else
                            printf("Nao existem elementos repetidos na lista!\n");
                    }
                    else
                    {
                         if (elementos_repetidos_v2(lista))
                            printf("Existem elementos repetidos na lista!\n");
                         else
                            printf("Nao existem elementos repetidos na lista!\n");
                    }
                }
                break;
            case 8:
                exportar_ficheiro(lista, nomefic);
                break;
            case 9:
                importar_ficheiro(lista, nomefic);
                break;
            case 0:
                exit(0);    // Fim f/do Programa
                break;
        } //END switch (menu_principal())
    //system("pause");
        } //END for(;;)
}

