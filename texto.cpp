
#include "Estrutura_dos_Dados.h"
#include "Funcoes.h"


//----------------------------------------------------------------------------

bool VerificaIDReq(const char* cod)
{
	int tam = strlen(cod);
	if (tam != 9)return false;
//	printf("TAM=%d\n", tam);
	int soma = 0;
	for (int i = 0; i < tam; i++)
		soma += cod[i] - '0';
	//printf("SOMA=%d\n", soma);
	printf("ID Valido\n");
	return soma % 10 == 0;
}

//----------------------------------------------------------------------------

bool VerificaData(int dia, int mes, int ano) 
{
	int x = ano % 4;
	int y = ano % 400;

	if (dia < 1 || dia>31 || mes < 1 || mes>12 || ano <= 1000 || ano >= 2500)
	{
		printf("Data invalida!\n");
		return false;
	}
	else
	{
		if (mes == 2)
		{
			if (x == 0 && y != 0)
			{
				if (dia > 29)
				{
					printf("Data invalida!\n");
					return false;
				}
				else
				{
					printf("Data valida\n");
					return true;
				}
			}
			else
			{
				if (dia > 28)
				{
					printf("Data invalida!\n");
					return false;
				}
				else
				{
					printf("Data valida\n");
					return true;
				}
			}
		}
		if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
		{
			if (dia > 30)
			{
				printf("Data invalida!\n");
				return false;
			}
			else 
			{
				printf("Data valida\n");
				return true;
			}
		}
		if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
		{
			printf("Data valida\n");
			return true;
		}
	}
	return true;
}

//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
//-----------------------------------END--------------------------------------
//----------------------------------------------------------------------------
