#include "main.h"
extern int mines[];

int est_une_mine(int ligne, int colonne)
{

	int position = get_position(ligne, colonne);

	return mines[position];

}


int placer_mine(int ligne, int colonne)
{

	int position = get_position(ligne, colonne);
	mines[position] = 1;

	return 0;

}


int affiche_mines(void)
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
				printf(" %i |", i);
			}
			else
			{
				printf("\n");
				print_line();
				printf(" %i |", i / 4);				
			}

		}

		// vérifie si on est au bout de la ligne, si oui on affiche | i | sinon juste | i
		(i + 1) % NB_COLONNES == 0 ? printf("| %i |", mines[i]) : printf("| %i ", mines[i]);


	}
	printf("\n");
	print_line();
	printf("\n");

	return 0;

}


void print_line(void)
{

	int size = NB_COLONNES * NB_COLONNES + 5;
	char line[size];

	for (int i = 0; i < 4; i++)
	{
		line[i] = i == 3 ? '+' : '-';
	}

	for (int i = 4; i < size; i++)
	{
		line[i] = i % NB_COLONNES == 0 ? '+' : '-';
	}

	printf("%s\n", line);

}


void print_letters(void)
{	

	char c;

	printf("   |");
	for (int i = 0; i < NB_COLONNES; i++)
	{
		c = i + 97;
		printf("| %c ", c);
	}
	printf("|\n");

}


int combien_de_mine_autour(int ligne, int colonne)
{

	int position = get_position();



}


int get_position(int ligne, int colonne)
{

	/* (ligne - 1) * NB_COLONNES :
			retourne le nombre de case présent 
			sur les lignes précedentes
		+ (colonne - 1) :
			ajoute les cases restantes sur la ligne actuelle
			(on retire 1 car on commence à 0 donc colonne 4 = colonne[3])
	*/

	return (ligne - 1) * NB_COLONNES + (colonne - 1);

}