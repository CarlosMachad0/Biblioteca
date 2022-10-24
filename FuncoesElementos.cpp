
#include "Funcoes.h"


//--------------------------------------------------------------------------
//------------------------FUNCOES_ELEMENTOS---------------------------------
//--------------------------------------------------------------------------

//Verifica------------------------------------------------------------------

int LerInteiro(const char *msg)
{
	printf("[%s] ", msg);
	int X;
	scanf("%d", &X);
	return X;
}

char *alocar(char *aloc)
{
	char *string;
	string = (char *)malloc(sizeof(char)*(strlen(aloc) + 1));
	strcpy(string, aloc);
	return string;
}

//CriaElemento--------------------------------------------------------------

DATA *criardata()
{
	DATA *data = (DATA *)malloc(sizeof(DATA));
	data->Dia = 0;
	data->Mes = 0;
	data->Ano = 0;
	return data;
}

Pessoa *CriarPessoa(char *id_requisitante, char *Nome, char *freguesia, DATA *data_nasc)
{
	Pessoa *X = (Pessoa *)malloc(sizeof(Pessoa));
	X->data_nasc = data_nasc;
	X->freguesia = freguesia;
	X->id_requisitante = id_requisitante;
	X->Nome = Nome;
	return X;
}

Requisitante *CriarRequisitante(Pessoa *info, DATA *datareq, Livro *L, char *disponibilidade)
{
	Requisitante *X = (Requisitante *)malloc(sizeof(Requisitante));
	X->info = info;
	X->datareq = datareq;
	X->disponibilidade = disponibilidade;
	X->L = L;
	return X;
}

Livro *CriarLivro(char *ISBN, char *titulo, char *area, DATA *ano_pub, int nreq, int estado)
{
	Livro *X = (Livro *)malloc(sizeof(Livro));
	X->ano_pub = ano_pub;
	X->area = area;
	X->estado = 0;
	X->ISBN = ISBN;
	X->nreq = 0;
	X->titulo = titulo;
	return X;
}

//CriaLista------------------------------------------------------------------

ListaPessoas *CriarListaPessoas()
{
	ListaPessoas *X = (ListaPessoas *)malloc(sizeof(ListaPessoas));
	X->inicio = NULL;
	X->nel = 0;
	return X;
}

ListaRequisitante *CriarListaRequisitantes()
{
	ListaRequisitante *X = (ListaRequisitante *)malloc(sizeof(ListaRequisitante));
	X->inicio = NULL;
	X->nel = 0;
	return X;
}

ListaLivros *CriarListaLivros()
{
	ListaLivros *X = (ListaLivros *)malloc(sizeof(ListaLivros));
	X->inicio = NULL;
	X->nel = 0;
	return X;
}

//CriaNOS--------------------------------------------------------------------

NoPessoas *CriarNo(Pessoa *P)
{
	NoPessoas *n = (NoPessoas *)malloc(sizeof(NoPessoas));
	n->info = P;
	n->prox = NULL;
	return n;
}

NoLivros *CriarNo(Livro *L)
{
	NoLivros *n = (NoLivros *)malloc(sizeof(NoLivros));
	n->info = L;
	n->prox = NULL;
	return n;
}

NoRequisitante *CriarNo(Requisitante *R)
{
	NoRequisitante *n = (NoRequisitante *)malloc(sizeof(NoRequisitante));
	n->info = R;
	n->prox = NULL;
	return n;

}

//Mostrar--------------------------------------------------------------------

void MostrarPessoa(Pessoa *X)
{
	printf("PESSOA %s, %s, %d-%d-%d, %s \n", X->id_requisitante, X->Nome, X->data_nasc->Dia, X->data_nasc->Mes, X->data_nasc->Ano, X->freguesia );
}

void MostrarRequisitante(Requisitante *X)
{
	//printf("Requisitante (%s, %s, %s, %s,)\n", X->datareq, X->disponibilidade, X->info, X->L);
}

void MostrarLivro(Livro *X)
{
	printf("Livro (%s, %s, %s, %d-%d-%d, %d, %d)\n", X->ISBN, X->titulo, X->area, X->ano_pub->Dia, X->ano_pub->Mes, X->ano_pub->Ano, X->estado, X->nreq);
}

//Adiciona_À_Lista-----------------------------------------------------------

void PessoaLista(ListaPessoas *l, Pessoa *P) //adicionar pessoa à lista
{
	if (!l) return;
	NoPessoas *n = CriarNo(P);
	if (!l->inicio)
	{
		l->inicio = n;
		return;
	}
	n->prox = l->inicio;
	l->inicio = n;
	return;
}

