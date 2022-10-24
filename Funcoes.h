#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Estrutura_dos_Dados.h"


//--------------------------------------------------------------------------
//----------------------------EXTERNS---------------------------------------
//--------------------------------------------------------------------------

char *alocar(char *aloc);
int LerInteiro(const char *msg);
bool VerificaIDReq(const char* cod);
bool VerificaData(int dia, int mes, int ano);

//Pessoas-------------------------------------------------------------------

ListaPessoas *CriarListaPessoas();
Pessoa *CriarPessoa(char *id_requisitante, char *Nome, char *freguesia, DATA *data_nasc);
void LoadPessoas(ListaPessoas *L);

//Livros---------------------------------------------------------------------

ListaLivros *CriarListaLivros();
Livro *CriarLivro(char *ISBN, char *titulo, char *area, DATA *ano_pub, int nreq, int estado);
void LoadLivros(ListaLivros *L);

//Freguesias-----------------------------------------------------------------

LFreguesias *CriarListaFreg();
Freguesia *CriarFreguesia(char *idfreg, char *nome, char *concelho);
void LoadFreguesias(LFreguesias *L);

//Concelhos------------------------------------------------------------------

Concelho *CriarConcelho(char *idconc, char *nome, char *distrito);
LConcelhos *CriarListaConc();
void LoadConcelhos(LConcelhos *L);

//Distritos------------------------------------------------------------------

LDistritos *CriarListaDist();
Distrito *CriarDistrito(char *iddist, char *nome);
void LoadDistritos(LDistritos *L);

//----------------------------------------------------------------------------
//-----------------------------------END--------------------------------------
//----------------------------------------------------------------------------