#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Estrutura_dos_Dados.h"
/*
//-------------------------------------------------------------
//-------------------------EXTERNS-----------------------------
//-------------------------------------------------------------

extern char *LerStringFicheiro(FILE *F);
extern int LerInteiro(const char *msg);
extern char *LerString(const char *texto);

//-------------------------------------------------------------
//-----------------------Criar Listas--------------------------
//-------------------------------------------------------------

ListaRequisitantes *CriarListaRequisitantes()
{
	ListaRequisitantes *R = (ListaRequisitantes *)malloc(sizeof(ListaRequisitantes));
	R->inicio = NULL;
	R->nel = 0;
	return R;
}

//----------------------------------------------------------------------------

ListaLivros *CriarListaLivros()
{
	ListaLivros *L = (ListaLivros *)malloc(sizeof(ListaLivros));
	L->inicio = NULL;
	L->nel = 0;
	return L;
}

//----------------------------------------------------------------------------

LFreguesias *CriarListaFreguesias()
{
	LFreguesias *F = (LFreguesias *)malloc(sizeof(LFreguesias));
	F->inicio = NULL;
	F->nel = 0;
	return F;
}

//----------------------------------------------------------------------------

LConcelhos *CriarListaCconcelhos()
{
	LConcelhos *C = (LConcelhos *)malloc(sizeof(LConcelhos));
	C->inicio = NULL;
	C->nel = 0;
	return C;
}

//----------------------------------------------------------------------------

LDistritos *CriarListaDistritos()
{
	LDistritos *D = (LDistritos *)malloc(sizeof(LDistritos));
	D->inicio = NULL;
	D->nel = 0;
	return D;
}

//-------------------------------------------------------------
//------------------Adicionar A Lista--------------------------
//-------------------------------------------------------------

void AdicionaRequisitante(ListaRequisitantes *L, Requisitante *R)
{
	if (!L) return;
	NoRequisitantes *X = (NoRequisitantes *)malloc(sizeof(NoRequisitantes));
	X->info = R;
	X->prox = L->inicio;
	L->inicio = X;
	L->nel++;
}

//----------------------------------------------------------------------------

void AdicionaFreguesia(LFreguesias *L, Freguesia *F)
{
	if (!L) return;
	NO_Freguesia *X = (NO_Freguesia *)malloc(sizeof(NO_Freguesia));
	X->INFO = F;
	X->PROX= L->inicio;
	L->inicio = X;
	L->nel++;
}

//----------------------------------------------------------------------------

void AdicionaConcelho(LConcelhos *L, Concelho *C)
{
	if (!L) return;
	NO_Concelho *X = (NO_Concelho *)malloc(sizeof(NO_Concelho));
	X->INFO = C;
	X->PROX = L->inicio;
	L->inicio = X;
	L->nel++;
}


//----------------------------------------------------------------------------

void AdicionaDistrito(LDistritos *L, Distrito *D)
{
	if (!L) return;
	NO_Distrito *X = (NO_Distrito *)malloc(sizeof(NO_Distrito));
	X->INFO = D;
	X->PROX = L->inicio;
	L->inicio = X;
	L->nel++;
}

//----------------------------------------------------------------------------



//-------------------------------------------------------------
//------------------Destruir Elemento--------------------------
//-------------------------------------------------------------

void DestruirLivro(Livro *xpto)
{
	free(xpto);
}

//----------------------------------------------------------------------------

void DestruirRequisitante(Requisitante *xpto)
{
	free(xpto);
}

//----------------------------------------------------------------------------

void DestruirFreguesia(Freguesia *xpto)
{
	free(xpto);
}

//----------------------------------------------------------------------------

void DestruirConcelho(Concelho *xpto)
{
	free(xpto);
}

//----------------------------------------------------------------------------

void DestruirDistrito(Distrito *xpto)
{
	free(xpto);
}

//----------------------------------------------------------------------------

*/