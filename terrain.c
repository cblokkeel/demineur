#include "main.h"
extern char terrain[];
extern int how_many_discovered;

int initialiser_terrain(void)
{

	int size = NB_LIGNES * NB_COLONNES;
	for (int i = 0; i < size; i++)
	{
		terrain[i] = '?';
	}

	return 0;

}


char contenu_de_terrain(int ligne, int colonne)
{

	int position = get_position(ligne, colonne);

	return terrain[position];

}


int place_sur_le_terrain(int ligne, int colonne, char car)
{

	int position = get_position(ligne, colonne);

	terrain[position] = car;

	return 0;

}


int affiche_terrain(void)
{

	int size = NB_LIGNES * NB_COLONNES;

	print_letters();
	print_line();
	print_line();

	for (int i = 0; i < size; i++)
	{	

		if (i % NB_COLONNES == 0)
		{
			if (i == 0)
			{
				printf(" %i |", i + 1);
			}
			else
			{
				printf("\n");
				print_line();
				printf(" %i |", i / NB_LIGNES + 1);				
			}

		}

		// vérifie si on est au bout de la ligne, si oui on affiche | i | sinon juste | i
		(i + 1) % NB_COLONNES == 0 ? printf("| %c |", terrain[i]) : printf("| %c ", terrain[i]);

	}

	printf("\n");
	print_line();
	printf("\n");

	return 0;

}

int revelation_du_terrain(int ligne, int colonne)
{
	int how_many_mine;
	char char_how_many_mine;
	int position = get_position(ligne, colonne);

	how_many_mine = combien_de_mine_autour(ligne, colonne);
	char_how_many_mine = how_many_mine + '0';
	terrain[position] = char_how_many_mine;
	how_many_discovered++;

	if (how_many_mine == 0)
	{
		
	}

	affiche_terrain();

	return 0;

}