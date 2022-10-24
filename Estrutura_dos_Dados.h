
#ifndef ESTRUTURA_DOS_DADOS_H_INCLUDED
#define ESTRUTURA_DOS_DADOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
#define FICHEIRO_LOGS "Logs.txt" //defenimos aqui para ser mais facil depois no caso de ser necessario alterar

//----------------------------------------------------------------------------
//-------------------------PARTE_DOS_ELEMENTOS--------------------------------
//----------------------------------------------------------------------------

//Elementos-------------------------------------------------------------------

typedef struct data
{
	int Dia;
	int Mes;
	int Ano;
}DATA;

typedef struct livro
{
	/*
	ISBN - codigo de barras = posicao 11
	Título - Titulo = posicao 12
	Área- departamento = posicao 2
	Ano de publicação - ano catalogacao = posicao 14
	*/

	char *ISBN;
	char *titulo;
	char *area;
	DATA *ano_pub; //vamos considerar o ano catalogacao porque no ficheiro nao havia ano de publicacao
	int nreq; //numero de requisicoes
	int estado;
}Livro;

typedef struct pessoa
{
	char *id_requisitante;
	char *Nome;
	DATA *data_nasc;
	char *freguesia;
}Pessoa;

typedef struct requisitante
{
	Pessoa *info;
	DATA *datareq;
	Livro *L;
	char *disponibilidade;
}Requisitante;

//Elementos_locais------------------------------------------------------------

typedef struct
{
	char *id_distrito;
	char *nome;
}Distrito;

typedef struct
{
	char *id_concelho;
	char *nome;
	char *pt_distrito;
}Concelho;

typedef struct
{
	char *id_freguesia;
	char *nome;
	char *pt_concelho;
}Freguesia;

//----------------------------------------------------------------------------
//-----------------------------PARTE_DOS_NOS----------------------------------
//----------------------------------------------------------------------------

typedef struct nopessoas
{
	Pessoa *info;
	struct nopessoas *prox;
}NoPessoas;

typedef struct norequisitante
{
	Requisitante *info;
	struct norequisitante *prox;
	/*
	:::NAO_USAR_PORQUE_OCUPAM_O_MESMO_ESPACO_QUE_AS_DE_BAIXO_E_FAZEM_SO_UMA_PARTE_DO_QUE_AS_OUTRAS_FAZEM:::
		int id_requisitante;
		int id_livro;
	*/
}NoRequisitante;

typedef struct noLivros
{
	Livro *info;
	struct noLivros *prox;
}NoLivros;

//NOS_Locais------------------------------------------------------------------

typedef struct no_freguesia
{
	Freguesia *INFO;
	struct no_freguesia *PROX;
}NO_Freguesia;

typedef struct no_concelho
{
	Concelho *INFO;
	struct no_concelho *PROX;
}NO_Concelho;

typedef struct no_distrito
{
	Distrito *INFO;
	struct no_distrito *PROX;
}NO_Distrito;

//----------------------------------------------------------------------------
//-----------------------------PARTE_DAS_LISTAS-------------------------------
//----------------------------------------------------------------------------

typedef struct
{
	NoPessoas *inicio;
	int nel;
}ListaPessoas;

typedef struct
{
	NoRequisitante *inicio;
	int nel;
}ListaRequisitante;

typedef struct
{
	NoLivros *inicio;
	int nel;
}ListaLivros;

//Listas_Locais---------------------------------------------------------------

typedef struct //lista_freguesias
{
	NO_Freguesia *inicio;
	int nel;
}LFreguesias;

typedef struct //lista_concelhos
{
	NO_Concelho *inicio;
	int nel;
}LConcelhos;

typedef struct //lista_distritos
{
	NO_Distrito *inicio;
	int nel;
}LDistritos;

//----------------------------------------------------------------------------
//-----------------------------------END--------------------------------------
//----------------------------------------------------------------------------

#endif // ESTRUTURA_DOS_DADOS_H_INCLUDED