void LivroLista(ListaLivros *l, Livro *x) //adicionar pessoa à lista
{
	if (!l)return;
	NoLivros *n = CriarNo(x);
	if (!l->inicio)
	{
		l->inicio = n;
		return;
	}
	n->prox = l->inicio;
	l->inicio = n;
	return;
}

void RequisitanteLista(ListaRequisitante *l, Requisitante *R)
{
	if (!l)return;
	NoRequisitante *n = CriarNo(R);
	if (!l->inicio)
	{
		l->inicio = n;
		return;
	}
	n->prox = l->inicio;
	l->inicio = n;
	return;
}

//Destruir-------------------------------------------------------------------

void DestruirPessoa(void *P)
{
	printf("Passei em %s\n", __FUNCTION__);
	Pessoa *X = (Pessoa *)P;
	free(X->Nome);
	free(X->freguesia);
	free(X->id_requisitante);
	free(X->data_nasc);
	free(X);
}

void DestruirRequisitante(void *P)
{
	printf("Passei em %s\n", __FUNCTION__);
	Requisitante *X = (Requisitante *)P;
	free(X->datareq);
	free(X->disponibilidade);
	free(X->info);
	free(X->L);
	free(X);
}

void DestruirLivro(void *P)
{
	printf("Passei em %s\n", __FUNCTION__);
	Livro *X = (Livro *)P;
	//free(X->NOME);
	free(X);
}

//LOAD-----------------------------------------------------------------------

void LoadPessoas(ListaPessoas *L)
{
	if (!L) return;
	char buffer[256], linha[256];
	char *id;
	char *nome;
	DATA data;
	char *localidade;
	Pessoa *P;
	FILE *F = fopen("Requisitantes.txt", "r"); //abre o arquivo para leitura
	while (!feof(F))
	{
		fgets(buffer, 256, F);
		strcpy(linha, buffer);
		char *token = strtok(buffer, "\t");
		id = alocar(token);
		token = strtok(NULL, "\t");
		nome = alocar(token);
		token = strtok(NULL, "\t");
		sscanf(token, "%d-%d-%d", &data.Dia, &data.Mes, &data.Ano); //seleciona scanf
		token = strtok(NULL, "\t");
		localidade = alocar(token);

		bool veridata = VerificaData(data.Dia, data.Mes, data.Ano);
		bool veriID = VerificaIDReq(id);

		if (veriID == false || veridata == false)
		{
			FILE *X = fopen(FICHEIRO_LOGS, "a");
			fprintf(X, "\n%s", linha);
			fclose(X);
		}
		else
		{
			P = CriarPessoa(id, nome, localidade, &data);
			PessoaLista(L, P);
			MostrarPessoa(P);
		}
		/*
		falta verificações com funcoes auxiliares
		*/
	}
	if (feof(F))
		printf("Cheguei ao Fim do ficheiro\n");
	fclose(F);
}

void LoadLivros(ListaLivros *L)
{
	if (!L) return;
	char buffer[256], linha[256];
	char *ISBN;
	char *titulo;
	char *area;
	DATA data;
	int nreq = 0;
	int estado = 0;
	Livro *X;
	FILE *F = fopen("Livro de registo Biblioteca.txt", "r"); //abre o arquivo para leitura
	while(!feof(F))
	{
		fgets(buffer, 256, F);
		char *token = strtok(buffer, "\t");
		token = strtok(NULL, "\t");
		area = alocar(token);
		token = strtok(NULL, "\t");
		token = strtok(NULL, "\t");
		token = strtok(NULL, "\t");
		token = strtok(NULL, "\t");
		token = strtok(NULL, "\t");
		token = strtok(NULL, "\t");
		token = strtok(NULL, "\t");
		token = strtok(NULL, "\t");
		token = strtok(NULL, "\t");
		ISBN = alocar(token);
		token = strtok(NULL, "\t");
		titulo = alocar(token);
		token = strtok(NULL, "\t");
		token = strtok(NULL, "\t");
		sscanf(token, "%d/%d/%d", &data.Dia, &data.Mes, &data.Ano); //seleciona scanf
		if (token == "/0")return;
		
		bool veridata = VerificaData(data.Dia, data.Mes, data.Ano);

		if (veridata == false)
		{
			FILE *X = fopen(FICHEIRO_LOGS, "a");
			fprintf(X, "\n%s", linha);
			fclose(X);
		}
		else
		{
			X = CriarLivro(ISBN, titulo, area, &data, nreq, estado);
			LivroLista(L, X);
			MostrarLivro(X);
		}
		if (feof(F))
			printf("Cheguei ao Fim do ficheiro\n");
	}

	// falta verificar o resto do texto (passar a frente caso nao exista a informacao)

}

//----------------------------------------------------------------------------
//-----------------------------------END--------------------------------------
//----------------------------------------------------------------------------