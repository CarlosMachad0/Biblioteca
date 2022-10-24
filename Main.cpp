
#include "Funcoes.h"

//---------------------------------------------------------------------------
//-----------------------------------MAIN------------------------------------
//---------------------------------------------------------------------------

int Menu()
{
	printf("1- Lista Pessoas \n");
	printf("2- Lista Livros \n");
	printf("3- Lista Freguesias \n");
	printf("4- Lista Concelhos \n");
	printf("5- Lista Distritos \n");
	printf("6- Sair \n");

	int N = LerInteiro("Opcao ?");
	return N;
}

int main()
{
	system("cls");
	printf("INICIO: PRatico \n\n");
	int OP = 0;
	do
	{
		system("cls");
		OP = Menu();
		switch (OP)
		{

			case 1:
			{
				system("cls");
				ListaPessoas *L = CriarListaPessoas();
				LoadPessoas(L);
			}; break;

			case 2:
			{
				system("cls");
				ListaLivros *X = CriarListaLivros();
				LoadLivros(X);
			}; break;

			case 3:
			{
				system("cls");
				LFreguesias * F = CriarListaFreg();
				LoadFreguesias(F);			
			}; break;

			case 4:
			{
				system("cls");
				LConcelhos *C = CriarListaConc();
				LoadConcelhos(C);
			}; break;

			case 5:
			{
				system("cls");
				LDistritos *L = CriarListaDist();
				LoadDistritos(L);
			}; break;

			case 6: return OP; break;

			
		}
		system("pause");

	} while (OP != 0);

	return 1;
}

//----------------------------------------------------------------------------
//-----------------------------------END--------------------------------------
//----------------------------------------------------------------------------