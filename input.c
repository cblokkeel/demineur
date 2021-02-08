#include "main.h"
extern int mines[];
extern int how_many_discovered;

char entree[10];

int demande_valeur(void)
{

	printf("Valeur: ");
	scanf("%s", entree);

	return 0;

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
	int is_finished;

	while (1)
	{

		demande_valeur();
		is_mine  = est_une_mine(numero_ligne(), numero_colonne());
		if (is_mine == 1) 
		{
			printf("Vous avez perdu !\n");
			break;		
		} 
		else 
		{
			revelation_du_terrain(numero_ligne(), numero_colonne());
		}

		is_finished = est_ce_fini();

		if (is_finished == 1)
		{
			printf("Bravo\n");
			break;
		}

	}
	 
}

int est_ce_fini(void)
{

	return how_many_discovered == NB_LIGNES * NB_COLONNES - NB_MINES ? 1 : 0;

}