#include "main.h"

char entree[10];

int demande_valeur(void)
{

	printf("Valeur: ");
	scanf("%s", entree);

}

int numero_colonne(void)
{

	int i = entree[0] - 96;
	return i;

}

int numero_ligne(void)
{

	int i = entree[1] - 48;
	return i;

}

void ask_user(void)
{

	int is_mine;

	while (1)
	{

		demande_valeur();

		is_mine  = est_une_mine(numero_ligne(), numero_colonne());

		printf("%i\n", is_mine);
	
	}
	 
}