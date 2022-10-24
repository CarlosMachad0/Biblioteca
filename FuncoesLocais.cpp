
#include "Funcoes.h"


//----------------------------------------------------------------------------
//----------------------------FUNCOES_LOCAIS----------------------------------
//----------------------------------------------------------------------------

//CriaElemento----------------------------------------------------------------

Freguesia *CriarFreguesia(char *idfreg, char *nome, char *concelho)
{
	Freguesia *X = (Freguesia *)malloc(sizeof(Freguesia));
	X->id_freguesia = idfreg;
	X->nome = nome;
	X->pt_concelho = concelho;
	return X;
}

Concelho *CriarConcelho(char *idconc, char *nome, char *distrito)
{
	Concelho *X = (Concelho *)malloc(sizeof(Concelho));
	X->id_concelho = idconc;
	X->nome = nome;
	X->pt_distrito = distrito;
	return X;
}

Distrito *CriarDistrito(char *id_distrito, char *nome)
{
	Distrito *X = (Distrito *)malloc(sizeof(Distrito));
	X->id_distrito = id_distrito;
	X->nome = nome;
	return X;
}

//CriaLista-------------------------------------------------------------------

LFreguesias *CriarListaFreg()
{
	LFreguesias *X = (LFreguesias *)malloc(sizeof(LFreguesias));
	X->inicio = NULL;
	X->nel = 0;
	return X;
}

LConcelhos *CriarListaConc()
{
	LConcelhos *X = (LConcelhos *)malloc(sizeof(LConcelhos));
	X->inicio = NULL;
	X->nel = 0;
	return X;
}

LDistritos *CriarListaDist()
{
	LDistritos *X = (LDistritos *)malloc(sizeof(LDistritos));
	X->inicio = NULL;
	X->nel = 0;
	return X;
}

//CriaNOS---------------------------------------------------------------------

NO_Freguesia *CriarNo(Freguesia *F)
{
	NO_Freguesia *n = (NO_Freguesia *)malloc(sizeof(NO_Freguesia));
	n->INFO = F;
	n->PROX = NULL;
	return n;
}

NO_Concelho *CriarNo(Concelho *C)
{
	NO_Concelho *n = (NO_Concelho *)malloc(sizeof(NO_Concelho));
	n->INFO = C;
	n->PROX = NULL;
	return n;
}

NO_Distrito *CriarNo(Distrito *D)
{
	NO_Distrito *n = (NO_Distrito *)malloc(sizeof(NO_Distrito));
	n->INFO = D;
	n->PROX = NULL;
	return n;
}

//Mostrar---------------------------------------------------------------------

void MostrarFreguesia(Freguesia *X)
{
	printf("Freguesia %s %s %s \n", X->id_freguesia, X->nome, X->pt_concelho) ;
}

void MostrarConcelho(Concelho *X)
{
	printf("Concelho %s %s %s \n", X->id_concelho, X->nome, X->pt_distrito);
}

void MostrarDistrito(Distrito *X)
{
	printf("Distrito %s %s \n", X->id_distrito, X->nome);
}

//Adiciona_À_Lista------------------------------------------------------------

void FreguesiaLista(LFreguesias *l, Freguesia *F) //adicionar Freguesia à lista
{
	if (!l) return;
	NO_Freguesia *n = CriarNo(F);
	if (!l->inicio)
	{
		l->inicio = n;
		return;
	}
	n->PROX = l->inicio;
	l->inicio = n;
	return;
}

void ConcelhoLista(LConcelhos*l, Concelho *F) //adicionar Concelho à lista
{
	if (!l) return;
	NO_Concelho *n = CriarNo(F);
	if (!l->inicio)
	{
		l->inicio = n;
		return;
	}
	n->PROX = l->inicio;
	l->inicio = n;
	return;
}

void DistritoLista(LDistritos *l,Distrito *D) //adicionar Distrito à lista
{
	if (!l) return;
	NO_Distrito *n = CriarNo(D);
	if (!l->inicio)
	{
		l->inicio = n;
		return;
	}
	n->PROX = l->inicio;
	l->inicio = n;
	return;
}

//LOAD------------------------------------------------------------------------

void LoadDistritos(LDistritos *L)
{
	if (!L);
	char buffer[256];
	char *id;
	char *nome;
	Distrito *X;
	FILE *F = fopen("distritos.txt", "r");
	while (!feof(F))
	{
		fgets(buffer, 256, F);
		char *token = strtok(buffer, "\t");
		id = alocar(token);
		token = strtok(NULL, "\t");
		nome = alocar(token);

		X = CriarDistrito(id, nome);
		DistritoLista(L, X);
		MostrarDistrito(X);
		if (feof(F))
			printf("Cheguei ao Fim do ficheiro\n");
	}
}

void LoadConcelhos(LConcelhos *L)
{
	if (!L);
	char buffer[256];
	char *id;
	char *nome;
	char *distrito = 0;
	Concelho *X;

	char *IdDistrito;
	LDistritos *D;

	FILE *F = fopen("distritos.txt", "r");
	while (!feof(F))
	{
		fgets(buffer, 256, F);
		char *token = strtok(buffer, "\t");
		id = alocar(token);
		token = strtok(NULL, "\t");
		nome = alocar(token);


		D->inicio->INFO->id_distrito = IdDistrito;
		

		X = CriarConcelho(id, nome, distrito);
		ConcelhoLista(L, X);
		MostrarConcelho(X);
		if (feof(F))
			printf("Cheguei ao Fim do ficheiro\n");
	}
}

void LoadFreguesias(LFreguesias *L)
{
	if (!L);
	char buffer[256];
	char *id;
	char *nome;
	char *concelho = 0;
	Freguesia *X;
	FILE *F = fopen("freguesias.txt", "r");
	while (!feof(F))
	{
		fgets(buffer, 256, F);
		char *token = strtok(buffer, "\t");
		id = alocar(token);
		token = strtok(NULL, "\t");
		nome = alocar(token);
		
		X = CriarFreguesia(id, nome, concelho);
		FreguesiaLista(L, X);
		MostrarFreguesia(X);
		if (feof(F))
			printf("Cheguei ao Fim do ficheiro\n");
	}
}

//----------------------------------------------------------------------------
//-----------------------------------END--------------------------------------
//----------------------------------------------------------------------------